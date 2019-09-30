#include<stdio.h>
#include<math.h>
unsigned long long ara[1000005] = {0};

int main()
{
    long long int n, a, b,m,l;
    long long i, j, index,sqr;

     for(a = 3; a <= 1000;a += 2 ){
        if(ara[a] == 0){
            for(b = a*a ; b < 1000000; b += a){
                ara[b] = 1;
            }
        }
    }
    while(scanf("%lld", &n) == 1 && n != 0){
    l = n;
    for(b = 3; b <= n/2; b += 2){
        if(ara[b] == 0){
            m = n - b;
        if(ara[m] == 0){
                printf("%llu = %llu + %llu\n",l,b,m);
                break;
            }
        }

    }
    if(b > n/2){
        printf("Goldbach's conjecture is wrong.\n");
    }
}
return 0;
}

