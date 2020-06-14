#include<bits/stdc++.h>
using namespace std;
#define mxx 50
vector<int> g[mxx];
int tme = 0;
int dis[mxx], fin[mxx],vis[mxx];

void dfs(int u)
{
    tme++;
    dis[u] = tme;
    vis[u] = 1;

    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(vis[v] == 0){
            dfs(v);
        }
    }
    tme++;
    fin[u] = tme;
}
int main()
{
    freopen("input.txt", "r", stdin);

    int n,m;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    for(int i = 1; i <= n; i++)
        printf("%d %d\n",dis[i], fin[i]);
}
