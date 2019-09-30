#include<bits/stdc++.h>
using namespace std;
#define mxx 105
vector<int> g[mxx];
int vis[mxx];
int cnt = 0;

void dfs(int u)
{
    vis[u] = 1;
    cnt++;

    for(int i = 0; i < g[u].size(); i++){
        if(vis[g[u][i]] == 0)
        dfs(g[u][i]);
    }
}

int main()
{
    int n;

    while(scanf("%d", &n) == 1){
        if(n == 0)
            break;

            cnt = 0;
        int m;
       for(int i = 1; i <= n; i++){
        scanf("%d", &m);

        while(m--){
            int u;
            scanf("%d", &u);
            g[i].push_back(u);
        }
       }

        int ans = 0, res = 1;

        for(int i = 1; i <= n; i++){
        memset(vis, 0, sizeof(vis));
                cnt = 0;
                dfs(i);
                if(cnt > ans){
                    ans = cnt;
                    res = i;
                }
            //cout << i << " " << g[i].size() <<" " << ans <<"  " <<cnt << endl;

        }

        printf("%d\n",res);

        for(int i = 0; i <= n; i++)
            g[i].clear();

    }
    return 0;
}
