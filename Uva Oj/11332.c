#include<stdio.h>
int main()
{
    unsigned long long int n, a, sum;

    while(scanf("%llu",&n) == 1 && n != 0){
    sum = 0;
    loop:
    while(n >= 1){
        a = n % 10;
        sum = sum + a;
        n = n / 10;
    }
    if(sum < 10){
    printf("%llu\n",sum);
    }
    else{
        n = sum;
        sum = 0;
        goto loop;
    }
    }
    return 0;
}

