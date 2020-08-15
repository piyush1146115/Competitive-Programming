#include<bits/stdc++.h>
using namespace std;
#define MAX 1005

vector<int> gr[MAX];
bool vis[MAX];
int lev[MAX], b[MAX];
int n;
int ans = 0;
void dfs(int u, int dep)
{
    vis[u] = 1;
    lev[dep] += b[u];

    ans = max(ans, lev[dep]);

    for(int i = 0; i < (int)gr[u].size(); i++)
    {
        int v = gr[u][i];
        if(vis[v] == 0)
        {
            dfs(v, dep + 1);
        }
    }

}

int main()
{
    int test;
    scanf("%d", &test);

    while(test--)
    {
        scanf("%d", &n);

        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]);
        }
        for(int i = 2; i <= n ; i++)
        {
            int p;
            scanf("%d", &p);
            gr[p].push_back(i);
            gr[i].push_back(p);
        }

        for(int i = 2; i <= n; i++)
        {
            memset(vis, 0 , sizeof(vis));
            memset(lev, 0, sizeof(lev));
            vis[i] = 1;
            ans = 0;
            dfs(1, 0);
            printf("%d\n",ans);
        }
        for(int i = 0; i <= n; i++){
            gr[i].clear();
        }

    }
}
