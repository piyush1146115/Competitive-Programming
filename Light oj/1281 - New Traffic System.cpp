#include<bits/stdc++.h>
using namespace std;
#define mxx 10005
#define inf 1000000000000
long long int dis[11][mxx];

int m, n, k, d;

struct node {
    int at, cost, state;

    node(int _at, int _cost,int _state) {
        at = _at;
        cost = _cost;
        state = _state;
    }
};

bool operator <(node a, node b)
{
    //priority queue returns the greatest value
    //so we need to write the comparator in a way that the cheapest value becomes the greatest value
    return a.cost > b.cost;
}

struct edge {
    int v, w,state;
    edge(int _v, int _w, int _state) {
        v = _v;
        w = _w;
        state = _state;
    }
};

vector<edge> adj[mxx];

/*
void reset()
{
    for(int i = 0; i < mxx; i++) {
        dis[i] = inf;
    }
}*/


int dijkstra(int s)
{
    // reset();

    memset(dis, 1, sizeof(dis));

    dis[0][s] = 0;
    priority_queue<node> pq;
    pq.push(node(s, 0, 0));

    while(!pq.empty()) {

        node u = pq.top();
        pq.pop();

        if(u.cost != dis[u.state][u.at]) { /// checking if the node was updated previously
            continue;
        }


        if(u.at == n - 1)
            return u.cost;


        for(int i = 0; i < adj[u.at].size(); i++) {
            edge e = adj[u.at][i];
            e.state += u.state;

            if(e.state <= d && dis[e.state][e.v] > u.cost + e.w) {
                dis[e.state][e.v] = u.cost + e.w;
                pq.push(node(e.v, dis[e.state][e.v], e.state));
            }
        }
    }

    return - 1;
}


int main()
{
    int test;
    scanf("%d",&test);

    for(int tc = 1; tc <= test; tc++)
    {
        scanf("%d %d %d %d",&n, &m, &k, &d);

        int u,v, cst;

        for(int i = 1; i <= m; i++) {
            scanf("%d %d %d", &u, &v, &cst);
            adj[u].push_back(edge(v, cst, 0));
        }

        //	dijkstra(0);

        for(int i = 1; i <= k; i++) {
            scanf("%d %d %d", &u, &v, &cst);
            adj[u].push_back(edge(v, cst, 1));
        }

        int res = dijkstra(0);


        if(res == -1)
            printf("Case %d: Impossible\n",tc);
        else
            printf("Case %d: %d\n",tc, res);


        for(int i = 0; i <= n; i++)
            adj[i].clear();
    }
    return 0;
}
