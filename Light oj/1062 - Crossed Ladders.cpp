#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x, y, c, w, d;
    int t, i, j;

    cin >> t;

    for(i = 1; i <= t; i++){
        scanf("%lf %lf %lf",&x, &y, &c);

        d = 1/ c;

        double hi, lo, mid;

        hi = min(x, y);
        lo = 0.0;
        j = 400;

        while(j--){
            mid = (hi + lo)/ 2.0;
            double sol = 1/(sqrt((x * x) - (mid * mid))) + 1/(sqrt((y * y) - (mid * mid)));
            if(sol > d){
                hi = mid;
            }
            else{
                lo = mid;
            }
        }
        printf("Case %d: %.7lf\n",i, mid);
    }

    return 0;
}
