#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second

int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {-1, 0, -1, 1, 0, 1};
int row, col;
char grid[205][205];
int vis[205][205];

map<pii, int> dis;

bool valid(int x, int y)
{
    if(x < row && y < col && x >= 0 && y >= 0 && vis[x][y] == 0)
        return true;

    return false;
}

void bfs(int x, int y)
{
    queue<pii> q;

    pii p = mp(x, y);
    vis[x][y] = 1;
    q.push(p);
    dis[p] = 0;

    while(!q.empty()) {
        pii f = q.front();
        q.pop();

        for(int i = 0; i <= 5; i++)
        {
            int xx = f.ff + dx[i];
            int yy = f.ss + dy[i];

            if(valid(xx, yy) && grid[xx][yy] == 'b') {
                pii t = mp(xx, yy);
                vis[xx][yy] = 1;
                dis[t] = dis[f] + 1;
                q.push(t);
            }
        }
    }
}


void bfs2(int x, int y)
{
    queue<pii> q;

    pii p = mp(x, y);
    vis[x][y] = 1;
    q.push(p);
    dis[p] = 0;

    while(!q.empty()) {
        pii f = q.front();
        q.pop();

        for(int i = 0; i <= 5; i++)
        {
            int xx = f.ff + dx[i];
            int yy = f.ss + dy[i];

            if(valid(xx, yy) && grid[xx][yy] == 'w') {
                pii t = mp(xx, yy);
                vis[xx][yy] = 1;
                dis[t] = dis[f] + 1;
                //cout << dis[t] << endl;
                q.push(t);
            }
        }
    }
}

int main()
{
    int cas = 0;

    while(scanf("%d" ,&row) == 1) {
        if(row == 0)
            break;

        col = row;
        for(int i = 0; i < row; i++)
            scanf("%s", grid[i]);

        for(int i = 0; i < row; i++)
            if(grid[0][i] == 'b' && vis[0][i] == 0)
                bfs(0, i);

        for(int i = 0; i < row; i++)
            if(grid[i][0] == 'w' && vis[i][0] == 0)
                bfs2(i, 0);

        int w = 1000000, b = 1000000;

        for(int i = 0; i < row; i++)
            if(grid[row - 1][i] == 'b' && vis[row - 1][i] == 1)
            {
                pii t = mp(row -1, i);
                  //cout << dis[t] << endl;
                b = min(dis[t], b);
            }

        for(int i = 0; i < row; i++)
            if(grid[i][row - 1] == 'w' && vis[i][row - 1] == 1)
            {
                pii t = mp(i, row - 1);
          
                w = min(dis[t], w);
            }

        //cout << b << " " << w << endl;

        
        printf("%d ", ++cas);
        if(b < w)
        printf("B\n");
        else
        printf("W\n");
        
        dis.clear();
        memset(vis, 0, sizeof(vis));
    }
}
