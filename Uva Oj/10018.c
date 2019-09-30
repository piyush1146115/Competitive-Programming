#include<stdio.h>
int main()
{
    unsigned long long int a,pal,b,c,d,rev, n,sum;
    int test,i,j;
    scanf("%d",&test);
    for(i = 1; i <= test;i++){
    scanf("%llu",&n);
    j = 0;
    sum = 0;
    b = n;
    rev = 0;
    while(n >= 1){
        c=n%10;
        rev= rev*10 + c;
        n = n/10;
    }
    a = rev;
    sum = a + b;
    loop:
    n=sum;
    rev = 0;
    j++;
    while(n >= 1){
        c=n%10;
        rev= rev*10 + c;
        n = n/10;
    }
    pal = rev;

    if(pal == sum){
        printf("%d %llu\n",j,pal);
    }
    else{
        sum = pal + sum;
        goto loop;
    }
    }
    return 0;
}
