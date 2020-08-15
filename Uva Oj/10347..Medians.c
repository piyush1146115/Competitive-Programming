#include<stdio.h>
#include<math.h>
int main()
{
   double  a, b, c, i, j, k, l;

    while(scanf("%lf %lf %lf",&a,&b,&c) == 3){
        i = (a + b + c) / 2;

       j = i*((i - a) * (i - b) * (i - c));

        k =  sqrt(j);
        l = (4.0/3.0) * k;

        if(l > 0){
            printf("%.3lf\n",l);
        }

        else{
            l = -1;
            printf("%.3lf\n",l);
    }
    }

    return 0;
}
