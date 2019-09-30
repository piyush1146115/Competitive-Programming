#include<bits/stdc++.h>
using namespace std;
#define  mxx 100005

vector<int> g[mxx];
int vis[mxx];
stack<int> st;

void dfs(int u)
{
   vis[u] = 1;

   for(int i = 0; i < g[u].size(); i++){
    int v = g[u][i];
    if(vis[v] == 0)
        dfs(v);
   }
   st.push(u);
}

 void dfs1(int u)
 {
     vis[u] = 1;

     for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(vis[v] == 0){
            dfs1(v);
        }
     }
 }

int main()
{
 int n, m, test;

 scanf("%d", &test);

 for(int tc = 1; tc <= test; tc++){
    scanf("%d %d", &n,&m);

        memset(vis, 0, sizeof(vis));
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
    }

    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
          dfs(i);
        }
    }
    memset(vis, 0, sizeof(vis));
    int cnt = 0;

    while(!st.empty()){
        if(vis[st.top()] == 0){
                cnt++;
            dfs1(st.top());
        }
        st.pop();
    }

    printf("%d\n",cnt);

    for(int i = 0; i <= n; i++)
        g[i].clear();
 }
}
