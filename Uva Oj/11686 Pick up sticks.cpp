#include<bits/stdc++.h>
using namespace std;
int indegree[1000005];
vector <int>  ans, take[1000005];
queue <int> q;
int main()
{

    int n, m, i, j, k, a, b, mx;

    while(scanf("%d %d",&n, &m) == 2){

            if(m == 0 && n == 0){
                break;
            }
            memset(indegree, 0, sizeof(indegree));
            //memset(taken, 0, sizeof(taken));

        for(i = 1; i <= m; i++){
                cin >> a >> b;
            take[a].push_back(b);
            indegree[b]++;
    //        mx = max(indegree[b], mx);
        }

            for(j = 1; j <=n;j++){
                if(indegree[j] == 0){
                    q.push(j);
                }
            }

        while(!q.empty()){
            int f = q.front();
               q.pop();
            ans.push_back(f);
            //cout <<f << endl;

            int sz = take[f].size();
            for(i = 0; i < sz; i++){
                indegree[take[f][i]]--;
                if(indegree[take[f][i]] == 0){
                    //ans.push_back(take[f][i]);
                    q.push(take[f][i]);
                }
            }
        }

    if(ans.size() != n){
        printf("IMPOSSIBLE\n");
    }
    else{
     for(i = 0; i < ans.size(); i++){
        printf("%d\n",ans[i]);
     }
    }

        for(i = 0; i <= n; i++)
        take[i].clear();
        ans.clear();

    }
    return 0;
}
