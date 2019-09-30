#include<bits/stdc++.h>
using namespace std;
#define Max_N 1002
#define Max_W 32
int n;
int dp[Max_N + 1][Max_W + 1];
int weight[Max_N + 1];
int cost[Max_N + 1];
int cap;

int knapsack(int i, int w)
{
    if(i == n + 1)
        return 0;
    if(dp[i][w] != -1){
        return dp[i][w];
    }

    int profit1 = 0, profit2 = 0;

    if(w + weight[i] <= cap)
        profit1 = cost[i] + knapsack(i + 1, w + weight[i]);

    profit2 = knapsack(i + 1, w);

    dp[i][w] = max(profit1, profit2);

    return dp[i][w];
}

int main()
{
    int test, i, j, g;
    long long int sum;

    scanf("%d", &test);

    while(test--){
            sum = 0;

        scanf("%d", &n);

        for(i = 1; i <= n; i++){
        scanf("%d %d",&cost[i], &weight[i]);
        }

        scanf("%d", &g);

        for( i = 1; i <= g; i++){
            memset(dp, -1, sizeof(dp));
            scanf("%d", &cap);
            sum += knapsack(1, 0);
        }

        printf("%lld\n", sum);
    }
    return 0;
}
