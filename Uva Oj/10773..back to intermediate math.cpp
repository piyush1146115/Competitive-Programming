#include<stdio.h>
#include<math.h>
int main()
{
    int test, a;
    double d, u, v, dif, t1, t2;

    scanf("%d",&test);

    for(a = 1; a <= test; a++){
        scanf("%lf %lf %lf",&d, &v, &u);

        if(u == 0 ||v == 0 || u <= v){
            printf("Case %d: can't determine\n",a);
        }
        else{
            t1 = d/u;
            t2 = d/sqrt(u*u - v*v);
            dif = fabs(t1 - t2);
            printf("Case %d: %.3lf\n",a, dif);
        }
    }
    return 0;
}
