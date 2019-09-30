#include<bits/stdc++.h>
using namespace std;
#define MAX 150
#define INF 10000000

int source, sink,par[MAX],vis[MAX], cost[MAX][MAX], total;
 
 
int BFS()
{
    int pathcap, i, cur, now;
 
    queue<int> q;
    pathcap = INF;
    memset(vis, false, sizeof(vis));
    memset(par, -1, sizeof(par));
 
 
    q.push(source);
 //   tot = 6*N + M +  3;
 //   debug3(N, M, tot);
    while(!q.empty())
    {
 
        cur = q.front(); q.pop();
    //    debug2(cur, tot);
        if(cur== sink) break;
 
        for(i =1; i < total ; i++){
          // debug3(cur, i, c[cur][i]);
            if(cost[cur][i]<= 0 || vis[i]) continue;
            par[i] = cur;
            vis[i] = true;
       //     debug3(cur, i, par[i]);
            q.push(i);
        }
    }
 
    int prv;
 
    now = sink;
    while(par[now] > -1){
        prv = par[now];
      //  debug2(now, prv);
      //  getchar();
        if(now == source){
            break;
        }
        pathcap = min(pathcap, cost[prv][now]);
        now = prv;
    }
 
    now = sink;
    while(par[now] > -1){
        prv = par[now];
        if(now == source){
            break;
        }
        cost[prv][now] -= pathcap;
        cost[now][prv] += pathcap;
        now = prv;
    }
 
    if(pathcap== INF) pathcap = 0;
 
    return pathcap;
}
 
 
int max_flow()
{
    int ans,flow;
 
    ans = 0;
 
    while(1){
        flow = BFS();
       // debug1(flow);
        if(flow == 0) break;
        ans+= flow;
    }
 
    return ans;
}
 
    int main() {
        //__FastIO;   //Be aware to use it!
       
        int test,u, v, w,  M, W, k;
        
        scanf("%d", &test);
       
        for(int tc = 1; tc <=  test; tc++){
            memset(cost, 0, sizeof(cost));
            
            scanf("%d %d", &M, &W);
           
            for(int i= 2 ; i <=  M - 1; i++){
                scanf("%d", &k);
                cost[i][i + M] = k;
                cost[i  + M][i] = k;
            }
           
            for(int  i = 0; i < W; i++){
                scanf("%d %d %d", &u, &v, &w);
                if(u == 1 || u == M){
                    cost[u][v] = w;
                }
                else{
                    cost[u + M][v] = w;
                }
                
               
                if(v == 1 || v == M){
                    cost[v][u] = w;
                }
                else{
                    cost[v + M][u] = w;
                }  
            }
           
            source = 1;
            sink = M;
            total = M*2 + 2;
            int ans = max_flow();
           
            printf("Case %d: %d\n",tc, ans);
        }
 
        return 0;
    }

