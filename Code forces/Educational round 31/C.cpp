#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

#define pii pair<int, int>
#define pll pair<ll, ll>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define ff first
#define ss second
#define mxx 100005

int ara[mxx], mp[mxx], par[mxx];

int fnd(int x){
if(par[x] == x)
    return x;
    else
        return par[x] = fnd(par[x]);
}
int Union(int a, int b)
{

    par[fnd(b)] = fnd(a);
}


int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
       scanf("%d", &ara[i]);
        par[i] = i;
    }

    for(int i = 1; i <= n; i++){
        Union(i, ara[i]);
    }

    for(int i = 1; i <= n; i++){
        mp[fnd(ara[i])]++;
    }

    vector<ll> v;

    for(int i = 1; i <= n; i++){
        if(mp[i] > 0){
            v.push_back(mp[i]);
        }
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ll ans = 0;
    if(v.size() > 1){
        v[0] = v[0] + v[1];
        v.erase(v.begin() + 1);

        for(int i = 0; i < (int)v.size(); i++){
            ans += (v[i]* v[i]);
        }
    }
    else{
        ans = v[0]*v[0];
    }

    cout << ans << endl;
}
