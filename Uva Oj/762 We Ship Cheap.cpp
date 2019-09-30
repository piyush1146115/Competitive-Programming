#include<bits/stdc++.h>
using namespace std;

#define MX 100005
#define pb push_back

vector<int> edge[MX], path;
map<string, int> mp;
map<int, string> mp2;

bool vis[MX];
int p[MX], n, cost[MX];

void reset()
{
    for(int i = 0; i < n + 5; i++){
        edge[i].clear();
        vis[i] = 0;
        //p[i] = 0;
        cost[i] = 0;
    }

    path.clear();
    mp.clear();
    mp2.clear();

}


void bfs(int so, int des)
{

    queue <int> q;
    q.push(so);
    vis[so] = 1;
    cost[so] = 0;
    p[so] = so;

    if(so == des)
        return;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = 0; i < edge[u].size();i++ )
        {
            if(vis[edge[u][i]] == 0){

                int v = edge[u][i];
                vis[v] = 1;
                cost[v] = cost[u] + 1;
                p[v] = u;

                if(v == des)
                    return;

                q.push(v);
            }
        }
    }
    return;
}


int main()
{
        int i, j, k, ed, flag = 0;
        string s1, s2;


    while(scanf("%d", &ed) == 1){

        if(flag)
        printf("\n");

        flag = 1;

        n = 0;
        while(ed--){

        cin >> s1 >> s2;

        if(mp[s1] == 0){
            n++;
            mp[s1] = n;
            mp2[n] = s1;
        }

        if(mp[s2] == 0){
            n++;
            mp[s2] = n;
            mp2[n] = s2;
        }

        edge[mp[s1]].pb(mp[s2]);
        edge[mp[s2]].pb(mp[s1]);

        }

        cin >> s1 >> s2;

          if(mp[s1] == 0){
            n++;
            mp[s1] = n;
            mp2[n] = s1;
        }
        if(mp[s2] == 0){
            n++;
            mp[s2] = n;
            mp2[n] = s2;
        }

        bfs(mp[s1], mp[s2]);

        k = mp[s2];

        if(vis[k] == 0){
            printf("No route\n");
        }
        else{
            path.pb(k);
            int s = mp[s1], now;
            now = k;
            while(now != s){
                    if(now != k)
                    path.push_back(now);
                now = p[now];

                path.push_back(now);
            }

            for(i = path.size() - 1; i >= 0; i -= 2){
                cout << mp2[path[i] ]  << " " << mp2[path[i - 1]] << endl;
            }

        }
         reset();
        }

    return 0;
}
