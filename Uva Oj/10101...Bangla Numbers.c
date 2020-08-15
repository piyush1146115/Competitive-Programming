#include<stdio.h>
void count(unsigned long long int n)
{
    unsigned long long int a, b;
     if(n >= 10000000){
            a = n / 10000000;
            n = n - (a * 10000000);
            printf("%llu kuti",a);
        }
        if(n >= 100000){
            a = n / 100000;
            n = n - (a * 100000);
            printf("%llu lakh ",a);
        }
        if(n >= 1000){
            a = n / 1000;
            n = n - (a * 1000);
            printf("%llu hajar ",a);
        }
        if(n >= 100){
            a = n / 100;
            n = n - (a * 100);
            printf("%llu shata",a);
        }
        printf("%llu ",n);
}
int main()
{
    unsigned long long int n, a, b, c = 0;


    while(scanf("%llu",&n) == 1){
            c++;
            printf("%4d.",c);
        if(n >= 10000000){
            a = n / 10000000;
            n = n - (a * 10000000);
            count(a);
            printf("kuti");
            if(n == 0){
                printf("\n");
                continue;
            }
            printf(" ");
        }
        if(n >= 100000){
            a = n / 100000;
            n = n - (a * 100000);
            printf("%llu lakh",a);
             if(n == 0){
                printf("\n");
                continue;
             }
             printf(" ");

        }
        if(n >= 1000){
            a = n / 1000;
            n = n - (a * 1000);
            printf("%llu hajar",a);
             if(n == 0){
                printf("\n");
                continue;
             }
             printf(" ");
        }
        if(n >= 100){
            a = n / 100;
            n = n - (a * 100);
            printf("%llu shata",a);
             if(n == 0){
                printf("\n");
                continue;
             }
             printf(" ");
        }
        printf("%llu",n);
        printf("\n");
    }
    return 0;
}
