#include<bits/stdc++.h>
using namespace std;

int r, c, cnt;
string s[25];
bool vis[25][25];
int dx[] = {0,  0, -1, +1};
int dy[] = {+1,  -1, 0, 0};

void dfs(int x, int y)
{
    cnt++;
    vis[x][y] = 1;
    if(s[x][y] == '#')
        return;

    for(int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(xx >= 0 && yy >= 0 && xx < r && yy < c && s[xx][yy] != '#' && vis[xx][yy] == 0)
        {
            dfs(xx, yy);
        }
    }
}

int main()
{

    int test;
    scanf("%d",&test);

    for(int tc =1 ; tc <= test; tc++)
    {
        cnt = 0;
        scanf("%d %d", &c, &r);

        for(int i = 0; i < r; i++)
            cin >> s[i];

        memset(vis, 0, sizeof(vis));

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(vis[i][j] == 0 && s[i][j] == '@')
                {
                    //cout << i << " " << j << endl;
                    dfs(i, j);
                }
            }
        }
        printf("Case %d: %d\n",tc, cnt);
    }
}

