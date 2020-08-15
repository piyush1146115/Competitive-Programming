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
    return s;
}

int mst2(int n)
{
    for(int i = 0; i <= n; i++)
    pr[i] = i;

    sort(e.begin(), e.end());
    reverse(e.begin(), e.end());
    
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
    return s;
}

int main()
{
   int test;
   
   scanf("%d", &test);
   
   for(int tc = 1; tc <= test; tc++){
    int n;
    //cin >> n;
	scanf("%d",&n);
            int u, v, w;
		
		while(scanf("%d %d %d",&u, &v, &w) == 3){
		
		if(u == 0 && v == 0 && w == 0)
		break;
		
        edge get;

        get.u = u;
        get.v = v;
        get.w = w;

        e.push_back(get);
    
}

	int best = mst(n  + 1);
	int worst = mst2(n  + 1);
	int ans = (best + worst);
	
	if(ans % 2 == 0){
		printf("Case %d: %d\n",tc, ans/2);
	}
	else{
		printf("Case %d: %d/%d\n",tc, ans, 2);
	}
	e.clear();
}
}
