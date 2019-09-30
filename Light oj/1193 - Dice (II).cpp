#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod  100000007
#define DEBUG(x) cout << #x <<": " << x << endl

ll dp[5][15005], cum[5][15005];

int main()
{
    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {
        ll n, k, s;
        scanf("%lld %lld %lld", &n, &k, &s);
        memset(dp, 0, sizeof(dp));
        memset(cum, 0, sizeof(cum));

        for(int i = 1; i <= k; i++)
        {
            dp[0][i] = i;
        }

        for(int i = 1; i <= s; i++)
            cum[0][i] = cum[0][i - 1] + dp[0][i];

    // cout << cum[0][s] << endl;

        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= s; j++)
            {
                if(i % 2 == 0)
                {
                    dp[1][j] =  (dp[1][j - 1] + cum[0][j - 1])% mod;
                  //  cout << i << " " << j << " " << dp[1][j] << endl;
                    if((j - k - 1) >= 1)
                    {
                     //   cout << cum[0][j - k - 1] << endl;
                        dp[1][j] -= ((dp[0][ j - k - 1] * k) % mod);
                        if(dp[1][j] < 0)
                            dp[1][j] += mod;
                        dp[1][j] -= cum[0][j - k - 1];
                        if(dp[1][j] < 0)
                            dp[1][j] += mod;

                    }
                    //cout << i << " " << j << " " << dp[1][j] << endl;
                    cum[1][j] = (cum[1][ j -1] + dp[1][j]) % mod;
                }
                if(i % 2 == 1)
                {
                    dp[0][j] =  (dp[0][j - 1] + cum[1][j - 1])% mod;
                  //  cout << i << " " << j << " " << dp[1][j] << endl;
                    if((j - k - 1) >= 1)
                    {
                     //   cout << cum[0][j - k - 1] << endl;
                        dp[0][j] -= ((dp[1][ j - k - 1] * k) % mod);
                        if(dp[0][j] < 0)
                            dp[0][j] += mod;
                        dp[0][j] -= cum[1][j - k - 1];
                        if(dp[0][j] < 0)
                            dp[0][j] += mod;

                    }
                    //cout << i << " " << j << " " << dp[1][j] << endl;
                    cum[0][j] = (cum[0][ j -1] + dp[0][j]) % mod;               }
            }
        }

        if(n % 2 == 1)
            printf("Case %d: %lld\n",tc, dp[0][s] %mod);
        else
            printf("Case %d: %lld\n",tc, dp[1][s] %mod);
    }
}
