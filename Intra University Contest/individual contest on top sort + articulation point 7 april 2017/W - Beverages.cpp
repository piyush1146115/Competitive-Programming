#include<bits/stdc++.h>
using namespace std;
#define mxx 105

map<string, int> mp1;
map<int, string> mp2;
vector<int> g[mxx], ans;
int visited[mxx];

int n, m;

void dfs(int u)
{
    visited[u] = 1;

    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(visited[v] == 0){
            dfs(v);
        }
    }
    ans.push_back(u);
}

int main()
{
    int tc = 0;
    while(scanf("%d", &n) == 1){
        string s;

        for(int i = 1; i <= n; i++){
            cin >> s;
            mp1[s] = i;
            mp2[i] = s;
        }
        string a, b;
        scanf("%d", &m);
        memset(visited, 0, sizeof(visited));
        if(tc)
            printf("\n");

        for(int i = 0; i < m; i++){
            cin >> a >> b;
        //    si
        g[mp1[a]].push_back(mp1[b]);
        }

        for(int i = 1; i <= n; i++){
            if(visited[i] == 0){
                dfs(i);
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order: ",++tc);

        cout << mp2[ans[n - 1]];
        for(int i = n - 2; i >= 0; i--){
            cout << " " << mp2[ans[i]];
        }

        printf(".\n");
        ans.clear();

        for(int i = 0; i <= n; i++)
            g[i].clear();

        mp1.clear();
        mp2.clear();
    }
}
