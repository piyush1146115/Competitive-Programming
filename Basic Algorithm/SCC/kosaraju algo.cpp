#include<bits/stdc++.h>
using namespace std;
#define mxx 50
vector<int> g[mxx], r[mxx], ans[mxx];
stack<int> st;
int color[mxx], vis[mxx];

void dfs(int u)
{
    vis[u] = 1;

    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(vis[v] == 0){
            dfs(v);
        }
    }
    st.push(u);
}

void dfs2(int u, int mark)
{
    ans[mark].push_back(u);
    color[u] = 1;

    for(int i = 0; i < r[u].size(); i++){
        int v = r[u][i];
        if(color[v] == 0){
            dfs2(v, mark);
        }
    }
}

int main()
{
    int n, m;

    scanf("%d %d",&n, &m );

    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d",&u, &v);
        g[u].push_back(v);
        r[v].push_back(u);
    }
    memset(color, 0, sizeof(color));
    memset(vis, 0, sizeof(vis));

    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            dfs(i);
        }
    }
    int mark = 0;

    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(color[u] == 0){
         mark++;
         dfs2(u, mark);
        }
    }
    for(int i = 1; i <= mark; i++){
        printf("SCC #%d:\n", i);
        for(int  j = 0; j < ans[i].size(); j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i <= n; i++){
        ans[i].clear();
        g[i].clear();
        r[i].clear();
    }

}
