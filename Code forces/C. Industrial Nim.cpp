#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll f(ll n)
{

    ll x = n % 4;

    if(x == 0)
        return 0;
    else if(x == 1)
        return (n - 1);
    else if(x == 2)
        return 1;
    else
        return n;
}

int main()
{
    ll n;

    scanf("%I64d", &n);
    ll ans = 0;

    for(int i = 0; i < n; i++){
        ll k, m;
        scanf("%I64d %I64d", &k, &m);
        ans ^= (f(k) ^ f(k + m));
    }

    if(ans)
        printf("tolik\n");
    else
        printf("bolik\n");
}
