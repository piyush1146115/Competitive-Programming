#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll lob, hor, p, q;
#define mxx 10000000000


ll bin(ll lo, ll hi)
{
    ll mid;
    ll ans = -1;

    while(lo <= hi){
        mid = (lo + hi)/2;
//if((mid*p>=x) && (mid*q>=y) && (mid*p-x<=mid*q-y))
        if((mid *p >= lob) && (mid*q >= hor)  &&(mid*p-lob<=mid*q-hor)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int test;

    scanf("%d", &test);

    while(test--){
     //   scanf("%I64d %I64d %I64d %I64d",&lob, &hor, &p, &q);
     cin >> lob >> hor >> p >> q;

        ll ans = bin(0, mxx);
        //cout << ans << endl;
        if(ans == - 1)
            printf("%I64d\n", ans);
        else
        printf("%I64d\n",ans*q - hor);


        }
}

