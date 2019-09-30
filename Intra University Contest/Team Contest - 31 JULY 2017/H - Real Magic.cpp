#include<bits/stdc++.h>
using namespace std;
#define mxx 10005
int vis[mxx], vis2[mxx], ans[mxx];
vector<int> g[mxx];
int cnt;
void dfs(int u)
{
	vis[u] = 1;
	cnt++;
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		
		if(vis[v] == 0){
			dfs(v);
		}
	}
}

void dfs2(int u)
{
	ans[u] = cnt;
	vis2[u] = 1;

	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		
		if(vis2[v] == 0){
			dfs2(v);
		}
	}
}


int main()
{
	int test;
	scanf("%d",&test);
	
	for(int tc = 1; tc <= test; tc++){
		int n, m;
		scanf("%d %d",&n, &m);
		
		for(int i = 0; i < m; i++){
			int u, v;
			scanf("%d %d",&u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		memset(vis, 0, sizeof(vis));
		memset(vis2, 0, sizeof(vis2));
		memset(ans, 0, sizeof(ans));
		
		for(int i = 1; i <= n; i++){
			if(vis[i] == 0){
				cnt = -1;
				dfs(i);
				dfs2(i);
			}
		}
		
		printf("Case #%d:\n",tc);
		printf("%d",ans[1]);
		
		for(int i = 2; i <= n; i++){
			printf(" %d",ans[i]);
		}
		
		printf("\n");
		
		for(int i = 0; i <= n; i++)
		g[i].clear();
	}
}
