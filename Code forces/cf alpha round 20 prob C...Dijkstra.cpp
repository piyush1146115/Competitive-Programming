#include<bits/stdc++.h>
using namespace std;
#define MX 100005

long long dis[MX], par[MX];

struct node{

long long at, cost;

node(long long _at, long long _cost){
    at = _at;
    cost = _cost;
}
};

bool operator < (node a, node b)
{
    return a.cost > b.cost;
}

struct edge
{
    long long v, w;

    edge(long long _v, long long _w){
    v = _v;
    w = _w;
    }
};

vector<edge> adj[MX];

void reset()
{
    for(int i = 0; i < MX; i++){
        dis[i] = 10000000000000;
        par[i] = -1;
    }
}


void dijkstra()
{
    reset();
    dis[1] = 0;

    priority_queue<node> pq;

    pq.push(node(1, 0));

    while(!pq.empty()){
        node u = pq.top();
        pq.pop();

        if(u.cost != dis[u.at])
            continue;

        for(int i = 0; i < adj[u.at].size(); i++){
            edge e= adj[u.at][i];

        if(dis[e.v] > u.cost+ e.w){
            dis[e.v] = u.cost + e.w;
            pq.push(node(e.v, dis[e.v]));
            par[e.v] = u.at;
        }
        }
    }
    return;
}

int main()
{
    long long n , m , i, j, k, l;

    scanf("%lld %lld", &n, &m);

    for(i = 0; i < m; i++){
        scanf("%lld %lld %lld", &j, &k, &l);
        adj[k].push_back(edge(j, l));
        adj[j].push_back(edge(k, l));
    }
    dijkstra();


        if(dis[n] == 10000000000000)
            printf("-1\n");
        else
            {
                vector<long long> ans;

                long long s = n;

                ans.push_back(n);

             while(par[s] != -1){
                ans.push_back(par[s]);
                s = par[s];
             }
             reverse(ans.begin(), ans.end());

             for( i = 0; i < ans.size(); i++)
                printf("%lld ",ans[i]);

             printf("\n");
            }
    return 0;
}
