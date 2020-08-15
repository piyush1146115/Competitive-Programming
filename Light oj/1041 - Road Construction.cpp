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
    map<string, int> mp;
    
    scanf("%d", &n);
    
    int  w, u, v;
	string a, b;
	m = 0;
    for(int i = 1; i <= n; i++){
        
        cin >> a >> b >> w;
        
        if(mp[a] == 0){
			m++;
			u = mp[a] = m;
		}
		else{
			u = mp[a];
		}
		
		if(mp[b] == 0){
			m++;
			mp[b] = v = m;
		}
		else{
			v = mp[b];
		}
		
        edge get;

        get.u = u;
        get.v = v;
        get.w = w;

        e.push_back(get);
    }

    int ans = mst(m);
    
    if(ans == -1){
		printf("Case %d: Impossible\n",tc);
	}
	else{
		printf("Case %d: %d\n",tc, ans);
	}
    e.clear();
    }
}
