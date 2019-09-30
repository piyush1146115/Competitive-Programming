#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ara[25];

ll lcm(ll a, ll b)
{
    ll mul = a * b;
    ll gc = __gcd(a,b);
    ll res = mul/gc;

    return res;
}
int main()
{
    int test;
    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++){
            ll n, m;

            scanf("%lld %lld", &n, &m);

            for(ll i = 0; i < m; i++){
                scanf("%lld", &ara[i]);
            }

            ll lim = (1 << m);
            ll ans = n;
            vector<ll> temp;
            for(ll i = 1; i < lim; i++){
                for(ll j = 0; j <= m; j++){
                    if((1 << j) & i){
                        temp.push_back(ara[j]);
                    }
                }

                if(temp.size() > 1){
                    ll lc = lcm(temp[0], temp[1]);
                    for(int j = 2; j < temp.size(); j++){
                        lc = lcm(lc, temp[j]);
                    }
                    if(temp.size() % 2 == 0){
                        ans += (n/lc);
                    }
                    else{
                        ans -=(n/lc);
                    }
                }
                else{
                    ans -= (n/temp[0]);
                }
                temp.clear();
            }
            printf("Case %d: %lld\n",tc, ans);
    }
}
