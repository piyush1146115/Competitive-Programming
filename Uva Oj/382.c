#include<stdio.h>
int main()
{
    int n, a, b = 1, div, sum,i,j,count;

    while(scanf("%d", &n) == 1){
            sum = 0;
            if(b == 1){
            printf("PERFECTION OUTPUT\n");
            b = 0;
            }
        if(n == 0){
            printf("END OF OUTPUT\n");
            break;
        }
        for(a = 1; a <= n/2;a++){
            if(n % a == 0){
                sum = sum +a;
            }
        }
        div = sum;
        count = 0;
        while(div >= 1){
            i = div % 10;
            div = div/10;
            count++;
        }
    if(sum == n){
        printf("%5d  PERFECT\n",n);
    }
    else if(sum > n || n == 4){
        printf("%5d  ABUNDANT\n",n);
    }
    else{
        printf("%5d  DEFICIENT\n",n);
    }
    }
return 0;
}
