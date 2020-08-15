#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mxx 100004

ll ara[mxx];
ll n, t;

bool calc(ll q)
{
    ll sum = 0, ans = LONG_LONG_MAX;
    for(int i = 0; i < q; i++)
        sum += ara[i];

    ans = min(sum, ans);
 //   cout << ans << endl;
   // getchar();
    for(int i = q; i < n; i++){
        sum -= ara[i - q];
        sum += ara[i];
         ans = min(sum, ans);
    }

    if(ans <= t)
        return true;
    else
        return false;
}

int main()
{
    scanf("%lld %lld",&n, &t);

    for(int i = 0; i < n; i++)
        scanf("%lld", &ara[i]);

        ll lo = 0, hi = n, mid, ans = 0;

        while(lo <= hi){

            mid = (lo + hi)/2;
            if(calc(mid)){
                ans = max(ans, mid);
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }

        printf("%lld\n",ans);

        return 0;
}
