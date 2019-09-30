#include<bits/stdc++.h>
using namespace std;
int taken[500], indegree[500];
int main()
{
    vector <int> take[500], lis;
    int n, m, i, j, k, a, b, mx;

    while(scanf("%d %d",&n, &m) == 2){
            if(m == 0 && n == 0){
                break;
            }
            memset(indegree, 0, sizeof(indegree));
            memset(taken, 0, sizeof(taken));
    mx = -1;
        for(i = 1; i <= m; i++){
                cin >> a >> b;
            take[b].push_back(a);
            indegree[b]++;
            mx = max(indegree[b], mx);
        }
    if(m == 0){
    for(i = 1; i <= n; i++)
        lis.push_back(i);
    }
        for(i = 0; i <= mx; i++){
            for(j = 1; j <=n;j++){
                if(indegree[j] == i){
                    lis.push_back(j);
                }
            }
        }

        printf("%d",lis[0]);
        for(i = 1; i < lis.size(); i++){
            printf(" %d",lis[i]);
        }
        printf("\n");

        for(i = 0; i < 500; i++)
        take[i].clear();
        lis.clear();

    }
    return 0;
}
