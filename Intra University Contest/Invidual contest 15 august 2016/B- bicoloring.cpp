#include<bits/stdc++.h>
using namespace std;
vector <int> v[250];
int co[250] , vis[250], flag, n;

void dfs(int x)
{
    int i, j;
    if(x == n || vis[x] == 1)
        return;

        vis[x] = 1;

        for(i = 0; i < v[x].size(); i++){
            if(co[v[x][i]] == co[x]){
                flag = 0;
            }
            if(co[x] == 0){
                co[v[x][i]] = 1;
            }
            else{
                 co[v[x][i]] = 0;
            }
            dfs(v[x][i]);
        }
}



int main()
{
    int  i, j, k, l, x, y;

    while(scanf("%d", &n) == 1 && n != 0){
        scanf("%d", &l);

        for(i = 0; i < l; i++){
            scanf("%d %d", &x, &y);
            if(x == y)
                continue;

            v[x].push_back(y);
            v[y].push_back(x);
        }
        memset(co, -1, sizeof(co));
        memset(vis, 0, sizeof(co));
        flag = 1;
        for(i = 0; i < n; i++){
                        if(co[i] == -1)
                            co[i] = 0;

                        vis[i] = 1;

                    for(j = 0; j < v[i].size();j++ ){
                        if(co[i] == co[v[i][j]]){
                            flag = 0;
                        }

                        if(co[i] == 0){
                            co[v[i][j]] = 1;
                        }
                        else{
                            co[v[i][j]] = 0;
                        }

                        if(vis[v[i][j]] == 0){
                            dfs(v[i][j]);
                        }
                    }

            }

        if(flag)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");

        for(k = 0; k <= n; k++)
            v[k].clear();
    }
    return 0;
}
