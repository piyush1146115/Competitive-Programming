#include<bits/stdc++.h>
using namespace std;
#define mxx 200000

vector<int> adj[mxx];

int cycle;
map<int ,int> visit, exist;

void dfs(int u)
{
	visit[u] = 1;
	for(int i = 0; i < adj[u].size(); i++)
	{
		if(visit[adj[u][i]] == 1){
		cycle = 1;
		return;
		}
		else if(visit[adj[u][i]] == 0){
			dfs(adj[u][i]);
		}
	}
	visit[u] = 2;
}
int main()
{
	int n, m;
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
	scanf("%d %d",&ara[i].left, & ara[i].right);
	//mp[ara[i].left]++;
	//mp[ara[i].right]++;
	exist[ara[i].left] = 1;
	exist[ara[i].right] = 1;
	
	adj[ara[i].left].push_back(ara[i].right);
	adj[ara[i].right].push_back(ara[i].left);
	}
	
	int flag = 1;
	
	for(int i = 1; i < m; i++)
	{
		if(exist[i] == 1)
		{
			if(visit[i] == 0)
			dfs(i);
		}
	}
	
	if(flag)
	printf("YES\n");
	else
	printf("NO\n");
}
