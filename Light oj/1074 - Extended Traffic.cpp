#include<bits/stdc++.h>
using namespace std;
#define inf 1000000
#define pb push_back
#define mxx 205

vector<int> g[mxx], cost[mxx];
int busy[mxx], dis[mxx], cycle[mxx], reach[mxx];

void dfs(int u)
{
    if(reach[u])
        return;
    reach[u] = 1;

    for(int i = 0; i < (int)g[u].size(); i++){
        if(reach[g[u][i]] == 0)
        dfs(g[u][i]);
    }
}

void bellmanford(int n)
{
    for(int k = 0; k < n; k++)
    {
        int done = 1;
        for(int u = 1; u <= n; u++)
        {
            for(int i = 0; i < (int)g[u].size(); i++)
            {
                int v = g[u][i];
                int uv = cost[u][i];
                if(dis[u] + uv < dis[v])
                {
                    done = 0;
                    dis[v] = dis[u] + uv;
                }
            }
        }
        if(done)
            break;
    }
}

int main()
{
    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {
        int n;
        memset(cycle, 0, sizeof(cycle));
        memset(reach, 0, sizeof(reach));

        scanf("%d", &n);

        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &busy[i]);
        }
        int m;
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d %d",&u, &v);
            g[u].pb(v);
            int dif = busy[v] - busy[u];
            cost[u].pb(dif * dif * dif);
        }

        for(int i = 0; i <= n; i++)
        {
            dis[i] = inf;
        }
        dis[1] = 0;
        dfs(1);
        bellmanford(n);
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", tc);
        while(q--)
        {
            int u;
            scanf("%d", &u);

            if(reach[u] == 0 ||  dis[u] < 3 || cycle[u] == 1 )
                printf("?\n");
            else
                printf("%d\n",dis[u]);
        }

        for(int i = 0; i <= n; i++)
        {
            cost[i].clear();
            g[i].clear();
        }
    }
}
