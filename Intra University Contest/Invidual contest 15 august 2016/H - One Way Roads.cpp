#include<bits/stdc++.h>
using namespace std;
vector <int> v[105];
int n, vis[105], cost[105][105], ans;
void dfs(int x)
{
    if(vis[x] == 1)
        return;
    vis[x] =1;

    for(int i = 0; i < v[x].size(); i++){
            if(vis[v[x][i]] == 0){
                ans += cost[x][v[x][i]];
        dfs(v[x][i]);
            }
    }
}

int main()
{
    int i, j, total, x, y, m, test, cs = 0;


    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
total = 0;
        for(i = 1; i <= n; i++){
            scanf("%d %d %d", &x, &y, &m);
            v[x].push_back(y);
            v[y].push_back(x);

            cost[y][x] = m;
            cost[x][y] = 0;
            total += m;
        }

        ans = 0;
        memset(vis, 0, sizeof(vis));
        dfs(1);
        int j = v[1][1];
        ans += cost[j][1];
        ans =min(ans, total - ans);
        printf("Case %d: %d\n",++cs,  ans);

        for(i = 0; i <=n ; i++)
            v[i].clear();

    }
    return 0;
}
