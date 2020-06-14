#include<bits/stdc++.h>
using namespace std;

#define black 1
#define white 2
#define gray 3
#define mxx 1000
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second

vector<pii> forward_edge, back_edge, cross_edge, tree_edge;

int color[mxx];
int tme ;
int d[mxx], f[mxx];
int par[mxx];
vector<int> g[mxx];

void dfs(int u)
{
	color[u] = gray;
	tme = tme + 1;
	d[u] = tme;
	
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(color[v] == black)
		{
			if(d[u] < d[v]){
				forward_edge.push_back(mp(u, v));
			}
			else{
				cross_edge.push_back(mp(u, v));
			}
		}
		if(color[v] == gray)
		back_edge.push_back(mp(u, v));
		
		if(color[v] == white)
		{
			par[v] = u;
			tree_edge.push_back(mp(u, v));
			dfs(v);
		}
	}
	color[u] = black;
	tme = tme + 1;
	f[u] = tme;
}

int main()
{
	int n, m;
	
	scanf("%d %d", &n, &m);
	
	
	for(int i = 1; i <= n; i++)
	{
		color[i] = white;	
	}
	
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
	//	g[v].push_back(u);
	}
	
	tme = 0;
	
	for(int i = 1; i <= n; i++){
		if(color[i] == white)
		{
			dfs(i);
		}
	}
	
	printf("Forward Edges......\n");
	for(int i = 0;  i < forward_edge.size(); i++){
		printf("%d %d\n",forward_edge[i].ff, forward_edge[i].ss);
	}
	
	printf("Back Edges......\n");
	for(int i = 0; i < back_edge.size(); i++)
	{
		printf("%d %d\n",back_edge[i].ff, back_edge[i].ss);
	}
	
	printf("Tree Edges......\n");
	for(int i = 0 ; i < tree_edge.size(); i++)
	{
		printf("%d %d\n",tree_edge[i].ff, tree_edge[i].ss);
	}
	
	printf("Cross Edges......\n");
	for(int i = 0 ; i < cross_edge.size(); i++)
	{
		printf("%d %d\n",cross_edge[i].ff, cross_edge[i].ss);
	}
	
	
	forward_edge.clear();
	tree_edge.clear();
	back_edge.clear();
	cross_edge.clear();
	
}
