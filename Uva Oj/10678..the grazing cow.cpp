#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)
int main()
{
    int nCase, tCase;
    double d,l,a,b;
    scanf("%d", &nCase);
    for(tCase=1; tCase<=nCase; tCase++)
    {
        scanf("%lf %lf",&d, &l);

        a=sqrt(((l/2)*(l/2))-((d/2)*(d/2)));
        b=l/2;
        printf("%.3lf\n",pi*a*b);
    }
    return 0;
}
