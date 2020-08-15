#include<bits/stdc++.h>
using namespace std;
#define mxx 205

struct st {
    int x,  y, cost;
};

int dx[] = { 0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int dis[mxx][mxx], vis[mxx][mxx];
int row, col;

string s[mxx];

bool valid(int x, int y, int cost) {

    if (x >= 0 && y >= 0 &&  x < row && y < col && dis[x][y] > cost && vis[x][y] == 0 && s[x][y] != '#') {
        return true;
    }
    return false;
}

void bfs(int x, int y) {
    dis[x][y] = 0;
    st p;
    p.x = x;
    p.y = y;
    p.cost = 0;
    queue<st> q;
    q.push(p);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = p.x + dx[i];
            int yy = p.y + dy[i];
            if (valid(xx, yy, p.cost + 1)) {
                st pp;
                pp.x = xx;
                pp.y = yy;
                pp.cost = p.cost + 1;
                dis[xx][yy] = pp.cost;
                q.push(pp);
            }
        }
    }
}

int bfs2(int x, int y) {
	
    if (x == 0 || x == row - 1) {
        return  1;
    }
    if (y == 0 || y == col - 1) {
        return 1;
    }
    
    vis[x][y] = 1;
    st p;
    p.x = x;
    p.y = y;
    p.cost = 0;
    queue<st> q;
    q.push(p);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = p.x + dx[i];
            int yy = p.y + dy[i];
            if (valid(xx, yy, p.cost + 1)) {
                st pp;
                pp.x = xx;
                pp.y = yy;
                pp.cost = p.cost + 1;
                vis[xx][yy] = 1;
                
                q.push(pp);
                if (xx == 0 || xx == row - 1) {
                    return pp.cost + 1;
                }
                if (yy == 0 || yy == col -1 ) {
                    return pp.cost + 1;
                }
            }
        }
    }
    
    return -1;
}


int main() {
    int test;
    scanf("%d", &test);

    for (int tc = 1; tc <= test; tc++) {
        scanf("%d %d", &row, &col);


        for (int i = 0; i <= 200; i++) {
            for (int j = 0; j <= 200; j++) {
                vis[i][j] = 0;
                dis[i][j] = 1 << 28;
            }
        }

        for (int i = 0; i < row; i++)
            cin >> s[i];

        int posx, posy;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (s[i][j] == 'F') {
                    bfs(i, j);
                }
                if (s[i][j] == 'J') {
                    posx = i;
                    posy = j;
                }
            }
        }

        int ans = bfs2(posx, posy);
        if(ans == -1)
        printf("Case %d: IMPOSSIBLE\n",tc);
        else
        printf("Case %d: %d\n",tc, ans);
        
    }
}
