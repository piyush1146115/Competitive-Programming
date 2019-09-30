#include<bits/stdc++.h>
using namespace std;
#define MX 2505

vector <int> ed[MX];
bool vis[MX];
int cost[MX], mx[MX], ans[3];

void reset()
{
    for(int i = 0; i < MX; i++){
        vis[i]  = 0;
        cost[i] = 0;
        mx[i] = 0;
    }
    ans[0] = 0;
}
void bfs(int s)
{
//    mx = mxl = -1;
    reset();
    vis[s] = 1;
    cost[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < ed[u].size(); i++){
                int v = ed[u][i];
            if(vis[v] == 0){
                cost[v] = cost[u] + 1;
                vis[v] = 1;
                mx[cost[v]]++;
              //cout << ans[0]<< " "  << mx[cost[v]]<< "ok \n" ;
                    if(ans[0] < mx[cost[v]]){
                    ans[0] = mx[cost[v]];
                    ans[1] = cost[v];
                }
                q.push(v);
            }
        }
    }
}

int main()
{
    int e, n, i, m, k;

    while(scanf("%d", &n) == 1){

        for(i = 1; i <= n; i++){
            scanf("%d", &e);
            while(e--){
                scanf("%d", &k);
                ed[i].push_back(k + 1);
            }
        }

        scanf("%d", &m);

        while(m--){
            scanf("%d", &k);
            bfs(k + 1);
            if(ans[0] == 0){
                printf("0\n");
            }
            else{
                printf("%d %d\n", ans[0], ans[1]);
            }
        }
        for(i = 0; i < n+ 2; i++)
            ed[i].clear();
    }
}
