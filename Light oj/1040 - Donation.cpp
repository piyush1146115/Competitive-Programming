#include<bits/stdc++.h>
using namespace std;
#define mxx 105

struct edge{
int u, v, w;

bool operator < (const edge &p)const{
return w < p.w;
}
};

int pr[mxx];

vector<edge> e;

int findd(int r)
{
   if(pr[r] == r){
	   return r;
   }
   else{
	   return pr[r] = findd(pr[r]);
   }
}

int mst(int n)
{
    for(int i = 0; i <= n; i++)
    pr[i] = i;

    sort(e.begin(), e.end());
    int cnt = 0, s = 0;

    for(int i = 0; i < e.size(); i++){
        int u = findd(e[i].u);
        int v = findd(e[i].v);

        if(u != v){
            pr[u] = v;
            cnt++;
           s += e[i].w;
           if(cnt == n - 1)
            break;
        }
    }
    if(cnt != n - 1)
    return -1;
    
    return s;
}

int main()
{
	int test;
	scanf("%d", &test);

	for(int tc = 1; tc <= test; tc++){
    int n, m;
    int total = 0;
    
    scanf("%d", &n);
    
    int  w, u, v;

    for(int i = 1; i <= n; i++){
      for(int j = 1 ;j <= n; j++){
     
		scanf("%d", &w);
		if(w > 0){
        edge get;
		total += w;
        get.u = i;
        get.v = j;
        get.w = w;

        e.push_back(get);
        }
        
    }
}

    int ans = mst(n);
    
    if(ans == -1){
		printf("Case %d: -1\n",tc);
	}
	else{
		printf("Case %d: %d\n",tc, total - ans);
	}
    e.clear();
    }
}
