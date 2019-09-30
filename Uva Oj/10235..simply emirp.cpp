#include<stdio.h>
long long int prime[1000000];
int main()
{
    long long int a, b, c, i, j, k, num, n;

    prime[1] = 1;

    for(a = 4; a <= 1000000; a += 2)
        prime[a] = 1;

    for(b = 3; b <= 1000; b += 2){
        if(prime[b] == 0){
            for(c = b * b; c <= 1000000; c += 2 * b){
                prime[c] = 1;
            }
        }
    }

    while(scanf("%lld", &n) == 1){
        if(prime[n] == 0){
            k = n;
            num = 0;
            while(k >= 1){
                i = k % 10;
                num = num*10 + i;
                k = k/10;
            }
            //printf("%lld\n",num);
            if(n == num){
                printf("%lld is prime.\n",n);
            }
            else if(prime[num] == 0){
                printf("%lld is emirp.\n",n);
            }
            else
                printf("%lld is prime.\n",n);
        }
        else{
            printf("%lld is not prime.\n",n);
        }
    }
    return 0;
}
