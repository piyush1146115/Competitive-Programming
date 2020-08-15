#include<bits/stdc++.h>
using namespace std;
#define mxx 20005
int color[mxx], flag[mxx];
vector<int> g[mxx];
int p1, p2;

void dfs(int u)
{
	if(color[u] == 1)
	p1++;
	if(color[u] == 2)
	p2++;
	
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(color[v] == 0){
			if(color[u] == 1){
				color[v] = 2;
				dfs(v);
			}
			else{
				color[v] = 1;
				dfs(v);
			}
		}
	}
	return;
}

int main()
{
	int test;
	
	scanf("%d",&test);
	
	for(int tc = 1; tc <= test; tc++){
		memset(color, 0, sizeof(color));
		memset(flag, 0, sizeof(flag));
		
		int n;
		
		scanf("%d", &n);
		
		for(int i = 1; i <= n; i++){
			int u, v;
			scanf("%d %d",&u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
			flag[u] = 1;
			flag[v] = 1;
		}
		int ans = 0;
		for(int i = 0; i <= 20000; i++){
			if(flag[i] == 1 && color[i] == 0){
				color[i] = 1;
				p1 = 0;
				p2 = 0;
				dfs(i);
				ans += max(p1, p2);
			}
		}
		
		int cnt1 = 0;
		
				
		printf("Case %d: %d\n",tc, ans);
		
		for(int i = 0; i <= 20000; i++)
		g[i].clear();
	}
	
}
