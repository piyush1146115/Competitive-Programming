#include<bits/stdc++.h>
#include <iostream>
using namespace std;

#define inf 10000
const int maxnodes = 211;
int nodes, src, dest;
int dist[maxnodes], q[maxnodes], work[maxnodes];

struct Edge {
  int to, rev;
  int f, cap;
};

struct node{
    double x,y;
    int now,cap;
};

node arr[maxnodes];

vector<Edge> g[212];

// Adds bidirectional edge

void init(int n)
{
    for(int i=1;i<=n;i++)
        g[i].clear();
}

void addEdge(int s, int t, int cap){
  Edge a = {t, g[t].size(), 0, cap}; //for s to t
  Edge b = {s, g[s].size(), 0, 0};  // for t to s
  g[s].push_back(a);
  g[t].push_back(b);
}

bool dinic_bfs() {
  fill(dist, dist + nodes, -1);
  dist[src] = 0;
  int qt = 0;
  q[qt++] = src;
  for (int qh = 0; qh < qt; qh++) {
    int u = q[qh];
    for (int j = 0; j < (int) g[u].size(); j++) {
      Edge &e = g[u][j];
      int v = e.to;
      if (dist[v] < 0 && e.f < e.cap) {
        dist[v] = dist[u] + 1;
        q[qt++] = v;
      }
    }
  }
  return dist[dest] >= 0;
}

int dinic_dfs(int u, int f) {

  if (u == dest)
    return f;
  for (int &i = work[u]; i < (int) g[u].size(); i++) {
    Edge &e = g[u][i];
    if (e.cap <= e.f) continue;
    int v = e.to;
    if (dist[v] == dist[u] + 1) {
      int df = dinic_dfs(v, min(f, e.cap - e.f));
      if (df > 0) {
        e.f += df;
        g[v][e.rev].f -= df;
        return df;
      }
    }
  }
  return 0;
}

int maxFlow(int _src, int _dest) {

  src = _src;
  dest = _dest;
  nodes = 210;
  int result = 0;
  while (dinic_bfs()) {
    fill(work, work + nodes, 0);
    while (int delta = dinic_dfs(src, INT_MAX))
    {
        result += delta;
    }
  }
  return result;
}

int main() {

    //freopen("input.txt","r",stdin);
   //freopen("out.txt","w",stdout);
    int test,n,p,q,Case,source,tot;
    double dis,x,y;

    scanf("%d",&test);

    for(Case = 1; Case<=test;Case++)
    {
        scanf("%d",&n);
        scanf("%lf",&dis);

        int source = 2*n+1;
        tot=0;

      //  cout<<n<<endl;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf %lf %d %d",&x,&y,&p,&q);
            tot+=p;

            arr[i].x = x;
            arr[i].y = y;
            arr[i].now = p;
            arr[i].cap = q;

            //addEdge(source,i,p);
            //addEdge(i,n+i,q);
        }

        //cout<<"thug life"<<endl;

        printf("Case %d:",Case);
        bool flag=1;

        for(int id = 1 ;id<=n;id++)
        {
            init(src);  //run time
            for(int i=1;i<=n;i++)
            {
                addEdge(source,i,arr[i].now);
                addEdge(i,n+i,arr[i].cap);
            }

            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    double dd = (arr[i].x - arr[j].x)*(arr[i].x - arr[j].x) + (arr[i].y - arr[j].y)*(arr[i].y - arr[j].y);
                    dd = sqrt(dd);

                    if(dd<=dis)
                    {
                        addEdge(n+i,j,inf);
                        addEdge(n+j,i,inf);
                    }
                }
            }

            int ret = maxFlow(source,id);

           // cout<<"\n"<<i<<" "<<ret<<" "<<tot<<endl;
            if(ret==tot)
            {
                flag=0;
                printf(" %d",id-1);
            }
        }
        if(flag) printf(" -1");

        printf("\n");

    }

   // cout<<"yes"<<endl;
    return 0;
}
