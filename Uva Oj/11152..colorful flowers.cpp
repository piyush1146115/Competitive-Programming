#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
int main()
{
    double a, b, c, s, area_tr, r, R, vio, rose, sun;

    while(scanf("%lf %lf %lf",&a , &b, &c) == 3){
        s = (a + b + c)/ 2.0;
        area_tr = sqrt(s * (s - a) * (s - b) * (s - c));
        r = area_tr / s;
        rose = (r * r) * PI;
        vio = area_tr - rose;
        R = (a * b * c)/ (4* area_tr);
        sun = (PI * R * R) - area_tr;

        printf("%.4lf %.4lf %.4lf\n", sun, vio, rose);
    }
    return 0;
}
