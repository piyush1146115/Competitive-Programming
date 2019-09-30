#include<stdio.h>
int main()
{
    unsigned long long a, b, sum, S, D;

    while(scanf("%llu %llu",&S, &D) == 2){
        sum = 0;

        for(a = S; sum < D;a++ ){
            sum += a;
        }

        printf("%llu\n",a-1);
    }
    return 0;
}
