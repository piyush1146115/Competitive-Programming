#include<bits/stdc++.h>
using namespace std;
#define mxx 2005
#define pb push_back
int c1, c2;
int dp[mxx][mxx];

vector<int> g[mxx], v1, v2;
bool vis[mxx];
int color[mxx];
int b, c, bicolor;

void isbicolor(int u)
{
    int c;
    if(color[u] == 1)
        c = 2;
    else
        c = 1;
    vis[u] = 1;

    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if(vis[v] == 1)
        {
            if(color[v] != c)
            {
                bicolor = 0;
                break;
            }
        }
        else
        {
            color[v] = c;
            isbicolor(v);
        }
    }
}


void dfs(int u)
{
    if(color[u] == 1)
        c1++;
    else
        c2++;
    vis[u] = 1;

    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];

        if(vis[v] == 0)
        {
            dfs(v);
        }
    }
}

int fun(int pos, int sum)
{
    if(pos == v1.size()){
        int dif = (b + c) - sum;
        if(dif >= c && sum >= b)
            return 1;
        else
            return 0;
    }

    if(dp[pos][sum] != -1)
        return dp[pos][sum];

    int p1 = 0, p2 = 0;

    p1 = fun(pos + 1, sum + v1[pos]);
    p2 = fun(pos + 1, sum + v2[pos]);

    dp[pos][sum] = p1|p2;
    return dp[pos][sum];
}

int main()
{
    int a, test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {

        scanf("%d %d %d", &b, &c, &a);

        for(int i = 0; i < a; i++)
        {
            int u, v;
            scanf("%d %d",&u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        memset(vis, 0,  sizeof(vis));
        memset(color, 0,  sizeof(color));
        bicolor = 1;

        for(int i = 1; i <= (b + c); i++)
        {
            if(vis[i] == 0)
            {
                color[i] = 1;
                isbicolor(i);
            }
        }

        if(bicolor)
        {
            memset(vis, 0, sizeof(vis));
            memset(dp, -1, sizeof(dp));

            for(int i = 1; i <= (b + c); i++)
            {
                if(vis[i] == 0)
                {
                    c1 = 0;
                    c2 = 0;
                    dfs(i);
                    v1.push_back(c1);
                    v2.push_back(c2);
                }
            }

            int ans = fun(0, 0);

            if(ans)
                printf("yes\n");
            else
                printf("no\n");

        }
        else
        {
            printf("no\n");
        }

        for(int i = 0; i <= (b +c); i++){
            g[i].clear();
        }
        v1.clear();
        v2.clear();
    }
}
