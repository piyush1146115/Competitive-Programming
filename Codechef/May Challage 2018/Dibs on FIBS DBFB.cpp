#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define MOD 1000000007
#define ll long long
ll a[MAX], b[MAX];
ll fib[MAX];

int main()
{
    ll test;
    scanf("%lld", &test);

    while(test--)
    {
        ll m, n;

        scanf("%lld %lld",&m, &n);

        for(int i = 0; i < m; i++)
        {
            scanf("%lld", &a[i]);
        }

        for(int i = 0; i < m; i++)
        {
            scanf("%lld", &b[i]);
        }

        fib[1] = 0ll;

        for(int i = 0; i < m; i++)
        {
            fib[1] += ((a[i]*m) % MOD);
            fib[1] %= MOD;
        }

        fib[2] = 0ll;

        for(int i = 0; i < m; i++)
        {
            fib[2] += ((b[i] * m) % MOD);
            fib[2] %= MOD;
        }

        for(int k = 3; k <= n; k++)
        {
            fib[k] = ((fib[k -1] % MOD) + (fib[k -2] % MOD)) % MOD;
        }

        printf("%lld\n",fib[n] % MOD);

    }

}
