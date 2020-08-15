#include<bits/stdc++.h>
using namespace std;
#define Mx 30005
vector<int> v[Mx], cost[Mx];
int vis[Mx];
int mx, leaf, sum;

void dfs(int n, int wt)
{
    if(vis[n] == 1)
        return;
    vis[n] = 1;

    for(int i = 0; i < v[n].size(); i++){

        if(vis[v[n][i]] == 0){
                sum = wt + cost[n][i];
                //cout << sum <<" "  << n << endl;
              //  getchar();
            if(sum > mx){
                mx = sum;
                leaf = v[n][i];

            }
              dfs(v[n][i], sum);
            //        cout << mx << endl;
        }
    }
}
int main()
{
    int i, j, k, l, test, n, cs = 0;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);

        for(i = 1;i < n; i++){
            scanf("%d %d %d",&j, &k, &l);
            v[j].push_back(k);
            v[k].push_back(j);
            cost[j].push_back(l);
            cost[k].push_back(l);
        }
        memset(vis, 0, sizeof(vis));
        mx = 0;
        dfs(0, 0);
        memset(vis, 0, sizeof(vis));
        mx = 0;
        dfs(leaf, 0);

        //cout << mx << endl;
        printf("Case %d: %d\n", ++cs, mx);

        for(i = 0; i <=n; i++){
            v[i].clear();
            cost[i].clear();
        }
    }
}
