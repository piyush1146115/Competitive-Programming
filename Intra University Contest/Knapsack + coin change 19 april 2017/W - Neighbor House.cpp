
#include<bits/stdc++.h>
using namespace std;
#define mxx 9999999
int m;
int ara[22][5], dp[22][5][20005];
int fun(int level, int pos, int sum)
{
    if(level > m){
        return sum;
    }
    if(dp[level][pos][sum] != -1){
        return dp[level][pos][sum];
    }

    int p1 = mxx, p2 = mxx;

    if(pos == 2){
            p1 = fun(level + 1, pos + 1, sum + ara[level][pos]);
            p2 = fun(level + 1, pos - 1, sum + ara[level][pos]);
    }
    else if(pos == 1){
        p1 = fun(level + 1, pos + 1, sum + ara[level][pos]);
        p2 = fun(level + 1, pos + 2, sum + ara[level][pos]);
    }
    else{
        p1 = fun(level + 1, pos - 1, sum + ara[level][pos]);
        p2 = fun(level + 1, pos - 2, sum + ara[level][pos]);
    }

    dp[level][pos][sum] = min(p1, p2);

    return dp[level][pos][sum];
}


int main()
{
 int test;

 scanf("%d", &test);

 for(int tc = 1; tc <= test; tc++){
    scanf("%d", &m);
    memset(dp, -1, sizeof(dp));

    for(int i = 1; i <= m; i++){
        scanf("%d %d %d",&ara[i][1], &ara[i][2], &ara[i][3]);
    }
    int res = mxx;

     res = min(res,fun(1, 1, 0));
     res = min(res,fun(1, 2, 0));
     res = min(res,fun(1, 3, 0));

    printf("Case %d: %d\n",tc, res);
 }
 return 0;
}
