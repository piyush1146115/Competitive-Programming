#include<bits/stdc++.h>
using namespace std;
#define mxx 105

int d1[mxx], d2[mxx], vis[mxx];

vector<int> g[mxx];

void bfs(int s)
{
	queue<int> q;
	
	q.push(s);
	d1[s] = 0;
	vis[s] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = 1;
		
		for(int i = 0; i < g[u].size(); i++)
		{
				int v = g[u][i];
				if(vis[v] == 0){
				d1[v] = d1[u] + 1;
				vis[v] = 1;
				q.push(v); 
				}
		}
	}
}


void bfs2(int s)
{
	queue<int> q;
	
	q.push(s);
	d2[s] = 0;
	vis[s] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = 1;
		
		for(int i = 0; i < g[u].size(); i++)
		{
				int v = g[u][i];
				if(vis[v] == 0){
				d2[v] = d2[u] + 1;
				q.push(v);
				vis[v] = 1; 
				}
		}
	}
}

int main()
{
	int test;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		int n, r;
		
		scanf("%d %d",&n, &r);
		
		for(int i = 1; i <= r; i++)
		{
			int x, y;
			scanf("%d %d",&x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		
		int s, d;
		
		scanf("%d %d",&s, &d);
		memset(d1, 0 , sizeof(d1));
		memset(vis, 0, sizeof(vis));
		bfs(s);
		memset(d2, 0 , sizeof(d2));
		memset(vis, 0, sizeof(vis));
		bfs2(d);
		
		int ans = -100214;
		
		for(int i = 0; i <= n; i++){
			int temp = d1[i] + d2[i];
		ans = max(ans, temp);
		}
		
		
		printf("Case %d: %d\n", tc, ans);
		
		for(int i = 0; i <= 101; i++)
		g[i].clear();
	}
	return 0;
}

