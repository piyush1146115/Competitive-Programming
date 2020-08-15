#include<bits/stdc++.h>
using namespace std;

long long f(long long p, long long mod)
{
    long long ret;

    if(p == 0){
        return 1;
    }
    if(p % 2 == 0){
        ret = f(p/2, mod);
        return ((ret % mod) * (ret % mod)) % mod;
    }
    else{
        return ((10 % mod) * (f(p - 1, mod) % mod)) % mod;
    }
}

int main()
{
    long long n, i, sum, j;

    while(scanf("%lld", &n) == 1){
        j = 1;
        sum = 0;
        i = 0;
            while(j != 0){
            sum += f(i, n);
            j = sum % n;
           // printf("%lld %lld\n",sum, j);
            i++;
            }
        printf("%lld\n", i);
    }

     return 0;
}
