#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<double> v, x;
ll n;

bool fun(double t)
{
    double lf, rt, lo, hi;

    lf = x[0] - v[0]*t;
    rt = x[0] + v[0]*t;

	//cout << (double)v[0]*t << endl;
	
    for(int i = 1; i < n; i++){
        lo = x[i] - v[i]*t;
        hi = x[i] + v[i]*t;
        
        rt = min(hi, rt);
        lf = max(lo, lf);
    }
    
    return (rt > lf);

}

int main()
{
     ios_base::sync_with_stdio(false);
     
    cin >> n;

    v.resize(n + 2);
    x.resize(n + 2);

    for(int i = 0; i < n; i++){
        cin >> x[i] >> v[i];
    }    

    double lo = 0.0, hi = (double)(20000000000.0), mid;

    double ans = 0;

    for(int i = 1; i <= 100; i++){
        mid = (lo + hi)/2.0;
      //  cout << lo << " " << hi << " " << ans << endl;
        
        if(fun(mid)){
            hi = mid;
            ans = mid;
        }
        else{
            lo = mid;
        }
    }
    
    cout << setprecision(10) << ans << endl;
}
