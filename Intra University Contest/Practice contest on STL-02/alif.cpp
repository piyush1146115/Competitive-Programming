#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll cal(ll x){
    ll res = x * (x-1);
    res /= 2;
    return res;
}

ll outOfBound(ll l, ll r, ll x){
    if(x<l || x>r) return true;
    return false;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        ll res = 0;
        ll l, r, taken = 0;
        for(int i=0;i<n;i++){
            ll x;
            cin >> x;
            if(!i){
                taken ++;
                l = r = x;
                continue;
            }

            if(outOfBound(l, r, x)){
                l = min(l, x);
                r = max(r, x);
                taken ++;
            }
            else{
                taken ++;
                res += cal(taken);
                taken = 1;
                l = r = x;
            }
        }

        res += cal(taken) + n;
        cout << res << endl;
    }


}

