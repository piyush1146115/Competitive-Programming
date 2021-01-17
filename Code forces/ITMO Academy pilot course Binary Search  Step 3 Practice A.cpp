#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> v, x;
ll n;

bool fun(double t)
{
    double lf, rt, lo, hi;

    lf = x[0] - (double)v[0]*t;
    rt = x[0] + (double)v[0]*t;

    for(int i = 1; i < n; i++){
        lo = x[i] - (double)v[i]*t;
        hi = x[i] + (double)v[i]*t;
        if(hi < lf && lo > rt)
            return false;
        
        rt = max(lo, rt);
        lf = min(lo, rt);
    }
    return true;

}
int main()
{
    
    cin >> n;

    v.resize(n + 2);
    x.resize(n + 2);

    for(int i = 0; i < n; i++){
        cin >> v[i] >> x[i];
    }    

    double lo = 0.0, hi = (double)n + 2.0, mid;

    double ans = 0;

    for(int i = 1; i <= 100; i++){
        mid = (lo + hi)/2.0;
        cout << lo << " " << hi << " " << ans << endl;
        
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