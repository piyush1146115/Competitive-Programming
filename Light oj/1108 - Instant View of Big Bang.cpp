#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int u, v, w;
    edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};

int cycle[1005], dist[1005], vis[1005], vis2[1005];
vector<edge> E;
vector<int> g[1005];

vector<int> ans;
int flag;

void dfs(int u)
{
    if(cycle[u])
    {
        flag = 1;
        return;
    }
    //ans.push_back(u);

    vis[u]  = 1;
    for(int i = 0; i < (int)g[u].size(); i++)
    {
        int v = g[u][i];

        if(cycle[v] == 1 || flag == 1)
        {
            flag = 1;
            return;
        }
        else if(vis[v] == 0)
        {
            dfs(v);
        }
    }
}

void dfs2(int u)
{
    if(vis2[u])
        return;
    ans.push_back(u);

    vis2[u]  = 1;
    for(int i = 0; i < (int)g[u].size(); i++)
    {
        int v = g[u][i];
        if(vis2[v] == 0)
        {
            dfs2(v);
        }
    }
}

void bellmanford(int s, int n)
{
    for(int i = 1; i <= n; i++)
    {
        dist[i] = 1000000000;
    }

    dist[s] = 0;

    for(int i = 1; i < n; i++)
    {
        int done = 1;
        for(int j = 0; j < (int)E.size(); j++)
        {
            edge e = E[j];
            if(dist[e.v] > dist[e.u] + e.w)
            {
                done = 0;
                dist[e.v] = dist[e.u] + e.w;
            }
        }
        if(done)
            break;
    }
    for(int j = 0; j < (int)E.size(); j++)
    {
        edge e = E[j];
        if(dist[e.v] > dist[e.u] + e.w)
        {
            cycle[e.u] = 1;
            cycle[e.v] = 1;
            //dfs(e.u);
            dist[e.v] = dist[e.u] + e.w;
        }
    }
}

int main()
{
    int test;
    scanf("%d", &test);
    for(int tc = 1; tc <= test; tc++)
    {
        memset(cycle, 0, sizeof(cycle));
        memset(vis2, 0, sizeof(vis2));
        memset(vis, 0, sizeof(vis));
        int n, m;
        scanf("%d %d", &n, &m);

        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            E.push_back(edge(u, v, w));
            g[u].push_back(v);
            //        g[v].push_back(u);
        }
        bellmanford(0, n);
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                flag = 0;
                dfs(i);

                if(flag && vis2[i] == 0)
                {
                    dfs2(i);
                }
            }
        }
        sort(ans.begin(), ans.end());
        printf("Case %d:",tc);

        if(ans.size() == 0)
            printf(" Impossible\n");
        else
        {
//            printf("%d", ans[0]);
            for(int i = 0; i < (int)ans.size(); i++)
                printf(" %d",ans[i]);

            printf("\n");
        }
        ans.clear();
        E.clear();
        for(int i = 0; i <= n; i++)
        {
            g[i].clear();
        }
    }
}
