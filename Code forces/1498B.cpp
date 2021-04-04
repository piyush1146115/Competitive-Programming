#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);

    int test;
    cin >> test;
    ll cnt[30];

    while(test--){
        ll n, W;
        memset(cnt, 0, sizeof(cnt));

        cin >> n >> W;
        int mx = 0, lg;
        for(int i = 0; i < n; i++){
            ll w;
            cin >> w;
            lg = log2(w);
            cnt[lg]++;
            mx = max(mx, lg);
        }

        int flag = 1;
        ll ans = 0, sum;

        while(flag){
            flag = 0;
            sum = 0;

            for(int i = mx; i >= 0; i--){
                if(cnt[i] > 0){
                    flag = 1;
                    ll p = 1 << i;
                    ll dif = W - sum;
                    ll div = dif/p;
                    if(div > 0){
                        ll use = min(cnt[i], div);
                        cnt[i] -= use;
                        sum += use * p;
                    }
                }
            }
            if(flag)
                ans++;
        }
        cout << ans << endl;
    }

}