#include<bits/stdc++.h>
using namespace std;
#define mxx 800005
vector<int> g[mxx + 5];
bool vis[mxx + 5];
int dis[mxx + 5], cost[mxx + 5];
void reset()
{
	for(int i = 0 ; i < mxx; i++){
	dis[i] = 0;
	vis[i] = 0;
	g[i].clear();
	}
}
void bfs(int s, int des)
{

vis[s] = 1;
queue<int> q;
q.push(s);
dis[s] = 0;
	while(!q.empty()){
		int u = q.front();
		//vis[u] = 1;
		q.pop();
		for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];

		if(vis[v] == 0){
		dis[v] = dis[u] + 1;
		vis[v] = 1;
		q.push(v);
		if(v == des)
		return;
		}
		}
	}
}

int main()
{
	int n, m, test;

	scanf("%d",&test);

	for(int tc = 1; tc <= test; tc++){
	reset();
	scanf("%d %d",&n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d",&cost[i]);
	}

	for(int i = 0; i < n; i++){
	int u, v;
	scanf("%d %d",&u, &v);
	g[u].push_back(v);
	g[v].push_back(u);
	}
	int s, des;
	scanf("%d %d",&s, &des);
	bfs(s, des);

	printf("Case %d: ",tc);

	if(vis[des] == 0){
	printf("Path not found\n");
	}
	else if(dis[des] > cost[des]){
		printf("Don't travel\n");
	}
	else{
		printf("%d\n", cost[des] - dis[des]);
	}
}
}
