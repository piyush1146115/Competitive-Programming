#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector <ll> v;
int main()
{
    ll n, f, k, l;

    scanf("%lld %lld", &n, &f);

    ll ans  = 0;

    for(int i = 0; i < n; i++){
        scanf("%lld %lld", &k, &l);


        if(k < l){
            ans += k;
            ll temp = k * 2, dif;
            if(temp > l){
                dif = (temp - l);
                temp -= dif;
            }
            temp -= k;
            v.push_back(temp);
        }
        else{
            ans += l;
        }
    }

    sort(v.begin(), v.end());

    for(int i = v.size() - 1; i >= 0; i--){
        if(f > 0){
            ans += v[i];
            f--;
        }
    }

    printf("%lld\n",ans);
}

