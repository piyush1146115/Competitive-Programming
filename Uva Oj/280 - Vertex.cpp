#include<bits/stdc++.h>
using namespace std;
#define mxx 105
vector<int> g[mxx];

bool vis[mxx];
int cnt;
void dfs(int n)
{
    for(int i = 0; i < g[n].size(); i++) {
        if(vis[g[n][i]] == 0) {
            int	u = g[n][i];
            vis[u] = 1;
            cnt++;
            dfs(u);
        }
    }
}


int main()
{
    int n;

    while(scanf("%d", &n) == 1) {

        if(n == 0)
            break;

        int str;

        while(scanf("%d", &str) == 1) {
            if(str == 0)
                break;

            int m;
            while(scanf("%d" , &m) == 1) {
                if(m == 0)
                    break;
                g[str].push_back(m);
            }
        }

        int q;

        scanf("%d", &q);
        while(q--) {
            int sou;
            scanf("%d", &sou);
            cnt = 0;
            memset(vis, 0, sizeof(vis));
            dfs(sou);

            printf("%d", n - cnt);


            for(int i = 1; i <= n; i++) {
                if(vis[i] == 0)
                {
                    printf(" %d", i);
                }
            }
            printf("\n");
        }
        for(int i = 0; i <= n; i++)
            g[i].clear();

    }

    return 0;
}
