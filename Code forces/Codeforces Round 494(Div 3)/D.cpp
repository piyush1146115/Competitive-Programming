#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[200005], bt[100];
ll n, q;
int main()
{
    //cin >> n >> q;
    scanf("%I64d %I64d", &n, &q);

    for(int i = 0; i < n; i++)
    {
        scanf("%I64d", &ara[i]);
    }
    memset(bt, 0, sizeof(bt));

    sort(ara, ara + n);
    ll cnt = 0;

    for(int i = 0; i < n; i++)
    {
        cnt = 0;
        ll sum = 1 << cnt;
        while(sum <= ara[i])
        {
            if(sum == ara[i])
            {
                bt[cnt]++;
                break;
            }
            cnt++;
            sum = 1 << cnt;
        }
    }


    while(q--)
    {
        ll k;
        scanf("%I64d", &k);

            ll mx = 0 ,ans  = 0;

            while((1 << mx) < k){
                mx++;
            }

            for(ll i = mx; i >= 0; i--){
                if(bt[i]){
                    ll temp = 1 << i;

                        ll div = k /temp;
                        ll use = min(div, bt[i]);
                        k -= (use * temp);
                        ans += use;
                }
            }


        if(!k)
            printf("%I64d\n",ans);
        else
            printf("-1\n");

    }
}
