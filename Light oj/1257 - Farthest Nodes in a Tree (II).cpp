#include<bits/stdc++.h>
using namespace std;
#define mxx 30005

int vis[mxx], ans[mxx];
vector<int> g[mxx], cost[mxx];

int leaf, far, mx;

void dfs(int u, int sum)
{
	vis[u] = 1;
	
	if(sum > mx){
		leaf = u;
		mx = sum;
	}
	
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(vis[v] == 0){
			dfs(v, sum + cost[u][i]);
		}
	}
}

void dfs2(int u, int sum)
{
	vis[u] = 1;
	
	if(sum >= mx){
		far = u;
		mx = sum;
	}
	
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(vis[v] == 0){
			dfs2(v, sum + cost[u][i]);
		}
	}
}

void dfs3(int u, int sum)
{
	vis[u] = 1;
	
	ans[u] = max(ans[u], max(sum, mx - sum));
	
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(vis[v] == 0){
			dfs3(v, sum + cost[u][i]);
		}
	}
}

int main()
{
	int test;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		int n;
		scanf("%d", &n);
		for(int i = 1; i < n; i++){
			int u, v, w;
			scanf("%d %d %d",&u, &v, &w);
			g[u].push_back(v);
			g[v].push_back(u);
			cost[u].push_back(w);
			cost[v].push_back(w);
		}
		memset(ans, 0, sizeof(ans));
		memset(vis, 0, sizeof(vis));
		mx = -1;
		dfs(1, 0);
		memset(vis, 0, sizeof(vis));
		dfs2(leaf, 0);
		memset(vis, 0, sizeof(vis));
		dfs3(far, 0);
		
		memset(vis, 0, sizeof(vis));
		dfs3(leaf, 0);
		
		printf("Case %d:\n",tc);
		for(int i = 0; i < n; i++){
			printf("%d\n",ans[i]);
		}
		
		for(int i = 0; i <= n; i++){
		g[i].clear();
		cost[i].clear();
	}
	
	}
}
