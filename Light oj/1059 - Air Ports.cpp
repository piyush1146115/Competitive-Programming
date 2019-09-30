#include<bits/stdc++.h>
using namespace std;
#define mxx 10005
#define ll long long


int par[mxx];
int N, M, A;
int ap, ct;

struct edge {
    int u, v, w;
    bool operator < (const edge &p)const {
        return w < p.w;
    }
};

int findd(int r) {
    if (par[r] == r) {
        return r;
    }
     else return par[r] = findd(par[r]);
}

vector<edge> e;

ll mst(int n) {
    sort(e.begin(), e.end());

    for (int i = 1; i < mxx; i++) {
        par[i] = i;
    }

    ll cnt = 0, s = 0;

    for (int i = 0; i < (int)e.size(); i++) {
        int u = findd(e[i].u);
        int v = findd(e[i].v);

        if (u != v) {
            if (e[i].w >= A) {
				break;
            }
             else
                s += e[i].w;

            par[u] = v;
            cnt++;
            if (cnt == n - 1)
                break;
        }
    }
    return s;
}



int main() {
    int test;

    scanf("%d", &test);

    for (int tc = 1; tc <= test; tc++) {
        ap = 0;

        scanf("%d %d %d", &N, &M, &A);
   
        int u, v, w;

        for (int i = 1; i <= M; i++) {
            scanf("%d %d %d", &u, &v, &w);
           edge get;
           
           get.u = u;
           get.v = v;
           get.w = w;
           e.push_back(get);
        }
        
        ll ans = mst(N);

		
		for(int i = 1; i <= N; i++){
			if(par[i] == i){
				ap++;
				ans += A;
			}
		}
        printf("Case %d: %lld %d\n", tc, ans, ap);
		e.clear();
    }
}
