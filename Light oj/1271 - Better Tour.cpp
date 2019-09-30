#include<bits/stdc++.h>
using namespace std;
#define mxx 50005
vector<int> g[mxx];
int ara[mxx], pa[mxx], vis[mxx];
int n;

void bfs(int st)
{
	vis[st] = 1;
	queue<int> q;
	q.push(st);
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(int i = 0; i < (int)g[u].size(); i++){
			int v = g[u][i];
			if(vis[v] == 0){
				pa[v] = u;
				vis[v] = 1;
				if(v == ara[n - 1])
				return;
				q.push(v);
			}
		}
	}
	
	return;
}


int main()
{
	int test;
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		int mx = -1;
		
		scanf("%d",&n);
		
		for(int i = 0; i < n; i++){
		scanf("%d", &ara[i]);
		mx = max(mx, ara[i]);
	}
		
		for(int i = 0; i < n - 1; i++){
			g[ara[i]].push_back(ara[i + 1]);
			g[ara[i + 1]].push_back(ara[i]);
		} 
		
		for(int i = 0; i <= mx; i++)
		sort(g[i].begin(), g[i].end());
		
		memset(vis, 0, sizeof(vis));
		
		bfs(ara[0]);
		
		vector<int> ans;
		
		ans.push_back(ara[n - 1]);
		int p = ara[n - 1];
		
		while(p != ara[0]){
			p = pa[p];
			ans.push_back(p);
		}
		
		reverse(ans.begin(), ans.end());
		
		printf("Case %d:\n",tc);
		printf("%d",ans[0]);
		
		for(int i = 1; i < (int)ans.size(); i++){
			printf(" %d",ans[i]);
		}
		
		printf("\n");
		
		ans.clear();
		
		for(int i = 0; i <= mx; i++)
		g[i].clear();
	}
}
