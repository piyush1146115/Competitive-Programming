#include<bits/stdc++.h>
using namespace std;

double p, q, r, s, t, u;

double calc(double x)
{
     return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{

    while(cin >> p >> q >> r >> s >> t >> u){
        double lo = 0.0, hi = 1.0, mid;

        for(int i = 0; i < 200; i++){
            mid = (lo + hi)/2.0;
            if(calc(mid) >= 0.0)
            {
                lo = mid;
            }
            else
                hi = mid;
        }

        if(abs(calc(mid)- 0) > 1e-10){
            printf("No solution\n");
        }
        else
            printf("%.4lf\n",mid);
    }
    return 0;
}
