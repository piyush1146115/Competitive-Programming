#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
int ara[1005];
long long power(long long b, long long p)
{
    ///b = base .. p = power
    long long ans = 1;

    while(p){
        if(p & 1){
            ans *= b;
        }
        b *= b;
        p = p / 2;
    }
    return ans;
}

void sieve()
{
    int i, j, k;
    prime.push_back(2);

    for(i = 3; i <= 40; i += 2){
            if(ara[i] == 0)
        for(j = i * i; j <= 1000; j += (i * 2)){
            ara[j] = 1;
        }
    }

    for(i = 3; i <= 1000; i += 2)
        if(ara[i] == 0)
        prime.push_back(i);

}
int main()
{
    sieve();
    long long a, b, k, n, i, j, l, sd, ss, sp1, sp2, test, t1, t2;

    scanf("%lld", &test);

    while(test--){
        scanf("%lld %lld %lld", &a, &b, &k);
        sd = ss = 0;
        for(i = a; i <= b; i++){
            if(i % k == 0){
                n = i;
                sp1 = sp2 = 1;
                for(j = 0; prime[j] <= sqrt(n); j++){
                       long long  int c = 0;
                    if(n % prime[j] == 0){
                    while(n % prime[j] == 0){
                        c++;
                        n /= prime[j];
                    }
                    t1 = power(prime[j], c+1);
                    t2 = (t1 - 1)/ (prime[j] - 1);
                    sp1 *= t2;
                    sp2 *= (c + 1);
                    }
                }
                if(n > 1){
                     t1 = n * n;
                    t2 = (t1 - 1)/ (n - 1);
                    sp1 *= t2;
                    sp2 *= 2;
                }
                ss += sp2;
                sd += sp1;
            }
        }
        printf("%lld %lld\n", ss, sd);
    }
    return 0;
}
