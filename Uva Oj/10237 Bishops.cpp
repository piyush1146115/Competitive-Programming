#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[65][65];

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
    int test, n, r;

    while(scanf("%d %d", &n, &r) == 2){
    if(n == 0 && r == 0)
            break;

    memset(dp, -1, sizeof(dp));

        ll ans, p = 1;
        int m = n;

        if(n  > 1)
            m = (n * 2) - 2;

        if(m < r)
        {
            printf("0\n");
            continue;
        }
        for(int i = n; i > (n - r); i--)
        {
            p *= i;
        }
        //cout << m << " " << p << endl;

        ans =  p * nCr(m, r);

        printf("%lld\n",ans);
    }

    return 0;
}
