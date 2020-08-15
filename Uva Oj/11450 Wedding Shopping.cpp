#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v[105];
int dp[25][205];

int fun(int state, int sum)
{
    if(sum > n)
        return 0;

    if(state == m){
        return sum;
    }

    if(dp[state][sum] != -1)
        return dp[state][sum];

    int p = 0;
    for(int i = 0; i < v[state].size(); i++){
        p = max(p, fun(state + 1, v[state][i] + sum));
    }

    return dp[state][sum] = p;
}

int main()
{
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &m);
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < m; i++){
            int k, j;
            scanf("%d", &k);
            //for(int i = 0;i < k; i++){
              while(k--){
                scanf("%d", &j);
                v[i].push_back(j);
              }
        }

        int ans = fun(0, 0);

        if(ans == 0)
            printf("no solution\n");
        else
            printf("%d\n",ans);

        for(int i = 0; i <= m;i++)
            v[i].clear();
    }
    return 0;
}
