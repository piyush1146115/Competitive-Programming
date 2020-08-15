#include<bits/stdc++.h>
using namespace std;

int dp[6][7500];
int coin[] = {50, 25, 10, 5, 1};

int fun(int pos, int value)
{
    if(value == 0)
        return 1;
    if(value < 0)
        return 0;
    if(pos >= 5)
        return 0;

    if(dp[pos][value] != -1)
        return dp[pos][value];

    int p1 = 0, p2 = 0;

    p1 = fun(pos, value - coin[pos]);
    p2 = fun(pos + 1, value);

    dp[pos][value] = p1 + p2;
    return dp[pos][value];
}

int main()
{
    int n;
    memset(dp, -1, sizeof(dp));

    while(scanf("%d", &n) == 1){
        printf("%d\n",fun(0, n));
    }
    return 0;
}
