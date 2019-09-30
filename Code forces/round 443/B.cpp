#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define DEBUG(x) cout<<#x<<": "<<x<<endl

int main()
{
    ll n, k;

    cin >> n >> k;

    ll ara[n + 5];

    for(int i = 0; i <  n; i++)
        cin >> ara[i];

    if(k >= n){
        cout  <<n << endl;
    }
    else{
        int flag = 0;
        ll ans ;
        int cnt = 0;
        int f = ara[0];

        for(int i = 1; i < n; i++){
            if(f > ara[i]){
                cnt++;
            }
            else{
                f = ara[i];
                    cnt = 1;
            }

            if(cnt >= k){
                flag = 1;
                ans = f;
                break;
            }
        }
        if(flag){
            cout   << ans << endl;
        }
        else{
            cout << n << endl;
        }
    }
   // main();
}
