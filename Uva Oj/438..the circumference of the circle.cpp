#include<bits/stdc++.h>
using namespace std;
#define pi 3.141592653589793
struct point{
double x;
double y;
}p1, p2, p3;
int main()
{
    double a, b, c, num, den, ans;

    while(scanf("%lf %lf %lf %lf %lf %lf",&p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y) == 6){

        a = sqrt(((p1.x - p2.x)* (p1.x - p2.x)) +((p1.y - p2.y) * (p1.y - p2. y)));
        b = sqrt(((p2.x - p3.x)* (p2.x - p3.x)) +((p2.y - p3.y) * (p2.y - p3. y)));
        c = sqrt(((p3.x - p1.x)* (p3.x - p1.x)) +((p3.y - p1.y) * (p3.y - p1. y)));

        den =  a * b * c;
        num = sqrt((a + b + c) * (b + c - a) * (c + a - b) * (a + b - c) );

        ans = den / num;

        ans = ans * 2 * pi;

        ans += 1e-9;

        printf("%0.2lf\n",ans);
    }
    return 0;
}
