#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
int main()
{
    double r, s, d, ang;
    char st[10];

    while(scanf("%lf %lf %s",&r, &ang, st) == 3){
        if(st[0] == 'm')
            ang /= 60;
        if(ang > 180)
            ang = 360 - ang;

        ang = (pi * ang) / 180;
        r += 6440;

        s = r * ang;
        d = 2.0 * r * sin(ang / 2.0);

        printf("%.6lf %.6lf\n",s, d);
    }
    return 0;
}
