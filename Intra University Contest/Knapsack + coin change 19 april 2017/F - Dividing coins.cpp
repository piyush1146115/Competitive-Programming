#include<bits/stdc++.h>
using namespace std;
int total;
int dp[105][50005];
int coin[105], m;

int fun(int pos, int amount)
{
    if(pos > m)
    {
        int v = total - amount;
        //cout << pos << " " << v << " " << amount << endl;
       // getchar();
        return abs(v - amount);
    }

    if(dp[pos][amount] != -1)
        return dp[pos][amount];

    int p1 = fun(pos + 1, amount + coin[pos]);
    int p2 = fun(pos + 1, amount);

    dp[pos][amount] = min(p1, p2);
    return dp[pos][amount];
}

int main()
{
    int test;
    scanf("%d", &test);

    for(int tc =1; tc <= test; tc++){
        scanf("%d",&m);
        total = 0;

        for(int i = 1; i <= m; i++){
            scanf("%d", &coin[i]);
        total += coin[i];
        }

        int ans = fun(1, 0);
        memset(dp, -1, sizeof(dp));

        printf("%d\n",ans);
    }
    return 0;
}
