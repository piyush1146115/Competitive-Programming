#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define inf 100000000000
int main()
{
    ll n, k;

    scanf("%I64d %I64d", &n, &k);
    ll mn = inf, mx = -inf;
    ll m;
    ll f, s;

    for(int i = 0; i < n; i++){
        scanf("%I64d", &m);
        if(i == 0)
            f = m;
        if(i == n -1)
            s = m;

if(mn > m)
    mn = m;
if(mx < m)
    mx = m;

    }

    if(k == 1)
        cout << mn << endl;
    else if(k == 2)
        cout << max(f, s) << endl;
    else
        cout << mx << endl;
}
