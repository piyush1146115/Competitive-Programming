#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mxx 100005

ll ara[mxx], sum[mxx];

int main()
{
    ll n, s;

    //cin >> n >> s;
    scanf("%I64d %I64d", &n, &s);

    for(int i = 0; i < n; i++){
      //  cin >> ara[i];
      scanf("%I64d", &ara[i]);
    }

    ll lo = 0, hi = n, mid, ans = 0, fin = 0;

    while(lo <= hi){
    mid = (lo + hi)/2;
    ll cost = 0;

    for(int i = 0; i < n; i++){
        sum[i] =   ara[i] + ((i + 1) * mid);
    }
    sort(sum, sum + n);

    for(int i = 0; i < mid; i++){
        cost += sum[i];
    }

//        cout << mid << " " << cost << " " << s << endl;
//        getchar();

    if(cost <= s){
        lo = mid + 1;
        ans = mid;
        fin = cost;
    }
    else{
        hi = mid - 1;
    }
    }
    printf("%I64d %I64d\n",ans, fin);
    //cout << ans << " " << fin << endl;
}
