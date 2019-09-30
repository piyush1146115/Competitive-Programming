#include<bits/stdc++.h>
using namespace std;
#define mxx 505
int grid[mxx][mxx];
int dp[mxx][mxx];

struct point
{
    int x, y;
} p[1005];
int ara[1005];
int dx[] = {+1, -1, -1, -2, -2, -3};
int dy[] = {-2, -2, -3, +1, -1, -1};

int fun(int x, int y)
{
    if(x == 0 && (y == 0 || y == 1))
        return 0;
    if(x == 1 && (y == 0 || y == 1))
        return 0;

    if(dp[x][y] != -1)
        return dp[x][y];
    set<int> Set;

    for(int i = 0; i < 6; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx >= 0 && yy >= 0)
            Set.insert(fun(xx, yy));
    }
    int mex = 0;

    while(Set.find(mex) != Set.end())
        mex++;

    dp[x][y] = mex;
    return mex;
}

int main()
{
    int test;
    scanf("%d", &test);
    memset(dp, -1, sizeof(dp));
    for(int tc = 1; tc <= test; tc++)
    {
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &p[i].x, &p[i].y);
        }

        for(int i = 0; i < n; i++)
        {
            ara[i] = fun(p[i].x, p[i].y);
        }
        int ans = 0;

        for(int i = 0; i < n;i++)
            ans ^= ara[i];

        if(ans != 0)
            printf("Case %d: Alice\n",tc);
        else
            printf("Case %d: Bob\n",tc);
    }
}
