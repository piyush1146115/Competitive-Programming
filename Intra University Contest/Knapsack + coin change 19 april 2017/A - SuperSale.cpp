#include<bits/stdc++.h>
using namespace std;
int MX, n;
int dp[1005][35];
int wgt[1005], price[1005];

int knapsack(int pos, int w)
{
    if(pos > n)
        return 0;
   // cout << pos << " " << w << endl;
   // getchar();
    if(dp[pos][w] != -1){
        return dp[pos][w];
    }

    int p1 = 0, p2 = 0;

    if(w + wgt[pos] <= MX)
    p1 = price[pos] + knapsack(pos + 1, w + wgt[pos]);

    p2 = knapsack(pos + 1, w);

    dp[pos][w] = max(p1, p2);
    return dp[pos][w];
}

int main()
{
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);

        for(int i = 1; i <= n; i++){
            scanf("%d %d",&price[i], &wgt[i]);
        }
        int g;
        int sum = 0;
        scanf("%d", &g);

        for(int i = 0; i < g; i++){
            scanf("%d", &MX);
            memset(dp, -1, sizeof(dp));
            sum += knapsack(1, 0);
        }
        printf("%d\n",sum);
    }
    return 0;
}
