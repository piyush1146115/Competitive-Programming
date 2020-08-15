#include<bits/stdc++.h>
using namespace std;
#define MX 105

int dis[MX], pa[MX];

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

void dijkstra(int s, int des)
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
                    pa[e.v] = u.at;
                    pq.push(node(e.v, dis[e.v]));
                }
             }
            }


        return;
}

int main()
{
    int i, test, N, M, T, E, n1, n2, t;
    vector<int>ans;




        int cnt = 0;
        scanf("%d %d %d", &N, &M, &T);

        for(i = 0; i < M; i++){
            scanf("%d %d %d", &n1, &n2, &t);
            adj[n1].push_back(edge(n2, t));
        }

            dijkstra(1, N);

        int now = N, temp;

        ans.push_back(N);
        while(now != 1){

            now = pa[now];
                 ans.push_back(now);
        }
        printf("%d\n",ans.size());

        for(i = ans.size(); i >= 0; i++)
            printf("%d ",ans[i]);

        printf("\n");

    return 0;
}

