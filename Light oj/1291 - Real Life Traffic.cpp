#include<bits/stdc++.h>
using namespace std;
#define mxx 10005
vector<int> g[mxx], v;

#define inf 1000000

int tme, root;
int com[mxx], dis[mxx],vis[mxx],deg[mxx], lo[mxx], par[mxx], vis2[mxx];
int  ans;

map<pair<int, int> , int > mp;

 int n, m, cnt;
 
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

void dfs2(int u)
{
	vis2[u] = 1;
	com[u] = cnt;
	for(int i = 0; i <(int)g[u].size(); i++){
		int vv = g[u][i];
		if(mp[make_pair(min(u,vv), max(u, vv))] == 1)
		continue;
		
		if(vis2[vv] == 0){
			dfs2(vv);
		}
	}
}

void dfs(int u)
{
	tme++;
  
    vis[u] = 1;
    lo[u] = tme;
    dis[u] = tme;
    
    for(int i = 0; i < (int)g[u].size(); i++){
		int vv = g[u][i];
		if(par[u] == vv)
		continue;
		
		if(vis[vv] == 1){
			lo[u] = min(lo[u], dis[vv]);
		}
		if(vis[vv] == 0){
			par[vv] = u;
			dfs(vv);
		lo[u] = min(lo[u], lo[vv]);
            if(lo[vv] > dis[u])
            {
				mp[make_pair(min(u, vv), max(u, vv))] = 1;
				v.push_back(min(u, vv));
				v.push_back(max(u, vv));
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
        init();
        scanf("%d %d", &n, &m);

        for(int i = 0; i < m; i++)
        {
            int u, w;
            scanf("%d %d", &u, &w);
            g[u].push_back(w);
            g[w].push_back(u);
        }

        ans = 0;
        tme = 0;

        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i);
            }
        }
        
        memset(vis2, 0, sizeof(vis2));
     cnt = 0; 
       
        for(int i = 0; i < n; i++){
			if(vis2[i] == 0){
				cnt++;
				dfs2(i);
			}
		}
       memset(deg, 0, sizeof(deg));
       
        for(int i = 0; i < (int)v.size(); i++){
			deg[com[v[i]]]++;
		}
		
		for(int i = 0; i <= cnt; i++){
			if(deg[i] == 1){
				ans++;
			}
		}
		
		ans = (ans + 1)/2;
        printf("Case %d: %d\n",tc, ans);
        
        for(int i = 0; i <= n; i++)
            g[i].clear();

            mp.clear();
			v.clear();
    }
    return 0;
}
