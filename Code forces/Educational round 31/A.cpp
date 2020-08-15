#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define ff first
#define ss second

int main()
{
    ll n, t;

    cin >> n >> t;

    ll ara[n + 5];

    for(int i = 0; i < n; i++)
        cin >> ara[i];
    ll sum = 0;
    ll ans;
    for(int i = 0; i < n; i++){
        sum += (86400 - ara[i]);
        if(sum >= t){
            ans = i;
            break;
        }
    }
    cout << ans + 1 << endl;
}
