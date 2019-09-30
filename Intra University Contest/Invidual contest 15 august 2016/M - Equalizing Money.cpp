#include<bits/stdc++.h>
using namespace std;
int n, sum, cost[1005], vis[1005];
vector <int> v[1005], ans;

void dfs(int x)
{
    int i;
    if(vis[x] == 1)
        return;

        sum += cost[x];
        ans.push_back(x);
    vis[x] = 1;

    for(i = 0; i < v[x].size(); i++)
        dfs(v[x][i]);

}

int main()
{
    int test, i, j, cs = 0, m, x, y;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &m);
        memset(vis,0,  sizeof(vis));
        for(i = 1; i  <= n; i++){
            scanf("%d",&cost[i] );
        }

        while(m--){
            scanf("%d %d", &x, &y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        int flag = 1;
        for(i = 1; i <= n; i++){
            if(vis[i] == 0){
                sum = 0;
                ans.clear();
                dfs(i);
                int sz = ans.size();
                if(sum % sz == 0){

                    for(j = 0; j < ans.size(); j++){
                        cost[ans[j]] = sum / sz;
                    }
                }
                else{
                    flag = 0;
                }
            }
            if(flag == 0)
                break;
        }
        for(i =1; i <= n; i++){
            if(cost[i] != cost[1]){
                flag = 0;
                break;
            }
        }

        if(flag)
            printf("Case %d: Yes\n", ++cs);
        else
            printf("Case %d: No\n", ++cs);

        for(i = 0; i <=n ; i++)
            v[i].clear();
    }
}
