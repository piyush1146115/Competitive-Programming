#include<bits/stdc++.h>
using namespace std;
#define mxx 50005
int pr[mxx];//for disjoint set
int N;//number of node
vector<int> g[mxx];//tree
vector<int>cst[mxx];//costs of tree
int L[mxx];//level
int T[mxx];//parent
int dist[mxx];//cost of incoming edge
int P[mxx][16];//sparse table for lca
int C[mxx][16];//sparse table for max edge

struct edge{
	int u, v, w;
	bool operator < (const edge &p)const{
		return w < p.w;
	}
};

vector<edge> e;

int findd(int r)
{
	if(pr[r] == r)
	return r;
	else{
	 return pr[r] = findd(pr[r]);
	}
}

void mst()
{
	sort(e.begin(), e.end());
	
	for(int i = 1; i <= N; i++)
	pr[i] = i;
	
	int count = 0;
	
	for(int i = 0; i < (int)e.size(); i++){
		int u = findd(e[i].u);
		int v = findd(e[i].v);
		
		if(u != v){
			pr[u] = v;
			count++;
			g[u].push_back(v);
			g[v].push_back(u);
			cst[u].push_back(e[i].w);
			cst[v].push_back(e[i].w);
			
			if(count == N - 1)
			break;
			}
	}
}


void dfs(int from, int u, int dep, int cost) {
    T[u] = from;
    L[u] = dep;
    dist[u] = cost;

    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];

        if (v == from)
            continue;

        dfs(u, v, dep + 1,cst[u][i]);
    }
}

void lca_init()
{
	memset(P, -1, sizeof(P));
	//memset(C, -1, sizeof(C));
	
	for(int i = 1 ; i <= N; i++){
		P[i][0] = T[i];
		C[i][0] = dist[i];
	}
	
	for(int j = 1; (1 << j) <= N; j++){
		for(int i = 1; i <= N;i++){
			if(P[i][j - 1] != -1){
				P[i][j] = P[P[i][j - 1]][j - 1];
				C[i][j] = max(C[i][ j - 1], C[P[i][j - 1]][j -1]);
			}
		}
	}
}


int lca_query(int p, int q) {
    int  lg;

    if (L[p] < L[q])
        swap(p, q);

    lg = 1;

    while (1) {
        int next = lg + 1;
        if ((1 << next) > L[p])
            break;
        lg++;
    }

    for (int i = lg; i >= 0; i--) {
        if (L[p] - (1 << i) >= L[q]) {
            p = P[p][i];
        }
    }

    if (p == q)
        return p;

    for (int i = lg; i >= 0; i--) {
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];
    }

    return T[p];
}


int ser(int p, int k) {
    int lg = 1;

    while (1) {
        if ((1 << lg) > L[p])
            break;
        lg++;
    }
	int ans = -1;
	
    for (int i = lg; i >= 0; i--){
        if ((1 << i) <= k) {
			ans = max(ans, C[p][i]);
            p = P[p][i];
            k -= (1 << i);
            if (k == 0)
                break;
        }
    }

    return ans;
}

int main()
{
	int test;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		int m;
		scanf("%d %d", &N, &m);
		
		for(int i = 0 ; i < m; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			
			edge get;
			get.u = u;
			get.v = v;
			get.w = w;
				
			e.push_back(get);
		}
		mst();
		dfs(1, 1, 0 , 0);
		lca_init();
		
		int q;
		scanf("%d", &q);
		
		printf("Case %d:\n",tc);
		
		while(q--){
			int u, v;
			scanf("%d %d", &u, &v);
			int lca = lca_query(u, v);
			int k;
			k = L[u] - L[lca];
			int ans = ser(u, k);
			k = L[v] - L[lca];
			ans = max(ans, ser(v, k));
			printf("%d\n",ans);
		}
		
		for(int i = 0; i <= N; i++){
		g[i].clear();
		cst[i].clear();
	}
		
		e.clear();
	}
}
