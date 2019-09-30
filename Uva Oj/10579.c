#include<stdio.h>
int main()
{
    unsigned long long int fibo, a, i, j;
    int n, m;

    a = 0;
    i = 1;
    scanf("%d", &n);
    m = 2;

    while(m != n){
        fibo = a + i;
        a = i;
        i = fibo;
        m++;
    }


    printf("%llu\n", fibo);

    return 0;
}
