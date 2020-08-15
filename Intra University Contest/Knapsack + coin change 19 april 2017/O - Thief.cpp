#include<bits/stdc++.h>
using namespace std;
#define mxx 105
long long n, W;
long long p[mxx], c[mxx], w[mxx];
long long dp[105][10005];

long long knapsack(long long  pos, long long weight)
{
    if(pos > n)
    {
        return 0;
    }
    if(dp[pos][weight] != -1)
        return dp[pos][weight];

    long long int p1 = 0, p2 = 0, p3 = 0;

    if(weight + w[pos] <= W){
        p2 = p[pos] + knapsack(pos, w[pos] + weight);
        p1 = p[pos] + knapsack(pos + 1, w[pos] + weight);
    }

        p3 = knapsack(pos + 1, weight);

        dp[pos][weight] = max(p1, max(p2, p3));

        return dp[pos][weight];
}

int main()
{
    long long int test;

    scanf("%lld", &test);

    for(long long int tc = 1; tc <= test; tc++){
        scanf("%lld %lld", &n, &W);

        for(int i = 1; i <= n; i++)
            scanf("%lld %lld %lld", &p[i], &c[i], &w[i]);

        long long int taken = 0;

        for(int i = 1; i <= n; i++)
            taken += (c[i] * w[i]);

        printf("Case %lld: ",tc);

        if(taken > W){
            printf("Impossible\n");
        }
        else{
                memset(dp, -1, sizeof(dp));
           long long int ans = knapsack(1, taken);
            printf("%lld\n",ans);
        }
    }
}
