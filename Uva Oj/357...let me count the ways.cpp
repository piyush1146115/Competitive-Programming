#include<bits/stdc++.h>
using namespace std;
#define ll long long

int coin[] = {50, 25, 10, 5, 1};///value of the coins available
int make;

ll dp[6][30005];

ll call(int i, int amount)
{
    if(i >= 5){ ///All coins have been taken
        if(amount == 0)
            return 1;

        else{
            return 0;
        }
    }
    if(amount < 0)
        return 0;

    if(dp[i][amount] != -1)
        return dp[i][amount];

    ll ret1 = 0, ret2 = 0;

    if(amount - coin[i] >= 0)
        ret1 = call(i, amount - coin[i]);

    ret2 = call(i + 1, amount);///don't take coin

    dp[i][amount] = ret1 + ret2; ///storing and returning

    return dp[i][amount];
}

int main()
{
    while(cin >> make){
    memset(dp, -1, sizeof(dp));

       ll res = call(0, make);
    if(res <= 1)
            printf("There is only %lld way to produce %d cents change.\n",res, make);
       else
        printf("There are %lld ways to produce %d cents change.\n", res, make);

    }
    return 0;
}

