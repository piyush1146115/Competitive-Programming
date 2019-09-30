#include<bits/stdc++.h>
using namespace std;
#define mxx 50005

#define gray 1
#define white 2
#define black 3

int d[mxx + 5], f[mxx + 5], sum[mxx] ;
bool vis[mxx + 5];

vector<int> g[mxx + 5];

int dfs(int u)
{
	int cnt = 0;
	vis[u] = 1;
	
	for(int i = 0;i < g[u].size(); i++){
		int v = g[u][i];
		if(vis[v] == 0)
		cnt = 1 + dfs(v);
		
		//vis[v] = 0;
	}
	
	sum[u] = cnt;
	return sum[u];
}

int main()
{
		int n, test;
		
		scanf("%d", &test);
		
		for(int tc = 1 ; tc <= test; tc++)
		{
			scanf("%d", &n);
			
			memset(vis, 0, sizeof(vis));
			memset(sum, 0, sizeof(sum));
			
			for(int i = 0; i < n; i++){
				int u, v;
				scanf("%d %d", &u, &v);	
				g[u].push_back(v);
			}
			
			for(int i = 1; i <= n; i++)
			{
				if(vis[i] == 0 && sum[i] == 0)
				int t = dfs(i);
			}
			
			int maxx = 0, ans;
			for(int i = 1; i <= n; i++)
			if(sum[i] > maxx){
			maxx = sum[i];
			cout << i << " " << sum[i] << endl;
			ans = i;
			}
			
			printf("Case %d: %d\n",tc, ans);
		}
		return 0;
}
