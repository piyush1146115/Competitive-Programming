#include<stdio.h>
#include<stdbool.h>
#include<math.h>
unsigned long long ara[1000005] = {0};
//unsigned long long ara2[100000];
bool isPrime(unsigned long long int x)
{
    unsigned long long int i, j;

    j = sqrt(x);
    for(i = 2; i <= j; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    unsigned long long int n, a, b,m,l;
    long long i, j, index,sqr;
    while(scanf("%llu", &n) == 1 && n != 0){
    l = n;

    sqr = sqrt(n);

    for(a = 2; a <= sqr;a++ ){
        if(ara[a] == 0){
            for(b = a*a ; b < n; b += a){
                ara[b] = 1;
            }
        }
    }
    for(b = 2; b <= n/2; b++){
        if(ara[b] == 0){
            m = n - b;

        }
         if(isPrime(m)){
                printf("%llu:\n%llu+%llu\n",l,b,m);
                break;
            }
    }
    if(b > n/2){
        printf("%llu:\nNO WAY!\n",l);
    }
}
return 0;
}
