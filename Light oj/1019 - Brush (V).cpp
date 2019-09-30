#include<bits/stdc++.h>
using namespace std;
#define MX 205

int dis[MX];
struct node{
int at, cost;

    node(int _at, int _cost){
        at = _at;
        cost = _cost;
    }
} ;

bool operator <(node a, node b)
{
    ///priority queue returns the greatest value
    ///so we need to write the comparator in a way
    ///so that the cheapest value becomes the greatest value
    return a.cost > b.cost;
}

struct edge{
    int v, w;
    edge(int _v, int _w){
    v = _v;
    w = _w;
    }
};

vector<edge> adj[MX];

void reset()
{
    for(int i = 0; i < MX; i++){
        dis[i] = 1000000000;
//        adj[i].clear();
    }
}

void dijkstra(int s)
{
    reset();

    dis[s] = 0;
    priority_queue<node> pq;

    pq.push(node(s, 0));

    while(!pq.empty()){
        node u = pq.top();
        pq.pop();

        if(u.cost != dis[u.at]){/// checking if the node is updated previously 
            continue;
        }
        
        for(int i = 0; i < adj[u.at].size(); i++){
            edge e = adj[u.at][i];

            if(dis[e.v] > u.cost + e.w){
                dis[e.v] = u.cost + e.w;
                pq.push(node(e.v, dis[e.v]));
            }
        }
    }
    
    return;
}

int main()
{
    int i, j, k, test, m, n, s, des, ans, cst, cse = 0;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d",&n, &m);

        for(i = 0; i < m; i++){
            scanf("%d %d %d",&j, &k, &cst);
            adj[j].push_back(edge(k, cst));
            adj[k].push_back(edge(j, cst));
        }

        dijkstra(1);

        if(dis[n] == 1000000000){
            printf("Case #%d: Impossible\n", ++cse);
        }
        else{
            printf("Case #%d: %d\n",++cse, dis[n]);
        }

        for(i = 0; i <= n; i++)
            adj[i].clear();
    }
}

