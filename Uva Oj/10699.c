#include<stdio.h>
#include<math.h>
long long int ara[1000000];
long long int prime[1000000];
int main()
{
    long long int a, b, n, i, j, k;
    int count;
    ara[1] = 1;
    /*for(i = 4; i <= 1000000;i += 2)
        ara[i] = 1;
*/
    for(i = 3; i <= 1000;i += 2){
        if(ara[i] == 0){
            for(j = i*i; j <= 1000000;j += i*2){
                ara[j] = 1;
            }
        }
    }
    prime[0] = 2;
    j = 1;
for(i = 3; i <= 1000000; i+= 2){
    if(ara[i] == 0){
        prime[j] = i;
        j++;
    }
}

    while(scanf("%lld",&n) == 1 && n != 0){
        /*b = sqrt(n);
        }
        else{
            b = n;
        }*/
        count = 0;
        for(k = 0; prime[k] <= n; k++){
            if(n % prime[k] == 0){
                count++;
            }
          }

        printf("%lld : %d\n",n,count);
    }
    return 0;
}
