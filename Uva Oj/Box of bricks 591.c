#include<stdio.h>
int main()
{
    int ara[55];
    int h, avg, j, k = 0, a, b, n, sum;

    while(scanf("%d", &n) == 1 && n != 0){
            k++;
            sum = 0;
        for(a = 0; a < n; a++){
            scanf("%d", &ara[a]);
            sum = sum + ara[a];
        }
        avg = sum / n;
        h = 0;
        for(a = 0; a < n; a++){
            if(ara[a] > avg){
                h = h + (ara[a] - avg);
            }
        }
        printf("Set #%d\n",k);
        printf("The minimum number of moves is %d.\n\n",h);
    }
return 0;
}
