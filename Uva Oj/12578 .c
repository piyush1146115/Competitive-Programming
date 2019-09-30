#include<stdio.h>
#include<math.h>
#define pi acos(-1)
int main()
{
    double lenth, rad, width, area_c, area_r;
    int test, a;

    scanf("%d", &test);

    for(a = 1; a <= test; a++){
        scanf("%lf", &lenth);
        rad = .2 * lenth;
        width = .6 * lenth;

        area_c = pi * rad * rad;
        area_r = width * lenth;

        printf("%.2lf %.2lf\n",area_c,area_r - area_c);
    }
return 0;
}
