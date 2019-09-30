#include<bits/stdc++.h>
using namespace std;
#define MX 105

int dis[MX];

struct node{

    int at, cost;

    node(int _at, int _cost){
    at = _at;
    cost = _cost;
    }

};

bool operator < (node a, node b)
{
    return a.cost > b.cost;
}

struct edge{
    int v, w;

    edge(int _v, int _w){
    v = _v;
    w = _w;
    }
};

vector <edge> adj[MX];

void reset()
{
    for(int i = 0; i < MX; i++)
        dis[i] = INT_MAX;
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

             if(u.cost != dis[u.at]){
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
    int i, test, N, M, T, E, n1, n2, t;

    scanf("%d", &test);

    while(test--){
        int cnt = 0;
        scanf("%d %d %d %d", &N, &E, &T, &M);

        for(i = 0; i < M; i++){
            scanf("%d %d %d", &n1, &n2, &t);
            adj[n1].push_back(edge(n2, t));
        }

        for(i = 1; i <= N; i++){
            dijkstra(i);
            if(dis[E] <= T){
                cnt++;
            }
        }
        printf("%d\n",cnt);

        if(test)
            printf("\n");

        for(i = 0; i < N + 2; i++)
            adj[i].clear();

    }
    return 0;
}
