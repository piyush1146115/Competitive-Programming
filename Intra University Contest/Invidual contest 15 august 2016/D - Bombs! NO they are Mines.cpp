#include<bits/stdc++.h>
using namespace std;
#define MX 10000000
bool mat[1005][1005], vis[1005][1005];
int  cost[1005][1005];
int row, col, dis[3] , src[3], sum, res = MX;
int fx[] = {+1, -1, +0, +0};
int fy[] = {+0, +0, +1, -1};

bool valid(int x, int y)
{
    if(x < 0 || y < 0 || x >= row || y >= col || vis[x][y] == 1 || mat[x][y] == 1 )
        return false;
    else
        return true;
}

void reset()
{

    for(int i = 0; i <= row; i ++){
        for(int j = 0; j <= col ; j++){
            cost[i][j] = 0;
            vis[i][j] = 0;
            mat[i][j] = 0;
        }
    }
}

int bfs(int sx, int sy)
{
    queue < pair <int, int> > q;

    q.push({sx, sy});
    cost[sx][sy] = 0;
    vis[sx][sy] = 1;

    if(sx == dis[0] && sy == dis[1])
        return 0;

    while(!q.empty())
    {
        pair <int, int> u;

        u = q.front();
        q.pop();
        int ux  = u.first;
        int uy = u.second;

        for(int i = 0; i < 4; i++){
            int tx = ux + fx[i];
            int ty = uy + fy[i];

            if(valid(tx, ty))
            {
                cost[tx][ty] = cost[ux][uy] + 1;
                if(tx == dis[0] && ty == dis[1])
                    return cost[tx][ty];

                q.push({tx, ty});
                vis[tx][ty] = 1;
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int i, j, k , n, m, l , x, y;

    while(scanf("%d %d", &row, &col) == 2){

        if(row == 0 && col == 0)
            break;

        reset();

        scanf("%d", &n);

        for(i = 0; i < n; i++){
            scanf("%d %d", &x, &m);
            for(j = 0; j < m; j++){
                scanf("%d", &y);
                mat[x][y] = 1;
            }
        }
        scanf("%d %d %d %d", &src[0], &src[1], &dis[0], &dis[1]);

       sum =  bfs(src[0], src[1]);

       cout << sum << endl;
    }
    return 0;
}
