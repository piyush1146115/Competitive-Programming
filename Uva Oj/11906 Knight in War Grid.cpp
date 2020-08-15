#include<bits/stdc++.h>
using namespace std;

int N, M,row, col, even, odd;

int dx[10];
int dy[10] ;
bool vis[105][105], water[105][105], vis2[105][105];

bool valid(int x, int y)
{
    if(x >= row || y >= col || x < 0 || y < 0 || water[x][y] == 1 || vis[x][y] == 1)
        return false;

    return true;
}

bool valid2(int x, int y)
{
    if(x >= row || y >= col || x < 0 || y < 0 || vis2[x][y] == 1 || water[x][y] == 1)
        return false;

    return true;
}


void dfs(int x, int y)
{

    vis[x][y] = 1;

    int cnt = 0;

    for(int i = 0; i < 8; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(valid2(xx, yy)){
            cnt++;
            vis2[xx][yy] = 1;
		}
    }

    memset(vis2, 0, sizeof(vis2));

    if(cnt % 2 == 0)
        even++;
    else
        odd++;

    for(int i = 0; i < 8; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(valid(xx, yy))
            dfs(xx, yy);
    }
}


int main()
{
    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++) {
        scanf("%d %d %d %d",&row, &col, &N, &M);

        memset(vis, 0, sizeof(vis));
        memset(water, 0, sizeof(water));
        int w;
        //= {N, N, -N, -N};
        //= {M, -M, M, -M};

        dx[0] = N;
        dx[1] = M;
        dx[2] = -N;
        dx[3] = -M;
        dx[4] = -N;
        dx[5] =  M;
        dx[6] = N;
        dx[7] = -M;

        dy[0] =  M;
        dy[1] =  N;
        dy[2] =  -M;
        dy[3] = -N;
        dy[4] =  M;
        dy[5] = -N;
        dy[6] = -M;
        dy[7] = N;


        scanf("%d",&w);

        for(int i = 0; i < w; i++) {
            int x, y;
            scanf("%d %d",&x, &y);
            water[x][y] = 1;
        }

        odd = even = 0;
        dfs(0, 0);
//        cout << even << " " << odd << endl;
	printf("Case %d: %d %d\n",tc,even, odd);
    }
    return 0;
}
