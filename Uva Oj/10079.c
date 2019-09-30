#include<stdio.h>
int main()
{
    unsigned long long int sum;
    int a, n;

    while(scanf("%d",&n)==1 && n >= 0){
        sum = 1;
    for(a = 1; a <= n; a++){
        sum = sum + a;
    }
    printf("%llu\n",sum);
    }
return 0;
}
