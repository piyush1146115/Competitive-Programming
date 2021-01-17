#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll w, h, n;

bool fun(ll x)
{
    if(((x/w) >= n && (x/h) > 0) || ((x/h) >= n && (x/w) > 0) || (((x/w) * (x/h)) >= n)){
        return true;
    }
	
    return false;
}

int main()
{
    cin >> w >> h >> n;

    ll lo = 0, mid, hi = 1e18 + 10;
    ll ans = -1;

    while((hi -lo) > 1){
        mid = (lo + hi)/2LL;
		//cout <<lo << " " << hi << " " <<  mid << endl;
		
        if(fun(mid)){
            hi = mid;
            ans = mid;
        }
        else{
            lo = mid;
        }
    }    

    cout << ans << endl;
}
