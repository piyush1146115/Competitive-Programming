#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
#define ll long long
vector<ll> a, b;
int main()
{
    ll n, m, k;
    scanf("%I64d %I64d", &n, &m);

    for(int i = 0; i < n; i++){
        scanf("%I64d", &k);
        a.push_back(k);
    }

    for(int i = 0; i < m; i++){
        scanf("%I64d", &k);
        b.push_back(k);
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < m; i++){
        ll u = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        printf("%I64d\n",u);
    }

    return 0;
}
