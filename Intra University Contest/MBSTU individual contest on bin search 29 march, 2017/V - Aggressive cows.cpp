#include<bits/stdc++.h>
using namespace std;
#define mxx 100005
#define ll long long

ll ara[mxx];
ll n, m;

bool chk(ll val)
{
    ll x = ara[0];
    ll cnt = 1;

    for(int i = 1; i < n; i++){
        if((ara[i] - x) >= val){
            cnt++;
            x = ara[i];
        }
    }
    //cout << cnt << " " << val << endl;
  //  getchar();

    if(cnt >= m)
        return true;
    else
    return false;
}

int main()
{
    int test;
    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++){
        scanf("%lld %lld", &n, &m);

        for(int i = 0; i < n; i++)
            scanf("%lld", &ara[i]);

        sort(ara, ara + n);

        ll hi = ara[n -1] - ara[0];
        ll lo = 0, ans;

        while(lo <= hi){
            ll mid = (lo + hi)/2;
        //cout << hi << " " << lo << " " << mid << endl;

            if(chk(mid)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        printf("%lld\n",ans);
    }
    return 0;
}
