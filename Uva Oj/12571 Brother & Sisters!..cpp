#include<bits/stdc++.h>
using namespace std;
int vis[250], ara[250];
int main()
{
    int n, q, test, i, j, k, ind;

    scanf("%d",&test);

    while(test--){
            memset(vis, 0 , sizeof(vis));
        scanf("%d %d", &n, &q);
        ind = 0;

        for(i = 0; i < n; i++){
            scanf("%d", &j);
            if(j <= 260){
                if(vis[j] == 0){
                    ara[ind++] = j;
                    vis[j] = 1;
                }
            }
        }

    int res, ans = -1223;

    for(i = 0; i < q; i++){
            ans = -1231;
                res = 0;
        scanf("%d", &j);
        for(k = 0; k < ind; k++){
            res = ara[k] & j;
            if(res > ans)
                ans = res;
        }

        printf("%d\n",ans);
    }

    }
    return 0;
}
