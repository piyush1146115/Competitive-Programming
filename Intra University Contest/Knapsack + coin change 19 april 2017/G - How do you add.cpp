#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[105][105];
ll n, k;

ll fun(ll sum, ll state)
{
    if(state == k){
        if(sum == n)
            return 1;
        else
            return 0;
    }

    if(sum > n)
        return 0;
    if(dp[sum][state] != -1)
        return dp[sum][state];

    ll ret = 0;

    for(int i = 0; i <= n; i++)
        ret += fun(i + sum, state + 1);

    dp[sum][state] = ret % 1000000;

    return dp[sum][state];
}

int main()
{
    while(scanf("%lld %lld",&n, &k) == 2){
            if(n == 0 && k == 0)
                break;

        ll ans = 0;
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i <= n; i++){
            ans += fun(i , 1);
            ans = ans % 1000000;
        }


        printf("%lld\n",ans);
    }
    return 0;
}
