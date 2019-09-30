#include<bits/stdc++.h>
using namespace std;
#define sq(x) x*x

int main()
{
    double r1, r2, r3;
    int test;
    scanf("%d", &test);

    for(int i = 1; i <= test; i++){
    scanf("%lf %lf %lf", &r1, &r2, &r3);
    double num = r1 * r2 * r3;
    double t1 = r1 *r2 + r2*r3 + r3*r1;
    double t2 = sqrt(r1 * r2 *r3 * (r1 + r2 + r3));
    double den = t1 + 2.0*t2;

    double ans = num / den;
    printf("%.10lf\n",ans);
    }
}
