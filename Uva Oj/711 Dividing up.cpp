#include<bits/stdc++.h>
using namespace std;

int dp[7][60005];
int coin[] = {1, 2 , 3, 4, 5 , 6};
int ara[8];


int fun(int pos, int sum)
{
    if(sum < 0)
        return 0;

    if(sum == 0)
        return 1;

    if(pos == 6){
        return 0;
    }

    if(dp[pos][sum] != -1)
        return dp[pos][sum];

        int p1 = 0, p2 = 0;

    for(int i = 0 ; i < ara[pos]; i++){
        p1 = fun(pos + 1, sum - (coin[pos] * (i+ 1)));

        if(p1 == 1)
            break;
    }

    if(p1 == 0)
    p2 = fun(pos + 1, sum);

    return dp[pos][sum] = p1 | p2;
}


int main()
{

    int n, m;
    int tc = 0;

    while(scanf("%d %d %d %d %d %d",&ara[0], &ara[1], &ara[2], &ara[3], &ara[4], &ara[5]) == 6){

        if(ara[0] == 0 && ara[1] == 0 && ara[2] == 0 && ara[3] == 0 && ara[4] == 0 && ara[5] == 0)
            break;

        m  = ara[0]  + ara[1] * 2 + ara[2] * 3 + ara[3] * 4 + ara[4] * 5 + ara[5] * 6;

        if(m % 2 != 0){
            printf("Collection #%d:\nCan't be divided.\n\n",++tc);
        }
        else{
        memset(dp, -1, sizeof(dp));
        int ans = fun(0, m/2);

        if(ans == 0)
        printf("Collection #%d:\nCan't be divided.\n\n",++tc);
        else
        printf("Collection #%d:\nCan be divided.\n\n",++tc);
        }
    }
    return 0;
}
