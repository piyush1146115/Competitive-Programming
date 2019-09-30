#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;

    scanf("%d",&test);

    for(int tc = 1; tc <= test; tc++){
        double x, y, c;

        scanf("%lf %lf %lf", &x, &y, &c);

        double hi = min(x, y), lo = 0.0, mid;

        while(abs(lo - hi) >= .000000001){
            mid = (lo + hi)/2.0;
            double ad = sqrt((x * x) - (mid * mid));
            double bc = sqrt((y * y) - (mid * mid));
            double ef = (ad * bc)/ (ad + bc);

            if(abs(ef - c) <= .00000001)
                break;
            if(ef > c)
                lo = mid;
            if(ef < c)
                hi = mid;
        }
        printf("Case %d: %.10lf\n",tc, mid);
    }
    return 0;
}
