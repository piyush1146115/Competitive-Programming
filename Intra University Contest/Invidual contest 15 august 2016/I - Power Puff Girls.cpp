#include<bits/stdc++.h>
using namespace std;
char gr[50][50];
bool vis[50][50];
int cost[50][50], sum;
int fx[] = {+1, -1, +0, +0};
int fy[] = {+0, +0, +1, -1};

void bfs(int a, int b)
{
    queue<int> q;
    int u, v, x, y, i, j;

    q.push(a);
    q.push(b);
    cost[a][b] = 0;

    while(!q.empty()){
        x = q.front();
        q.pop();
        y = q.front();
        q.pop();

        vis[x][y] = 1;

        for(i = 0; i < 4; i++){
            u = x + fx[i];
             v=  y + fy[i];

            if(u >= 0 && v >= 0 && vis[u][v] == 0 && gr[u][v] != '#' && gr[u][v] != 'm'){
                vis[u][v] = 1;
                q.push(u);
                q.push(v);
                cost[u][v] = cost[x][y] + 1;
                if(gr[u][v] == 'h'){
                    sum = max(cost[u][v], sum);
                    return;
                }
            }
        }
    }
}
int main()
{
    int n, i, j, k, test, m, cs = 0;

    scanf("%d",&test);

    while(test--){
 sum = 0;
    scanf("%d %d", &n, &m);

    for(i = 0; i < n; i++){
        cin >> gr[i];
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(gr[i][j] == 'a' || gr[i][j] == 'b' || gr[i][j] == 'c'){
                memset(vis, 0,  sizeof(vis));
               memset(cost, 0, sizeof(cost));

                bfs(i, j);
            }
        }
    }

    printf("Case %d: %d\n",++cs,  sum);
    }
}
