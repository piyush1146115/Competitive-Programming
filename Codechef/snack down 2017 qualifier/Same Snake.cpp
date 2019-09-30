#include<bits/stdc++.h>
using namespace std;
#define mxx 100005
#define ll long long

ll  cum[mxx];
vector<ll> v;

int main()
{
    int test;

    scanf("%d",&test);

    while(test--){
        ll n, m;
        ll l;

        scanf("%lld %lld", &n, &m);

        for(int i = 0; i < n; i++){
            scanf("%lld",&l);
            v.push_back(l);
        }

        sort(v.begin(), v.end());

        for(int i = 0; i < v.size(); i++){
            cum[i + 1] = cum[i] + v[i];
        }


        while(m--){
            ll q;
            scanf("%lld", &q);
//
//            for(int i = 1; i <= n; i++)
//                cout << cum[i] << " ";
//
//            cout << endl;

            ll it = lower_bound(v.begin(), v.end(), q) - v.begin();
           // printf("%d\n",it);
           ll lo = 0, mid, hi = it + 1;
           ll ans = 0;

           if(it <= n)
           while(lo <= hi){

            mid = (lo + hi)/2;
            ll dif = cum[it] - cum[it - mid];
            ll dd = (mid * q) - dif;
            ll df = it - mid ;
//           cout << lo << " " << hi << " " << it << " " << cum[it] << " " << cum[it - mid] <<" " << dd << " " << df << endl;
//            getchar();
//            getchar();

            if(dd <= df){
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
           }

           if(it <= n)
           ans += (n - it);

           printf("%lld\n",ans);
        }
        cum[0] = 0;
        cum[1] = 0;
        v.clear();
    }
return 0;
}
