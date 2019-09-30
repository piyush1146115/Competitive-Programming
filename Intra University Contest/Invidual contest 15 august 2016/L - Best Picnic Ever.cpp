#include<bits/stdc++.h>
using namespace std;
int ara[1005];
vector<int> vec[1005], ans;
map<int, int> mp;

bool vis[1005];

void dfs(int n)
{
    if(vis[n] == 1)
        return;
//cout << n << endl;
    vis[n] = 1;
    ans.push_back(n);
    for(int i = 0;  i < vec[n].size(); i++)
    {
        dfs(vec[n][i]);
    }
}

int main()
{
    int k, n, m, u , v, i, j, test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        scanf("%d %d %d", &k, &n, &m);

        for(i = 0; i < k; i++)
            scanf("%d", &ara[i]);

        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            vec[u].push_back(v);
        }

        for(i = 0; i < k; i++)
        {
            mp[ara[i]]++;
            ans.clear();
            memset(vis, 0, sizeof(vis));
            vis[ara[i]] = 1;
            for(j = 0; j < vec[ara[i]].size(); j++)
            {
                if(vis[vec[ara[i]][j] ]== 0)
                    dfs(vec[ara[i]][j]);
            }
            for(int l = 0 ; l < ans.size(); l++)
                mp[ans[l]]++;
        }
        int co = 0;
        for(i = 1; i <= n; i++)
            if(mp[i] == k)
            {
                co++;
            }
        printf("Case %d: %d\n", ++cs, co);
        for(i = 0; i <= n; i++)
        {
            vec[i].clear();
        }
        mp.clear();
    }
}
