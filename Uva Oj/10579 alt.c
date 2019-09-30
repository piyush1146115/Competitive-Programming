#include<stdio.h>
int main()
{
    unsigned long long int fibo[1500];
    int n, a;

    scanf("%d", &n);

    fibo[0] = 0;
    fibo[1] = 1;

    for( a = 2; a < n ; a++){
        fibo[a] = fibo[a - 1] + fibo[a - 2];
    }

    printf("%llu", fibo[a - 1]);

    return 0;
}
