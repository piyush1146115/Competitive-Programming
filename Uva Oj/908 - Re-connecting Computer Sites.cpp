#include<bits/stdc++.h>
using namespace std;
#define mxx 1000005

struct edge{
int u, v, w;
bool operator < (const edge &p)const{
    return w < p.w;
}
};

int pr[mxx];

int findd(int r)
{
   return (pr[r] == r)? r : findd(pr[r]);
}

vector<edge> e;

int mst(int n)
{
    for(int i = 0; i <= n; i++){
        pr[i] = i;
    }

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

int main()
{

    int n, cnt  = 0;

    while(scanf("%d", &n) == 1){
        int old = 0;

            int u, v, w;
        for(int i = 1; i < n; i++){
            scanf("%d %d %d", &u, &v, &w);
            old += w;
        }


    int  k;
    scanf("%d", &k);

        edge get;
    for(int i = 0; i < k; i++){
        //int u, v, w;
        scanf("%d %d %d", &u, &v,  &w);
        get.u = u;
        get.v = v;
        get.w = w;
        e.push_back(get);
    }

    int m;

    scanf("%d", &m);

    for(int i = 0; i < m; i++){
       // int u, v, w;
        //edge get;
        scanf("%d %d %d", &u, &v,  &w);
        get.u = u;
        get.v = v;
        get.w = w;
        e.push_back(get);
//    cout <<"ok" << endl;
    }


    int ans = mst(m + k);
    if(cnt)
        printf("\n");

    printf("%d\n%d\n",old, ans);
    cnt = 1;
    e.clear();
    }
}
