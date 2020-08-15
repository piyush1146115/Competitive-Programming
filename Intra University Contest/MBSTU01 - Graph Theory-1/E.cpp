#include<bits/stdc++.h>
using namespace std;
string s[205];
int flag = 0;
bool vis[205][205];
int dx[] = {-1, -1, 0, 0, +1, +1};
int dy[] = {-1, 0, -1, +1, 0, +1};
int n;

void dfs(int x, int y)
{
    vis[x][y] = 1;
    if(y == (n -1)){
        flag = 1;
    }
    if(s[x][y] == 'b')
        return;

    for(int i = 0; i < 6; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(xx >=0 && yy >= 0 && xx < n && yy < n &&vis[xx][yy] == 0 && s[xx][yy] == 'w'){
            dfs(xx, yy);
        }
    }
}

void dfs2(int x, int y)
{
    vis[x][y] = 1;
    if(x == (n -1)){
        flag = 2;
    }
    if(s[x][y] == 'w')
        return;

    for(int i = 0; i < 6 ; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(xx >=0 && yy >= 0 && xx < n && yy < n &&vis[xx][yy] == 0 && s[xx][yy] == 'b'){
            dfs2(xx, yy);
        }
    }
}


int main()
{
    int tc = 0;
    while(scanf("%d", &n) == 1){
        if(n == 0)
            break;

        flag = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }

        for(int i = 0; i < n; i++){
            if(s[i][0] == 'w' && vis[i][0] == 0){
                dfs(i, 0);
            }
        }


        for(int i = 0; i < n; i++){
            if(s[0][i] == 'b' && vis[0][i] == 0){
                dfs2(0,i);
            }
        }

        printf("%d ",++tc);

        if(flag == 1){
            printf("W\n");
        }
        if(flag == 2){
            printf("B\n");
        }
    }
}
