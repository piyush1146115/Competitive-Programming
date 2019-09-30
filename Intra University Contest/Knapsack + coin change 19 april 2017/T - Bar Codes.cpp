#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, k, m;
ll dp[52][52][52];

ll fun(int state, int sum)
{
    if(state == 0 && sum == 0)
    {
        return 1;
    }
    if(state == 0 && sum != 0)
        return 0;

    if(sum < 0 || state < 0)
    return 0;

  if(dp[state][sum][m] != -1)
    return dp[state][sum][m];

    ll p1 = 0;
    for(int i = 1; i <= m; i++){
        p1 += fun(state - 1, sum  - i);
    }

    dp[state][sum][m] = p1;
    return p1;
}

int main()
{
   int test;

   scanf("%d", &test);

       memset(dp, -1, sizeof(dp));

   for(int tc = 1; tc <= test; tc++)
   {
        scanf("%d %d %d", &n, &k, &m);

        ll ans = fun(k,n );

        printf("Case %d: %lld\n",tc, ans);
   }
}
