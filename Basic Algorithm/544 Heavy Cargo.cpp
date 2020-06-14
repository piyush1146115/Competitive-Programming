#include<bits/stdc++.h>
using namespace std;
#define mxx 205

int par[mxx], vis[mxx], path[mxx];
int src , des, ans;
map< pair <int, int> , int> wgt;

struct edge
{
    int u, v, w;
    bool operator <(const edge &p)const
    {
        return w > p.w;
    }
};

int findd(int r)
{
    return (par[r] == r) ? r : findd(par[r]);
}

vector<edge> e;
vector<int> g[mxx];

void mst(int n)
{
    sort(e.begin(), e.end());

    for(int i = 1; i <= n; i++)
    {
        par[i] = i;
    }
    int cnt = 0;

    for(int i = 0; i < (int)e.size(); i++)
    {
        int u = findd(e[i].u);
        int v = findd(e[i].v);

        if(u != v)
        {
            par[u] = v;
            g[e[i].u].push_back(e[i].v);
            g[e[i].v].push_back(e[i].u);

            cnt++;
            if(cnt == n - 1)
                break;
        }
    }
    return;
}

void dfs(int u)
{
    vis[u] = 1;
    if(u == des)
        return;

    for(int i = 0; i < g[u].size(); i++)
        if(vis[g[u][i]] == 0)
        {
            path[g[u][i]] = u;
            dfs(g[u][i]);
        }
}


int main()
{
    int  n, m, cnt = 0, cost, tc = 0;

    while(scanf("%d %d", &n, &m) == 2)
    {
        cnt = 0;
        if(n == 0 && m == 0)
            break;

        memset(vis, 0, sizeof(vis));
        memset(path, - 1, sizeof(path));

        map<string, int> mp;

        string a, b;

        while(m--)
        {
            cin >> a >> b >> cost;

            if(mp[a] == 0)
            {
                cnt++;
                mp[a] = cnt;
            }
            if(mp[b] == 0)
            {
                cnt++;
                mp[b] = cnt;
            }
            edge get;
            get.u = mp[a];
            get.v = mp[b];
            wgt[make_pair(get.u, get.v)] = cost;
            wgt[make_pair(get.v, get.u)] = cost;

            get.w = cost;
            e.push_back(get);

//            cout << a << " " << mp[a] << endl;
//            cout << b << " " << mp[b] << endl;
        }

        cin >> a >> b;
        src = mp[a];
        des = mp[b];

        mst(n);
        ans = 9999999;
        dfs(src);

        while(1)
        {
//            cout << des << " " << path[des] << endl;
//            getchar();
            if(des == src)
                break;
            ans = min(wgt[make_pair(des, path[des])], ans);
            des = path[des];
        }

        printf("Scenario #%d\n%d tons\n\n",++tc, ans);
        wgt.clear();
        mp.clear();
        e.clear();
        for(int i = 0; i <= n; i++)
        {
            g[i].clear();

        }
    }
}
