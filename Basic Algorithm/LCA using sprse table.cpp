#include <bits/stdc++.h>
using namespace std;
#define mxx 100005
int N; //number of node
int L[mxx]; //level
int P[mxx][22]; // sparse table
int T[mxx]; //parent
vector<int> g[mxx];

void dfs(int from, int u, int dep)
{
	T[u] = from;
	L[u] = dep;
	
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		
		if(v == from)
		continue;
		
		dfs(u, v, dep + 1);
	}
}

int lca_query(int p, int q)
{
	int  lg;
	
	if(L[p] < L[q])
	swap(p, q);
	
	lg = 1;
	
	while(1){
		int next = lg + 1;
		if((1 << next) > L[p]) 
		break;
		lg++;
	}
	
	for(int i = lg; i >= 0; i--){
		if(L[p] - (1 << i) >= L[q]){
			p = P[p][i];
		}
	}
	
	if(p == q)
	return p;
	
	for(int i = lg; i >= 0; i--){
		if(P[p][i] != -1 && P[p][i] != P[q][i])
		p = P[p][i], q = P[q][i];
	}
	
	return T[p];
}

void lca_init()
{
	memset(P, -1, sizeof(P));
	int i, j;
	
	for(i = 1; i <= N; i++){
		P[i][0] = T[i];
	}
	
	for(j = 1; (1 << j) <= N;j++){
		for(i = 1; i <= N; i++){
			if(P[i][j - 1] != -1)
			P[i][j] = P[P[i][j - 1]][j - 1];
		}
	}
}

int main()
{
	N = 5;
	
	g[1].push_back(2);
	g[1].push_back(3);
	g[3].push_back(4);
	g[3].push_back(5);
	dfs(1, 1, 0);
	lca_init();
	printf("%d\n",lca_query(4, 2));
}
