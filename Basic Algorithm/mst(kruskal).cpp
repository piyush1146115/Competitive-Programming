#include<bits/stdc++.h>
using namespace std;
#define mxx 100005



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

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int u, v, w;

        cin >> u >> v >> w;
        edge get;

        get.u = u;
        get.v = v;
        get.w = w;

        e.push_back(get);
    }

    cout << mst(n) << endl;
}

/*
7 11
1 2 7
1 4 5
2 4 9
2 3 8
2 6 7
4 6 15
4 5 6
5 7 11
5 6 8
3 6 5
6 7 9
*/
