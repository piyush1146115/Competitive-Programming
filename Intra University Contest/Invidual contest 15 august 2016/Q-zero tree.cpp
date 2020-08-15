#include<bits/stdc++.h>
#define MX 100005
using namespace std;
vector <long long int> v[MX];
long long ps[MX], ng[MX], cost[MX], vis[MX], ans = 0;

void dfs(long long int x)
{
   long long int i, j, k;
    vis[x] = 1;
    for(i = 0; i < v[x].size(); i++){
        j = v[x][i];
        if(vis[j])
            continue;
        dfs(j);
        ps[x] = max(ps[x], ps[j]);
        ng[x] = max(ng[x], ng[j]);
    }

    cost[x] -= ps[x];
    cost[x] += ng[x];
    ans = abs(cost[x]) + ps[x] + ng[x];
    if(cost[x] >= 0)
        ps[x] += cost[x];
    else
        ng[x] += abs(cost[x]);
}

int main()
{
    long long int x, y, i, j, k, n;

        scanf("%lld" , &n);

    for(i  = 0; i < n - 1; i++){
        scanf("%lld %lld", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(i = 1; i <= n; i++)
        scanf("%lld", &cost[i]);

    ans = 0;
    dfs(1);
    cout << ans << endl;
}
