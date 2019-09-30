#include<bits/stdc++.h>
using namespace std;
vector <int> prime;
int ara[32005];
void sieve()
{
    int i, j, k;

    prime.push_back(2);

    for(i = 3; i <= 200; i += 2){
        if(ara[i] == 0){
            for(j = i * i; j <= 32000; j += (i + i))
                ara[j] = 1;
        }
    }

    for(i = 3; i <= 32000; i+= 2)
        if(ara[i] == 0)
        prime.push_back(i);
}

bool isPrime(long long n)
{
    int i, j;
    j = sqrt(n);
    for(i = 0; prime[i] <= j;i++ ){
        if(n % prime[i] == 0){
            return false;
        }
    }
    return true;
}

long long f(long long n, long long p, long long mod)
{
    long long ret;

    if(p == 0){
        return 1;
    }
    if(p % 2 == 0){
        ret = f(n, p/2, mod);
        return ((ret % mod) * (ret % mod)) % mod;
    }
    else{
        return ((n % mod) * (f(n, p - 1, mod) % mod)) % mod;
    }
}


int main()
{
    sieve();

    long long  p, a, i, j;

    while(scanf("%lld %lld",&p, &a) == 2){
        if(p == 0 && a == 0)
            break;


            if(!(isPrime(p))){
            i = f(a, p, p);
            //printf("%lld\n", i);
            if(i == a)
                printf("yes\n");
            else
                printf("no\n");
    }
    else
        printf("no\n");

    }
    return 0;
}
