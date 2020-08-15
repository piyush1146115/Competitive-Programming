#include<stdio.h>
unsigned long long ara[10000005];
int main()
{
    unsigned long long int n, a, b,m,l,sqr, c;


    for(a = 4; a <= 100000000; a += 2)
        ara[a] = 1;


    for(a = 3; a <= 10000; a += 2 )
    {
        if(ara[a] == 0)
        {
            for(b = a*a ; b <= 100000000; b += 2*a)
            {
                ara[b] = 1;
            }
        }
    }


    while(scanf("%llu", &n) == 1)
    {

        for( b = n/2 ; b >= 2; b--)
        {
              if(ara[b] == 0)
            {
                    m = n - b;
                    if(ara[m] == 0){
                            if(m == b){
                                continue;
                            }

                        printf("%llu is the sum of %llu and %llu.\n",n,b,m);
                        break;
                        }
                    }
                }
        if(b < 2)
            {
            printf("%llu is not the sum of two primes!\n",n);
            }
    }


    return 0;
    }
