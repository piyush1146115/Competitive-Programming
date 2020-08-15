#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int ara[33005];
vector <int> prime;
int main()
{
    long long int i, j, a, factor, sum, n;
    double temp;

    for(i = 4; i <= 33000; i += 2){
        ara[i] = 1;
    }

    for(i = 3; i <= 183; i += 2){
        if(ara[i] == 0){
            for(j = i * i; j <= 33000; j += i * 2){
                ara[j] = 1;
            }
        }
    }
   prime.pb(2);

    for(i = 3; i <= 33000; i += 2){
        if(ara[i] == 0){
            prime.pb(i);
        }
    }

    while(scanf("%lld", &n) == 1 && n != 0){
    a = n;

    sum = 1;

    for(i = 0; prime[i] <= sqrt(a); i++){
                factor = 0;

            if(a % prime[i] == 0){

            while(a % prime[i] == 0){
                factor++;
                a = a / prime[i];
            }

            temp = pow(prime[i], factor - 1);
            sum *= ((prime[i] - 1)* temp);
          }
    }
    if(a > 1){
        sum = sum * (a - 1);
    }
    if(n < 0){
        printf("%lld\n", n);
    }
    if(n == 1){
        printf("0\n");
    }
    else{
    printf("%lld\n", sum);
    }

    }
    return 0;
}
