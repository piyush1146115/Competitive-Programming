#include<bits/stdc++.h>
using namespace std;
vector<int>v[1005];
queue<int>q;
int level[1005];

void BFS()
{
    int top, i, j, k;
    while(!q.empty())
    {
        top = q.front();
        q.pop();
        for(i = 0; i < v[top].size(); i++){
            if(level[v[top][i]] == -1){
                level[v[top][i]] = level[top] + 1;
                q.push(v[top][i]);
            }
        }
    }
}
int main()
{
    int i, j, test, k, n, rel;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &rel);
        memset(level, -1, sizeof(level));

        while(rel--){
            scanf("%d %d", &j, &k);
            v[j].push_back(k);
            v[k].push_back(j);
        }
        level[0] = 0;
        q.push(0);
        BFS();

        for(i = 1; i < n; i++){
            printf("%d\n",level[i]);
        }
        for(i = 0; i <= 1000; i++)
            v[i].clear();

        if(test)
            printf("\n");
    }
    return 0;
}
