#include<stdio.h>
int main()
{
    long long n;

    while(scanf("%lld", &n) == 1 && n != 0){

    if(n <= 100){
        printf("f91(%lld) = 91\n",n);
    }
    else{
        printf("f91(%lld) = %lld\n",n,n-10);
    }
    }
return 0;

}
