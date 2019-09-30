#include<bits/stdc++.h>
using namespace std;
#define MAX 5005
vector<int> g[MAX];
bool vis[MAX];
stack<int> st;

void dfs(int u)
{
    vis[u] = 1;

    for(int i = 0; i < (int)g[u].size(); i++){
        int v = g[u][i];
        if(vis[v] == 0){
            dfs(v);
        }
    }
    st.push(u);
}

void dfs2(int u)
{
    vis[u] = 1;

    for(int i = 0; i < (int)g[u].size(); i++){
        int v = g[u][i];
        if(vis[v] == 0){
            dfs2(v);
        }
    }
 //   st.push(u);
}

int main()
{
    int n, m, s;

    scanf("%d %d %d",&n, &m, &s);

    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
    }

    dfs(s);
    int cnt = 0;

    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            dfs(i);
        }
    }
    memset(vis,0, sizeof(vis));

    dfs2(s);

    //for(int i = 1; i <= n; i++){
      while(!st.empty()){
            int v = st.top();
            st.pop();
        if(vis[v] == 0){
            cnt++;
            dfs2(v);
        }
      }


    printf("%d\n", cnt);

}
