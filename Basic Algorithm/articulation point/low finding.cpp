#include<bits/stdc++.h>
using namespace std;

#define mxx 50
vector<int> g[mxx];
vector<int> art;

int tme = 0, root;
int dis[mxx], fin[mxx],vis[mxx], lo[mxx], par[mxx];
int cnt = 0;

void dfs(int u)
{
    tme++;
    dis[u] = lo[u] = tme;
    vis[u] = 1;
    for(int  i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(par[u] == v){
            continue;
        }
        if(vis[v] == 1){
            lo[u] = min(lo[u], dis[v]);
        }

        if(vis[v] == 0){
            if(u == root)
            cnt++;

            par[v] = u;
            dfs(v);
            lo[u] = min(lo[u], lo[v]);
    if(lo[v] >= dis[u] && u != root)
        art.push_back(u);

        }
    }

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

    root = 1;
    dfs(1);
    if(cnt >= 2)
        art.push_back(root);

//    for(int i = 1; i <= n; i++)
//        printf("%d %d\n",dis[i], lo[i]);
if(art.size() == 0)
    cout << "No articulation point\n";
else{
cout <<"Articulation points are:\n";
sort(art.begin(), art.end());
for(int i = 0; i < art.size(); i++)
    printf("%d\n",art[i]);
}
}

