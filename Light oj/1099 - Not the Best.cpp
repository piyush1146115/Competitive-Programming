#include<bits/stdc++.h>
using namespace std;
#define MX 5015

int dis[MX], dis2[MX];
int mn, n;

struct node {
    int at, cost, flag;

    node(  int _at,  int _cost, int _flag) {
        at = _at;
        cost = _cost;
        flag = _flag;
    }
};

bool operator <(node a, node b)
{
    ///priority queue returns the greatest value
    ///so we need to write the comparator in a way
    ///so that the cheapest value becomes the greatest value
    return a.cost > b.cost;
}

struct edge {
    int v, w;
    edge(  int _v,  int _w) {
        v = _v;
        w = _w;
    }
};

vector<edge> adj[MX];

void reset()
{
    for(int i = 0; i < 5005; i++) {
        dis[i] = 100000000;
        dis2[i] = 100000000;
        //        adj[i].clear();
    }
}

void dijkstra(int s)
{
    reset();
    mn = 1000000000;
    dis[s] = 0;
    dis2[s] = 0;

    priority_queue<node> pq;

    pq.push(node(s, 0, 0));
    pq.push(node(s, 0, 1));

    while(!pq.empty()) {
        node u = pq.top();
        pq.pop();
			
		//	cout << u.at << " " << u.cost << " " << u.flag <<  endl;
       
       
       /* if(u.cost > dis[u.at]) { /// checking if the node is updated previously
            continue;
        }*/
			
		//	cout << u.at << " " << u.cost << " " << u.flag <<  endl;
			
        for(int i = 0; i < adj[u.at].size(); i++) {
            edge e = adj[u.at][i];

            int  w=e.w;

            if(u.flag==1)
                w+=dis2[u.at];
            else
                w+=dis[u.at];
			     
          
            if(dis[e.v] > w) {
                dis2[e.v] = dis[e.v];
                dis[e.v] = w;
                mn = min(mn,e.w);
                if(u.at == n)
                    continue;
                
                pq.push(node(e.v, dis2[e.v],1));
                pq.push(node(e.v, dis[e.v],0));
            }

             if(dis2[e.v] > w && dis[e.v] < w) {
                dis2[e.v] =w;
                mn = min(mn,e.w);
                if(u.at == n)
                    continue;
                pq.push(node(e.v, dis2[e.v],1));
            }
        }
    }

    return;
}


int main()
{
    int i, j, k, test, m, cst, cse = 0;

    scanf("%d", &test);

    while(test--) {
        scanf("%d %d",&n, &m);

        for(i = 0; i < m; i++) {
            scanf("%d %d %d",&j, &k, &cst);
            adj[j].push_back(edge(k, cst));
            adj[k].push_back(edge(j, cst));
        }

        dijkstra(1);

         //printf("%d\n",mn, dis2[3]);
		
        printf("Case %d: %d\n",++cse, min((dis[n] + mn * 2), dis2[n]));


        for(i = 0; i <= n; i++)
            adj[i].clear();
    }
}
