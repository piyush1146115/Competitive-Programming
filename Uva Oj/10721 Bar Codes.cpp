#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[55][55];
int n, k, m;

ll fun(int pos, int sum)
{
    if(pos == k){
        if(sum == n)
            return 1;
        else
            return 0;
    }

    if(sum >= n)
        return 0;

    if(dp[pos][sum] != -1)
        return dp[pos][sum];

    ll p = 0;

    for(int i = 1; i <= m ; i++){
        p += fun(pos + 1, sum + i);
    }
    return dp[pos][sum] = p;
}

int main()
{
    while(scanf("%d %d %d", &n , &k, &m) == 3){
        memset(dp, -1, sizeof(dp));
        ll ans = fun(0, 0);
        printf("%lld\n",ans);
    }
}
