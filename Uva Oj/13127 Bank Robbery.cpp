#include<bits/stdc++.h>
using namespace std;
#define MX 1005

int dis[MX], ans[MX];

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


    dis[s] = 0;
    priority_queue<node> pq;

    pq.push(node(s, 0));

    while(!pq.empty()){
        node u = pq.top();
        pq.pop();

        if(u.cost != dis[u.at]){/// checking if the distance is minimum
            continue;
        }
        for(int i = 0; i < adj[u.at].size(); i++){
            edge e = adj[u.at][i];

            if(dis[e.v] > u.cost + e.w){
                dis[e.v] = u.cost + e.w;
                ans[e.v] = min(ans[e.v], dis[e.v]);
                pq.push(node(e.v, dis[e.v]));
            }
        }
 }
    return;
}

int main()
{
    int i, j, k, n, m, p[MX], b[MX], B, P, t;

    while(scanf("%d %d %d %d", &n, &m, &B, &P) == 4){
        reset();
        for(i = 0; i < MX; i++)
            ans[i] = 1000000000;

        for(i = 0; i < m; i++){
            scanf("%d %d %d", &j, &k, &t);
            adj[j].push_back(edge(k, t));
            adj[k].push_back(edge(j, t));
        }

        for(i = 0; i < B; i++)
            scanf("%d", &b[i]);

        for(i = 0 ; i < P; i++)
            scanf("%d", &p[i]);

        for(i = 0; i < P; i++){
            dijkstra(p[i]);
        }

        int mx = 0;
        for(i = 0; i < B; i++){
                if(ans[b[i]] == 1000000000){
                    mx = 1000000000;
                    break;
                }
            mx = max(mx, ans[b[i]]);
        }

        int co = 0;
        vector<int> v;

        for(i = 0; i < B; i++){
            if(ans[b[i]] == mx){
                co++;
                v.push_back(b[i]);
            }
        }

        sort(v.begin(), v.end());

        printf("%d ",co);

        if(mx == 1000000000)
            printf("*\n");
        else{
            printf("%d\n",mx);
        }

        printf("%d",v[0]);

        for(i = 1; i < v.size(); i++)
            printf(" %d",v[i]);

            printf("\n");

    for(i = 0;  i < n + 2; i++)
        adj[i].clear();
    }
    return 0;
}
