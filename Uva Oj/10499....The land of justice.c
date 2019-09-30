#include<stdio.h>
int main()
{
    long long int  n;
   long long int a;
    while(scanf("%lld", &n) == 1 && n >= 0){
        a = .25 * n * 100;
        if(n == 1)
            a = 0;

        printf("%lld%%\n",a);
    }
    return 0;
}
