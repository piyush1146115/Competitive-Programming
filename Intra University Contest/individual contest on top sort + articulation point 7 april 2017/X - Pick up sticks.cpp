#include<bits/stdc++.h>
using namespace std;
#define mxx 1000005

int visited[mxx], cycle;
vector<int> edge[mxx];
stack<int> ans;
//cycle check
void visit(int p)
{
    if(visited[p] == 2 || cycle)
        return;

    //we won't process anything if we have already found a cycle
    if(visited[p] == 1)
    {
        cycle = 1;
        return;
    }

    visited[p] = 1;

    for(int i = 0 ; i < edge[p].size(); i++)
        visit(edge[p][i]);

    visited[p] = 2;
    ans.push(p);
}

int main()
{

    int n, m;

    while(scanf("%d %d", &n, &m) == 2){
        int u, v;
        if(m == 0 && n == 0)
            break;

        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < m; i++){
           scanf("%d %d",&u, &v);
        edge[u].push_back(v);
        }
        cycle = 0;
        for(int i = 1; i <= n; i++){
            if(visited[i] == 0){
                visit(i);
            }
            if(cycle)
                break;
        }
        if(cycle){
            printf("IMPOSSIBLE\n");

            while(!ans.empty()){
                ans.pop();
            }
        }
        else{
            while(!ans.empty()){
                printf("%d\n",ans.top());
                ans.pop();
            }
        }
        for(int i = 0; i <= n; i++)
            edge[i].clear();
    }

    return 0;
}
