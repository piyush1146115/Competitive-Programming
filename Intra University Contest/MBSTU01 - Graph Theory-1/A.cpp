#include<bits/stdc++.h>
using namespace std;

int r, c;
string s[105];
bool vis[105][105];
int dx[] = {0, +1, -1, -1, +1, -1, 0, +1};
int dy[] = {+1, +1, +1, 0, 0, -1, -1, -1};
void dfs(int x, int y)
{
    vis[x][y] = 1;
    if(s[x][y] == '*')
        return;

    for(int i = 0; i < 8; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(xx >= 0 && yy >= 0 && xx < r && yy < c && s[xx][yy] == '@' && vis[xx][yy] == 0){
            dfs(xx, yy);
        }
    }
}

int main()
{

    while(scanf("%d %d", &r, &c) == 2){
        if(r == 0 && c == 0)
            break;

            for(int i = 0; i < r; i++)
                cin >> s[i];

            memset(vis, 0, sizeof(vis));
            int cnt = 0;
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    if(vis[i][j] == 0 && s[i][j] == '@'){
                    //cout << i << " " << j << endl;
                        cnt++;
                        dfs(i, j);
                    }
                }
            }
        printf("%d\n",cnt);
    }
}
