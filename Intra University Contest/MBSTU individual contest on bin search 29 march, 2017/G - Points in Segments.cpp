#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int test;
    scanf("%d", &test);
    for(int tc = 1; tc <= test; tc++){
    ll n, q;
    scanf("%lld %lld",&n, &q);
    vector<ll>v;

    while(n--){
        ll m;
        scanf("%lld", &m);
        v.push_back(m);
    }
    vector<ll> :: iterator up, lo;
    printf("Case %d:\n",tc);
    while(q--){
        ll left, right;

        scanf("%lld %lld",&left, &right);
        if(right < left)
            swap(left, right);

        up = upper_bound(v.begin(), v.end(), right);
        lo = lower_bound(v.begin(), v.end(), left);

        ll ans = up - lo;
        printf("%lld\n",ans);
    }
    }
    return 0;

}
