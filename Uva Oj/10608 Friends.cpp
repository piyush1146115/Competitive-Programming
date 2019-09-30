#include<bits/stdc++.h>
using namespace std;
#define mxx 30005
int par[mxx], rn[mxx], ara[mxx], cnt[mxx];

int fnd(int n)
{
	if(par[n] == n)
	return n;
	else{
		return par[n] = fnd(par[n]);
	}
}

void unin(int a, int b)
{
	int u = fnd(a);
	int v = fnd(b);
	
	if(rn[u] > rn[v]){
		par[v] = u;
	}
	else{
		par[u] = v;
		rn[v]++;
	}
}

int main()
{
	
	int test;
	
	scanf("%d", &test);
	
	while(test--){
		memset(rn, 0, sizeof(rn));
		memset(cnt, 0, sizeof(cnt));
		
	int n, m;
	scanf("%d %d",&n, &m);
	
	for(int i = 1; i <= n; i++){
	par[i] = i;
	}
	
	for(int i = 0; i < m; i++){
	int u, v;
	scanf("%d %d", &u, &v);
	unin(u, v);
	}
	
	for(int i = 1; i <= n; i++){
	par[i] = fnd(par[i]);
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		cnt[par[i]]++;
		ans = max(cnt[par[i]], ans);
	}
	printf("%d\n",ans);
	}
	return 0;
}
