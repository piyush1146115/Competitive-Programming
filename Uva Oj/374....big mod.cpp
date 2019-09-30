#include<bits/stdc++.h>
using namespace std;

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
    long long b, p , m;

     while(scanf("%lld %lld %lld", &b, &p, &m) == 3){
        printf("%lld\n", f(b, p, m));
     }

     return 0;
}
