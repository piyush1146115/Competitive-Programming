#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll bm(ll n)
{
    if(n == 0)
        return 1;
    if(n % 2 == 0){
        ll p = bm(n/2);
        return ((p % mod) * (p % mod))%mod;
    }
    else{
        return (2 * (bm(n - 1) % mod)) % mod;
    }
}

int main()
{
    ll n, i, j, test, cs= 0;

    scanf("%lld",&test);

    while(test--){
        scanf("%lld",&n);
        ll ans;
        if(n == 1)
            ans = 1;
        else
         ans = ((n % mod) * bm(n - 1))%mod;

        printf("Case #%lld: %lld\n", ++cs, ans);
    }
    return 0;
}
