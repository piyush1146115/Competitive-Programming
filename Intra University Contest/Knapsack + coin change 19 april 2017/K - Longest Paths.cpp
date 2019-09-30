#include<bits/stdc++.h>
using namespace std;
#define mxx 105

vector<int> g[mxx];
int dis[mxx], n;
int dp[mxx][mxx];

int fun(int pos, int sum)
{
    dis[pos] = max(dis[pos], sum);
    if(g[pos].size() == 0)
        return sum;


    if(dp[pos][sum] != -1)
        return dp[pos][sum];

    int p = 0;

    for(int i = 0; i < g[pos].size(); i++)
        p = max(p, fun(g[pos][i], sum + 1));

    dp[pos][sum] = p;

    return p;
}

int main()
{
    int tc = 0;
    while(scanf("%d", &n) == 1){
        if(n == 0)
            break;

        int s, u, v;

        scanf("%d", &s);
        memset(dis, 0, sizeof(dis));
        memset(dp, -1, sizeof(dp));

        while(scanf("%d %d",&u, &v) == 2){
            if(u == 0 && v == 0)
                break;
            g[u].push_back(v);
        }

        int ans = fun(s, 0);
        int node;

        for(int i = 0; i <= n; i++){
            if(dis[i] == ans){
                node = i;
                break;
            }
   // cout << dis[i] << endl;
        }


        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++tc, s,ans, node);

        for(int i = 0; i <= n; i++)
            g[i].clear();
    }
    return 0;
}
