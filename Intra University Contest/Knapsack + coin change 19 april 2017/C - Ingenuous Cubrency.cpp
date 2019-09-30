#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll coin[25];
ll dp[25][10000];

ll power(int b, int p)
{
    if(p == 0)
        return 1;
    if(p % 2 == 0){
        ll ret = power(b, p/2);
        return ret *ret;
    }
    else{
        return b * power(b, p - 1);
    }
}
ll fun(int pos, int value)
{
    if(value < 0)
        return 0;
    if(value == 0)
        return 1;
    if(pos > 21)
        return 0;

    if(dp[pos][value] != -1){
        return dp[pos][value];
    }
    else{
        ll p1 = fun(pos, value - coin[pos]);
        ll p2 = fun(pos + 1, value);
        dp[pos][value] = p1 + p2;
        return dp[pos][value];
    }
}

int main()
{
    for(int i = 1; i <= 22; i++){
        ll res = power(i, 3);

        //cout << i << " " << res << endl;
        coin[i] = res;
    }

    ll n;
    memset(dp, -1, sizeof(dp));


    while(scanf("%lld", &n) == 1){
        ll ans = fun(1,n);
        printf("%lld\n",ans);
    }

}
