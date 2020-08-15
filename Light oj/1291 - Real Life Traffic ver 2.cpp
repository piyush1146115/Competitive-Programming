#include<bits/stdc++.h>
using namespace std;
#define mxx 10005
vector<int> g[mxx];
int vis[mxx];
int ans;

#define inf 1000000
void dfs(int u)
{
	vis[u] = 1;
	int cnt = 0;
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		cnt++;
		if(vis[v] == 0){
			dfs(v);
		}
	}
	if(cnt == 1)
	ans++;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {
		memset(vis, 0, sizeof(vis));
        //init();
        int n, m;
        
        scanf("%d %d", &n, &m);

        for(int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        ans = 0;
        //tme = 0;

        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i);
            }
        }
        
        
		ans = ans/2 + (ans % 2);
		
        printf("Case %d: %d\n",tc, ans);
        
        for(int i = 0; i <= n; i++)
            g[i].clear();

    }
    return 0;
}
