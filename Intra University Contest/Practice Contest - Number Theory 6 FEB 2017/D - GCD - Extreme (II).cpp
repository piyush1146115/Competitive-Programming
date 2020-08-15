#include<bits/stdc++.h>
using namespace std;
#define mxx 4000005

bool mark[mxx];
long long phi[mxx], res[mxx];

void sievephi(long long n)
{
    long long i, j;

    //initialization

    for(long long i = 1; i <= n; i++)
        phi[i] = i;

    mark[1] = 1;

    for(long long i = 2; i <= n; i++) {
        if(mark[i] == 0)
        {
            phi[i] = i - 1;

            for(j = i + i; j <= n; j += i) {
                mark[j] = 1;
                phi[j] = phi[j]/i * (i - 1);
            }
        }
    }
}

void gcdextreme(long long n)
{
    for(long long d = 1; d <= n/2; d++)
    {
        for(long long i = 2; i * d <= n; i++)
        {
            long long x = i * d;
            res[x] += d * phi[x/d];
        }
    }

    for(long long i = 2; i <= n; i++)
        res[i] += res[i - 1];

}

int main()
{
    sievephi(4000001);
    gcdextreme(4000001);
    long long n;

    while(scanf("%lld", &n) == 1) {
        if(n == 0)
            break;

        printf("%lld\n",res[n]);
    }
    return 0;
}

