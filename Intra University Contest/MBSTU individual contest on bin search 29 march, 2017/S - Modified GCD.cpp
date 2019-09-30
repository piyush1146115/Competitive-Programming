#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll, ll> mp;
vector<ll> v;

int main()
{
    ll a, b;
    scanf("%lld %lld", &a , &b);
    ll n;
    scanf("%lld", &n);

    for(ll i = 1; i * i <= a; i++){
        if(a % i == 0){
            if(i * i == a){
                mp[i]++;
                v.push_back(i);
            }
            else{
                mp[i]++;
                v.push_back(i);
                mp[a/i]++;
                v.push_back(a/i);
            }
        }
    }

    for(ll i = 1; i * i <= b; i++){
        if(b % i == 0){
            if(i * i == b)
                mp[i]++;
            else{
                mp[i]++;
                mp[b/i]++;
            }
        }
    }

//    for(int i = 0; i < v.size(); i++)
//        cout << v[i] << " " << mp[v[i]] << endl;
////
    for(int i = 0; i < n; i++){
        ll ans = -1;

     ll left, right;
        scanf("%lld %lld", &left, &right);
        for(int j = 0; j < v.size(); j++){
            if(v[j] >= left && v[j] <= right && mp[v[j]] >= 2){
                ans = max(ans, v[j]);
            }
           // cout << v[j] << " " << mp[v[j]] << endl;
        }
    cout << ans << endl;
    }
}
