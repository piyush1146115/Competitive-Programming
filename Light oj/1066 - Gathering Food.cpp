#include<bits/stdc++.h>
using namespace std;
#define mxx 13
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int, int>

int fx[] = { 0, 1, -1, 0};
int fy[] = { 1, 0, 0, -1};

int n;
int cnt, c;
int vis[mxx][mxx], dis[mxx][mxx];
char ara[100];
string s[mxx];
int posx,  posy;

bool valid(int x, int y) {
    if (x >= 0 && y >= 0 && x < n && y < n && vis[x][y] == 0 && s[x][y] != '#') {
        return true;
    } else
        return false;
}


int bfs(int stx, int sty) {

    dis[stx][sty] = 0;
    vis[stx][sty] = 1;

  

    queue < pair<int, int> > q;
    q.push(mp(stx, sty));

    while (!q.empty()) {
        pii p = q.front();
        q.pop();

        int x = p.ff;
        int y = p.ss;

        vis[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            int xx = x + fx[i];
            int yy = y + fy[i];

            if (valid(xx, yy)) {
                dis[xx][yy] = dis[x][y] + 1;

                if (isalpha(s[xx][yy])) {

                    if (s[xx][yy] == ara[c]) {
                        posx = xx, posy = yy;
                        return dis[xx][yy];
                    } else if (s[xx][yy] < ara[c]) {
                        q.push(mp(xx, yy));
                    }
                } else {
                    q.push(mp(xx, yy));
                    //dis[xx][yy] = dis[x][y] + 1;
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
        scanf("%d", &n);
        // memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));

        for (int i = 0; i < n; i++)
            cin >> s[i];

       
        cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isalpha(s[i][j])) {
                    ara[cnt++] = s[i][j];
                    if (s[i][j] == 'A') {
                        posx = i, posy = j;
                    }
                }
            }
        }

        sort(ara, ara + cnt);
        int ans = 0;

        for (c = 1; c < cnt; c++) {
            
            memset(vis, 0, sizeof(vis));
			int res = bfs(posx, posy);
			if (res == -1){
                ans = -1;
                break;
			}
			ans += res;
        }

        if (ans == -1) {
            printf("Case %d: Impossible\n", tc);
        } else {
            printf("Case %d: %d\n", tc, ans);
        }
    }
}

/*
 *
4
.ID#
GA..
H#E.
FC.B
*/
