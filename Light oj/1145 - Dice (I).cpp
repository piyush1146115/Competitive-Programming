#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000007

ll dp[5][15005];

int main()
{
    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {
        ll n, k, s;
        scanf("%lld %lld %lld", &n, &k, &s);
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= k; i++)
        {
            if(i <= k)
            dp[0][i] = 1;
        }
    // cout << cum[0][s] << endl;

        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= s; j++)
            {
                if(i % 2 == 0)
                {
                    dp[1][j] =  (dp[1][j - 1] + dp[0][j - 1])% mod;
                  //  cout << i << " " << j << " " << dp[1][j] << endl;
                    if((j - k - 1) >= 0)
                    {
                     //   cout << cum[0][j - k - 1] << endl;
                        dp[1][j] -= dp[0][ j - k - 1];
                        if(dp[1][j] < 0)
                            dp[1][j] += mod;
                    }
                    //cout << i << " " << j << " " << dp[1][j] << endl;
                   // cum[1][j] = (cum[1][ j -1] + dp[1][j]) % mod;
                }
                if(i % 2 == 1)
                {
                    dp[0][j] = (dp[0][j - 1] +  dp[1][ j - 1]) % mod;
                    if((j - k - 1) >= 0)
                    {
                        dp[0][j] -= dp[1][ j - k - 1];
                        if(dp[0][j] < 0)
                            dp[0][j] += mod;
                    }
                    //cout << i << " " << j << " " << dp[1][j] << endl;
                    //cum[0][j] = (cum[0][ j -1] + dp[0][j]) % mod;
                }
            }
        }

        if(n % 2 == 1)
            printf("Case %d: %lld\n",tc, dp[0][s] %mod);
        else
            printf("Case %d: %lld\n",tc, dp[1][s] %mod);
    }
}
