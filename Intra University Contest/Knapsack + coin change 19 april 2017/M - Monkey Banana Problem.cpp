#include<bits/stdc++.h>
using namespace std;
int n;
int mat[205][105];
int dp[205][105];

int dfs(int x, int y)
{
    if(x < 0 || y < 0 || y >= n)
        return 0;

    if(dp[x][y] != - 1)
        return dp[x][y];

    int p1 = 0, p2 = 0;

    if(x < n - 1)
    {
        p1 = mat[x][y] + dfs(x + 1, y);
        p2 = mat[x][y] + dfs(x + 1, y + 1);
    }
    else
    {
        if(x - n != n - y)
            p1 = mat[x][y] + dfs(x + 1, y);

        p2 = mat[x][y] + dfs(x + 1, y - 1);
    }
    dp[x][y] = max(p1, p2);

    return dp[x][y];
}

int main()
{
    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {
        scanf("%d", &n);
        memset(mat, 0, sizeof(mat));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= i; j++)
                scanf("%d", &mat[i][j]);
        }
        int k = 0;
        for(int i = n - 2 ; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                scanf("%d",&mat[n + k][j]);
            }
            k++;
        }


        memset(dp, -1, sizeof(dp));
        int res = dfs(0, 0);

        printf("Case %d: %d\n",tc, res);
    }
    return 0;
}
