#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[40][40];

ll nCr(int n, int r)
{
    if(n == r)
        return 1;
    if(r == 1)
        return n;
    if(r == 0)
        return 1;

    if(dp[n][r] != -1)
        return dp[n][r];

    dp[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);

    return dp[n][r];
}

int main()
{
    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++){
    memset(dp, -1, sizeof(dp));
        int n , r;

        scanf("%d %d", &n, &r);
        if(n < r){
            printf("Case %d: 0\n", tc);
            continue;
        }

        ll ans, p = 1;

        for(int i = n; i > (n - r); i--){
            p *= i;
        }

        ans = p * nCr(n, r);

        printf("Case %d: %lld\n",tc, ans);
    }
    return 0;
}
