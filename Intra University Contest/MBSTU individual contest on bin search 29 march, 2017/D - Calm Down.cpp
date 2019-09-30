#include<bits/stdc++.h>
using namespace std;
#define eps 1e-7
#define sq(x) x*x
#define pi acos(-1)

int main()
{
    int test;
    scanf("%d", &test);
    double n, r;

    for(int tc = 1; tc <= test; tc++){
        scanf("%lf %lf", &r, &n);
        double a, b, c;
        double lo = 0.0, hi = r, mid;

        while(1){
            mid = (lo + hi)/2.0;
            a = 2.0 * mid;
            b = r - mid;
            c = r - mid;

            double temp = ((sq(b) + sq(c) - sq(a))/(2.0*b*c));
           double angle = acos(temp)  * (180 / pi);
            double total = angle  * n;

            //cout << mid << " " << angle << endl;
           // printf("%lf %lf %lf\n",mid, temp, angle);
            //getchar();
            if(abs(total - 360.0) <= eps)
                break;
            if(total > 360.0)
                hi = mid;
            else
                lo = mid;
        }

        printf("Case %d: %.10lf\n", tc, mid);
    }
    return 0;
}
