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

    ll n, k;

    cin >> n >> k;

    ll sum = 0;

    for(int i = 0; i < n; i++){
        ll t;
        cin >> t;
        sum += t;
    }

    if((sum + n - 1) == k){
        printf("YES\n");
    }
    else
        printf("NO\n");

}
