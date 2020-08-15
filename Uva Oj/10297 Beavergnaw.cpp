#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
int main()
{
    double r, R, d, D, V, total, k, ar;

    while(cin >> D >> V){
        if(D == 0 && V == 0)
            break;
        R = D/ 2.0;
        total = pi * R * R * D;
        k = (2.0/3.0) * (pi * R* R * R);
         ar = (total - V - k)/ pi;
        d = cbrt(ar * 6.0);
        printf("%.3lf\n",d);
    }
    return 0;
}
