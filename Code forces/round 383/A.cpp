#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pf printf
#define sf scanf
#define ull unsigned long long
#define sq(x) x*x

ll bigmod(ll n, ll p)
{
    if(p == 0)
        return 1;
    if(p % 2 == 0){
        ll ans = bigmod(n, p /2) % 10;
        return ((ans% 10 ) * (ans % 10))% 10;
    }
    else{
        return ((1378 % 10) * (bigmod(n, p - 1)% 10))%10;
    }
}
int main()
{
    ll n;

    sf("%lld", &n);

    ll ans = bigmod(1378, n);

    cout<< ans<< endl;
}
