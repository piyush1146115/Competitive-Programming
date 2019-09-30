#include<bits/stdc++.h>
using namespace std;
#define mxx 10005
vector<int> g[mxx];
vector<int> art;
#define inf 10000000

int tme, root;
int dis[mxx],vis[mxx], lo[mxx], par[mxx];
vector< pair <int, int> > ans;

map< pair<int, int>, int> mp;
void init()
{
    for(int i = 0; i < mxx; i++)
    {
        vis[i] = 0;
        dis[i] = 0;
        lo[i] = inf;
        par[i] = 0;
    }
}

void dfs(int u)
{
    tme++;
    dis[u] = tme;
    lo[u] = tme;

    vis[u] = 1;

    for(int  i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if(par[u] == v)
        {
            continue;
        }

        if(vis[v] == 1)
        {
            lo[u] = min(lo[u], dis[v]);
        }

        if(vis[v] == 0)
        {
            par[v] = u;
            dfs(v);
            lo[u] = min(lo[u], lo[v]);

            if(lo[v] > dis[u] && mp[make_pair(u,v)] == 0)
            {
                pair<int, int> p;
                p.first = min(u, v);
                p.second = max(u, v);

                ans.push_back(p);

                mp[make_pair(u,v)] = 1;
                mp[make_pair(v,u)] = 1;
            }

        }
    }
}


int main()
{
    //freopen("input.txt", "r", stdin);
    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {

        int n;
        init();
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
        {
            int u, v, t;

            scanf("%d (%d)", &u, &t);
            while(t--){
            scanf("%d", &v);
            g[u].push_back(v);
            g[v].push_back(u);
            }
        }


       // ans = 0;
        tme = 0;

        for(int i = 0; i <= n; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i);
            }
        }



        printf("Case %d:\n",tc);

        sort(ans.begin(), ans.end());
        printf("%d critical links\n",ans.size());

        for(int i = 0; i < ans.size(); i++)
            printf("%d - %d\n",ans[i].first, ans[i].second);

            mp.clear();
            ans.clear();
        for(int i = 0; i <= n; i++)
            g[i].clear();
    }
    return 0;
}
