#include<bits/stdc++.h>
using namespace std;

vector<int> adj[500];


int dir[500], vis[500];

void bfs(int src, int des)
{
    memset(vis, 0, sizeof(vis));
    queue<int> q;

    q.push(src);
    dir[src] = src;
    vis[src] = 1;

    while(!q.empty()){
        int u = q.front();
        //vis[u] = 1;
        q.pop();

        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];

            if(vis[v] == 0){
                dir[v] = u;
                vis[v] = 1;
            if(v == des)
                return;
                q.push(v);
            }
        }
    }

}

int main()
{
    map<string, int> mp;
    map<int,string> mp2;

    int i, j, k;

    string s1, s2;

    int test;

    scanf("%d",&test);

    while(test--){
            int m, n, co =0;

        scanf("%d %d",&m, &n);

        while(m--){
            cin >> s1 >>s2;
            if(mp[s1] == 0){
                mp[s1] = ++co;
                mp2[co] = s1;
            }

            if(mp[s2] == 0){
                mp[s2] =  ++co;
                mp2[co] = s2;
            }

            adj[mp[s1]].push_back(mp[s2]);
            adj[mp[s2]].push_back(mp[s1]);
        }

        while(n--){
            cin >> s1 >> s2;
            memset(dir, 0, sizeof(dir));
            bfs(mp[s1], mp[s2]);
            i = mp[s2];
            vector<string> path;
            path.push_back(mp2[i]);
            while(i != mp[s1]){
               // cout << mp2[i] << endl;
                i = dir[i];
                path.push_back(mp2[i]);
            }

            for(i = path.size() - 1; i >= 0; i--)
                cout << path[i][0];

            cout << endl;
        }

        mp.clear();
        mp2.clear();
        for(i = 0; i< 500; i++)
            adj[i].clear();

        if(test)
            cout << endl;
    }

}
