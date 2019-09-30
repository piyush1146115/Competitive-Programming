#include<bits/stdc++.h>
using namespace std;
#define mod 1000
#define ll long long


ll bigmod(ll b, ll p)
{
    if(p == 0)
        return 1;

    if(p % 2 == 0){
        ll ret = bigmod(b, p/2);
        return ((ret % mod)*(ret % mod))%mod;
    }
    else
        return ((b % mod ) * (bigmod(b, p -1) % mod)) % mod;
}


int main()
{
    const double eps = 1e-9;

    ll test, tc = 0;

    scanf("%lld",&test);

    while(test--){
        double n, k;
        cin >> n >> k;

        double fact =k * log10(n);

        double q = fact - floor(fact + eps);
        double b = pow(10.0, q);
       // cout << b << endl;

        for(int i = 0; i < 2; i++)
            b *= 10.0;

        printf("Case %lld: ", ++tc);
        ll ans = (int)b;

        cout << ans << " ";
        ll a = (int)n;
        ll c = (int)k;

        ll ret = bigmod(a, c);
        printf("%03lld\n",ret);
    }
    return 0;
}
