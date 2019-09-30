#include<bits/stdc++.h>
using namespace std;
#define mxx 100005

vector<int> g[mxx], vec;
int color[mxx];
int col1, col2;
int vis[mxx];


void dfs(int u)
{
	vis[u] = 1;
	
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
	
	if(vis[v] == 0){
	if(color[u] == 1){
		color[v] = 2;
		col2++;
	}
		else{
		vec.push_back(v);
		color[v] = 1;
	}
		dfs(v);
	}
		
	}
}

int main()
{
	
	int n;
	scanf("%d", &n);
	
	for(int i = 1 ; i < n; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	col1 = 1;
	col2 = 0;
	color[1] = 1;
	vec.push_back(1);
	dfs(1);
	long long cnt = 0;
	for(int i = 0; i < (int)vec.size(); i++){
		
			int c = col2 - (int)g[vec[i]].size();
			//cout <<1 <<" "  <<i << " "<<  (int)g[i].size() << " " << col1 << " "<< c << endl;
			//getchar();
			if(c > 0){
			cnt += c;	
		}
	}
	
	printf("%I64d\n", cnt);
}
