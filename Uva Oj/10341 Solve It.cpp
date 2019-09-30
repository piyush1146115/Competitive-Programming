#include<bits/stdc++.h>
using namespace std;
double p, q, r, s, t, u;
double f(double x)
{
    //return p * exp(-x) +  q * sin(x) + r * cos(x) + s * tan(x) +  (t*x *x) + u;
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{
    double high, low, mid;
    int i, j;

    while(cin >> p >> q >> r >> s >> t >> u){
        low = 0.0;
        high = 1.0;

        for(i = 0; i < 200; i++){
            mid = (low + high) / 2.0;
            if(f(mid) >= 0.0){
                low = mid;
            }
            else{
                high = mid;
            }
        }

        if(fabs(f(mid) - 0) > 1e-10 ){
            printf("No solution\n");
        }
        else
            printf("%.4lf\n",mid);
    }
    return 0;
}


