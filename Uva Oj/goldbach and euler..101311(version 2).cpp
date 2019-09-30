#include<bits/stdc++.h>
using namespace std;
long long int ara[100000010];

 int main()
{
     long long int n, a, b, m, c;
    long long int i, j, count, dif, flag;

    ara[1] = 1;
    for(i = 4; i <= 100000005; i += 2)
        ara[i] = 1;

    for(i = 3; i <= 10001; i += 2){
        if(ara[i] == 0){
            for(j = i * i; j <= 100000009; j += i << 1){
                ara[j] = 1;
            }
        }
    }

    while(scanf("%lld", &n) == 1)
    {
        flag = 0;
        if(n % 2 != 0){
            if(ara[n - 2] == 0){
            printf("%lld is the sum of 2 and %lld.\n",n, n - 2);
            }
            else{
                printf("%lld is not the sum of two primes!\n",n);
            }
        }
    else{
        for(i = n/2; i < n - 1 ;i++){
            dif = n - i;

            if(dif == i){
                continue;
            }
            if(ara[dif] == 0 && ara[i] == 0){
                    printf("%lld is the sum of %lld and %lld.\n",n, dif, i);
                    flag = 1;
                    break;
            }
        }
        if(flag == 0)
        printf("%lld is not the sum of two primes!\n",n);
    }

    }
    return 0;
}
