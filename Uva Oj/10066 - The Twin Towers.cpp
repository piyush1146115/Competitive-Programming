#include<bits/stdc++.h>
using namespace std;
#define mxx 105

int a[mxx], b[mxx];
int dp[mxx][mxx];

int n, m;

int lcs(int i, int j)
{
    if(i == n || j == m)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;

    if(a[i] == b[j])
        ans = 1 + lcs(i + 1, j + 1);
    else{
        ans = max(ans, lcs(i + 1, j));
        ans = max(ans, lcs(i, j + 1));
    }

    dp[i][j] = ans;
    return ans;
}

int main()
{
    int tc = 0;

    while(scanf("%d %d",&n, &m) == 2){
        if(n == 0 && m == 0)
            break;

    memset(dp, - 1, sizeof(dp));

        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);

        for(int i = 0; i < m; i++)
            scanf("%d", &b[i]);
        int ans = lcs(0, 0);

        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",++tc,ans);
    }
}
