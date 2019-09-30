#include<stdio.h>
#include<math.h>
int main()
{
    int a, b, dif,i, j;

    while(scanf("%d %d",&a, &b) == 2 && (a != -1 || b != -1)){
        dif = fabs(b - a);
        if(dif > 50){
            dif = 100 - dif;
        }
        printf("%d\n",dif);
    }
return 0;
}
