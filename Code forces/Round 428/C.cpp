#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
//#define pii pair<int, int>
#define DB(a) cout <<#a <<" " << a << endl;
#define mxx 100005
vector<int> g[mxx];
int vis[mxx];
double  sum;

void dfs(int u, int len, double prob)
{
	vis[u] = 1;
	int flag = 1;
	int cnt = 0;
	
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(vis[v] == 0){
			flag = 0;
			//dfs(v, len + 1);
			cnt++;
		}
	}
	
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(vis[v] == 0){
			flag = 0;
			dfs(v, len + 1, prob/(double)cnt);
		}
	}
	if(flag){
		
		sum += ((double)len * prob);
	}
}

int main()
{
	
	memset(vis, 0, sizeof(vis));
	int n;
	sum = 0.0;
	
	scanf("%d", &n);
	
	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(1, 0, 1.0);
	//double ans = sum/cnt;
	
	printf("%.18lf\n",sum);
	
	
}
