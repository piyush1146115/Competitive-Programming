#include<bits/stdc++.h>
using namespace std;

vector<long long int> v[1000000], bak, cost[1000000];
bool vis[1000000];

int main()
{
    long long int i, j, k, l, m, n, x, y;
    int flag = 0;

    scanf("%lld %lld %lld", &n, &m, &k);

    for(i = 0; i < m; i++)
    {
        scanf("%lld %lld %lld", &x, &y, &l);
        v[x].push_back(y);
        v[y].push_back(x);
        cost[x].push_back(l);
        cost[y].push_back(l);
    }

    long long ans = 100000000000000;
    if(n == k || k == 0){
        printf("-1\n");
    }
    else{
    for(i = 0; i < k; i++)
    {
        scanf("%lld", &j);
        bak.push_back(j);
        vis[j] = 1;
    }

    for(i = 0; i < bak.size(); i++){
        for(j = 0; j < v[bak[i]].size(); j++){
            if(vis[v[bak[i]][j]] == 0){
                    flag = 1;
                ans = min(ans, cost[bak[i]][j]);
            }
        }
    }

    if(flag == 1){
        printf("%lld\n",ans);
    }
    else{
        printf("-1\n");
    }
    }
    return 0;
}
