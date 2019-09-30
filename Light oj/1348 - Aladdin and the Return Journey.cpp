#include<bits/stdc++.h>
using namespace std;
#define mxx 30005
int ara[mxx * 2 + 5];
int L[mxx];
int P[mxx][20];
int T[mxx];
int tree[mxx * 8];
int tme;
int N, sz;

struct st{
	int str, en, val;
}node[mxx];

vector<int> g[mxx];

void dfs(int from, int u, int dep)
{
	T[u] = from;
	L[u] = dep;
	++tme;
	ara[tme] = node[u].val;
	node[u].str = tme;
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		
		if(v == from)
		continue;
		
		dfs(u, v, dep + 1);
	}
	tme++;
	node[u].en = tme;
	ara[tme] = - node[u].val;
	return;
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

void init(int nd, int b, int e)
{
	if(b == e){
		tree[nd] = ara[b];
		return;
	}
	int left = nd * 2;
	int right = nd * 2 + 1;
	int mid = (b + e)/2;
	
	init(left, b, mid);
	init(right, mid + 1, e);
	
	tree[nd] = tree[left] + tree[right];
}

void update(int nd, int b, int e, int x, int v)
{
	if(x > e || x < b)
	return;
	
	//if(i > e || i < b)
      //  return;
	
	if(b >= x && e <= x)
	{
		tree[nd] = v;
		return;
	}
	int left = nd * 2;
	int right = nd * 2 + 1;
	int mid = (b + e)/2;
	
	update(left, b, mid, x, v);
	update(right, mid + 1, e, x, v);
	
	tree[nd] = tree[left] + tree[right];
}


int query(int nd, int b, int e, int i, int j)
{
	 if(i > e || j < b)
        return 0;
	
	if(b >= i && e <= j){
		return tree[nd];
	}
	
	int left = nd * 2;
	int right = nd * 2 + 1;
	int mid = (b + e)/2;
	
	int p1 = query(left, b, mid, i, j);
	int p2 = query(right, mid + 1, e, i, j);
	
	return p1 + p2;
}

int main()
{
	int test;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		scanf("%d", &N);
		
		for(int i = 1; i <= N; i++){
			scanf("%d", &node[i].val);
		}
		
		for(int i = 1; i < N; i++){
			int u, v;
			scanf("%d %d",&u, &v);
			g[u + 1].push_back(v + 1);
			g[v + 1].push_back(u + 1);
		}
		
		tme = 0;
		dfs(1, 1, 0);
		lca_init();
		sz = 2 * N;
		
		init(1, 1, sz);
		
		int q;
		
		/*for(int i = 1; i <= N; i++){
			printf("%d start : %d  end : %d\n",i, node[i].str, node[i].en);
		}*/
		
		/*for(int i = 1; i <= 2*N; i++)
		printf("%d : %d\n",i, ara[i]);*/
		
		scanf("%d", &q);
		printf("Case %d:\n",tc);
		
		while(q--){
			int t, u, v;
			scanf("%d %d %d",&t, &u, &v);
			
			if(t == 0){
				int lca = lca_query(u + 1, v + 1);
				
				//printf("%d %d %d\n", lca, u + 1, v + 1);
				//printf("%d %d %d\n", node[lca].str, node[u + 1].str, node[v + 1].str);
				
				int ans = query(1, 1, sz, node[lca].str, node[u + 1].str);
				ans += query(1, 1, sz, node[lca].str, node[v + 1].str);
				printf("%d\n", ans - ara[node[lca].str]);
			}
			else{
				update(1, 1, sz, node[u + 1].str, v);
				update(1, 1, sz, node[u + 1].en, -v);
				ara[node[u + 1].str] = v;
				ara[node[u + 1].en] = - v;
			}	
		}
			
		for(int i = 0 ; i<= N; i++){
			g[i].clear();
		}
	}
}
