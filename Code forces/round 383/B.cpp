#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pf printf
#define sf scanf
#define ull unsigned long long
#define sq(x) x*x
#define mxx 100005
int ara[mxx];
int main()
{
    map<int , int> mp;
    int i,  n, m;

    cin >> n >> m;

    for( i = 0; i < n; i++)
    {
        sf("%d",&ara[i]);
        mp[ara[i]]++;
    }
    ll ans = 0;

    for(i = 0; i < n; i++){
        int p = ara[i] ^ m;
        mp[ara[i]]--;
        ans += mp[p];
    }

    cout << ans << endl;
}
