#include<bits/stdc++.h>
using namespace std;
vector<int> ed[50];
int vis[50], cost[50];

void reset()
{
    for(int i = 0; i < 40; i++){
        vis[i] = 0;
        cost[i] = 0;
    }
}

int bfs(int s, int e)
{
    reset();

    queue<int> q;
    q.push(s);
    cost[s] = 0;
    vis[s] = 1;

    if(s == e)
        return 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = 0; i < ed[u].size(); i++){

                int v = ed[u][i];


            if(vis[v] == 0){

                cost[v] = cost[u] + 1;
                vis[v] = 1;
                if(v == e)
                    return cost[v];

                q.push(v);
            }
        }
    }
}

int main()
{
    int i, s, e, n, m, ans, cs = 0;

//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

    while(scanf("%d", &n) == 1){

        while(n--){
            scanf("%d", &m);
            ed[1].push_back(m);
            ed[m].push_back(1);
        }

        for(i = 2; i <= 19; i++){
            scanf("%d", &n);

                while(n--){
                    scanf("%d", &m);
                    ed[m].push_back(i);
                    ed[i].push_back(m);
                }
        }

        scanf("%d", &n);

    printf("Test Set #%d\n" ,++cs);

        while(n--){
            scanf("%d %d", &s, &e);
            ans = bfs(s, e);
            printf("%2d to %2d:%2d\n",s, e, ans);
        }

    printf("\n");

        for(i = 0; i<= 21; i++)
            ed[i].clear();
    }
    return 0;
}
