#include<bits/stdc++.h>
using namespace std;
#define mxx 100005

int par[mxx];

struct edge{
int u, v, w;
    bool operator < (const edge &p)const{
    return w < p.w;
    }
};
int findd(int r)
{
    if(par[r] == r){
        return r;
    }
    else return par[r] = findd(par[r]);
}

vector<edge> e;

int mst(int n)
{
    sort(e.begin(), e.end());

    for(int i = 1; i <= n; i++){
        par[i] = i;
    }
    int cnt = 0, s = 0;

    for(int i = 0; i < (int)e.size(); i++){
        int u = findd(e[i].u);
        int v = findd(e[i].v);

        if(u != v){
            par[u] = v;
            s += e[i].w;
            cnt++;
            if(cnt == n - 1)
                break;
        }
    }
    return s;
}

int main()
{
    int n, m;

    scanf("%d %d",&n, &m);

    for(int i = 0; i < m; i++){
        int u, v, w;
        edge get;

        scanf("%d %d %d",&u, &v, &w);

        get.u = u;
        get.v = v;
        get.w = w;

        e.push_back(get);
    }

    int res = mst(n);

    printf("%d\n",res);
    return 0;
}
