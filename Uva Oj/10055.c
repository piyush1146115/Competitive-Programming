#include<stdio.h>
int main()
{
    unsigned long long int a, b, sum;

    while(scanf("%llu %llu", &a, &b) == 2){
        if(a >= b)
            sum = a - b;
        else
            sum = b - a;

        printf("%llu\n", sum);
    }
return 0;
}
