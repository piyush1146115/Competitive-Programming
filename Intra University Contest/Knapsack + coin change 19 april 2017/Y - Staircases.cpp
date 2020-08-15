#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[505][505];
ll n;

ll fun(int value, int level )
{
    if(level == n)
        return 1;
    if(level > n)
        return 0;
        if(dp[value][level] != -1)
            return dp[value][level];

    ll p1 = 0, p2 = 0;
    for(int i = value + 1; i < n; i++){
        p1 += fun(i , level + i);
    }


    dp[value][level] = p1;
    return dp[value][level];
}

int main()
{
    ll res;
    scanf("%lld",&n);

    res = 0;
    memset(dp, -1, sizeof(dp));

    res = fun(0,0);

    printf("%lld\n", res);
}
