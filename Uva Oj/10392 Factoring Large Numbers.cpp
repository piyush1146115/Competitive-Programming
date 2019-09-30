#include<bits/stdc++.h>
using namespace std;
vector<long long> prime;
bool chk[100000000];
void sieve()
{
    long long i, j, k;
    prime.push_back(2);

    for(i = 3; i <= 10000; i+= 2){
            if(!chk[i]){
        for(j = i * i ; j <= 100000000; j += (i << 1)){
            chk[j] = 1;
            }
        }
    }

    for(i = 3; i <= 100000000; i += 2)
    if(!chk[i])
        prime.push_back(i);
}
int main()
{
    sieve();
    long long n, i, j, k;

    while(scanf("%lld" ,&n) == 1 && n >= 0){

        for(i = 0; prime[i] <= sqrt(n); i++){
            while(n % prime[i] == 0){
                n /= prime[i];
                printf("    %lld\n",prime[i]);
            }
        }
        if(n > 1){
            printf("    %lld\n", n);
        }
        printf("\n");
    }
    return 0;
}
