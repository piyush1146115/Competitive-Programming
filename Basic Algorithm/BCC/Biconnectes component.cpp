#include<bits/stdc++.h>
using namespace std;
#define mxx 10005
vector<int> g[mxx], ans[mxx];
vector<int> art;
#define inf 1000000
#define mkp make_pair
#define pii pair<int, int>

int tme, mark;
int dis[mxx],vis[mxx], lo[mxx], par[mxx];
stack<pii> st;

map<int, int> mp;

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
    int cnt = 0;

    for(int  i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if(par[u] == v)
        {
            continue;
        }
        if(vis[v] == 1 && dis[v]<lo[u])
        {
            lo[u] = min(lo[u], dis[v]);
            st.push(mkp(u, v));
        }

        if(vis[v] == 0)
        {

            st.push(mkp(u, v));
            cnt++;
            par[v] = u;
            dfs(v);
            lo[u] = min(lo[u], lo[v]);

            if(lo[v] >= dis[u] && par[u] != 0 && mp[u] == 0)
            {
                mark++;
                pii t = st.top();
                st.pop();
                ans[mark].push_back(t.first);
                ans[mark].push_back(t.second);
                //mp[t.second] = 1;
               // mp[u] = 1;
                while((t.first != u || t.second != v) && (t.first != v || t.second != u)){
                 t = st.top();
                st.pop();
                ans[mark].push_back(t.first);
                ans[mark].push_back(t.second);
                //mp[t.second] = 1;
                //mp[t.first] = 1;
                }
            }
             if(par[u] == 0 && cnt > 1 && mp[u] == 0)
            {
            mark++;
              pii t = st.top();
                st.pop();
                ans[mark].push_back(t.first);
                ans[mark].push_back(t.second);
                //mp[t.second] = 1;
                //mp[u] = 1;

                while((t.first != u || t.second != v) && (t.first != v || t.second != u)){
                 t = st.top();
                st.pop();
                ans[mark].push_back(t.first);
                ans[mark].push_back(t.second);
                //mp[t.second] = 1;
                //mp[t.first] = 1;
                }
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

        int n, m;
        init();
        scanf("%d %d", &n, &m);

        for(int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        mark = 0;
        tme = 0;

        for(int i = 1; i <= n; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i);
            }
        }

        if(!st.empty()){
            mark++;
            while(!st.empty()){
            pii t = st.top();
            st.pop();
            ans[mark].push_back(t.first);
            ans[mark].push_back(t.second);
            }
        }

        for(int i = 1; i <= mark; i++){
                printf("Biconnected Components Set #%d:\n",i);
            set<int> ss;
            for(int j = 0; j < ans[i].size(); j++){
               // printf("%d ", ans[i][j]);
               ss.insert(ans[i][j]);
            }

            set<int> :: iterator it;
             for(it = ss.begin(); it != ss.end(); it++){
                cout <<*(it) << " ";
             }

            printf("\n");
        }

        for(int i = 0; i <= n; i++){
            g[i].clear();
            ans[i].clear();
        }

            mp.clear();
    }
    return 0;
}
