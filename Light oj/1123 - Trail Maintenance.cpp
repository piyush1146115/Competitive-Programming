#include<bits/stdc++.h>
using namespace std;
#define mxx 205
int par[mxx];

struct edge {
    int u, v, w;
    bool operator < (const edge &p)const {
        return w < p.w;
    }
};

int findd(int r) {
    if (par[r] == r) {
        return r;
    } else return par[r] = findd(par[r]);
}

vector<edge> e;

int mst(int n) {
	
    sort(e.begin(), e.end());
    
		for (int i = 1; i <= n; i++){
        par[i] = i;
    }
    vector<edge> temp;
    
    int cnt = 0, s = 0;

    for (int i = 0; i < (int)e.size(); i++) {
        int u = findd(e[i].u);
        int v = findd(e[i].v);
        
        if (u != v) {
			edge get;
			get.u = e[i].u;
			get.v = e[i].v;
			get.w = e[i].w;
			temp.push_back(get);
            par[u] = v;
            s += e[i].w;
            cnt++;
            if (cnt == n - 1){
                e.clear();
                e = temp;
                break;
			}
        }
    }
    if (cnt != n - 1)
        return -1;
    
    return s;
}

int main()
{
    int n, m, test;

    scanf("%d", &test);

    for (int tc = 1; tc <= test; tc++) {
        scanf("%d %d", &n, &m);
        
        printf("Case %d:\n", tc);
        int res;
		
        for (int i = 1; i <= m; i++){
            int u, v, w;
            edge get;
            scanf("%d %d %d", &u, &v, &w);
				
            get.u = u;
            get.v = v;
            get.w = w;
            e.push_back(get);
                res = mst(n);
                
            printf("%d\n", res);
        }
        e.clear();
    }
}
