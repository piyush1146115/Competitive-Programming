#include<bits/stdc++.h>
using namespace std;
map<string, int> mp;
vector<int> edge[1000];
 bool vis[1000];
 int cost[1000];

 int bfs(int s, int d)
 {
     queue <int> q;
     q.push(s);
     vis[s] = 1;
     cost[s] = 0;
     if(s == d)
        return 0;

     while(!q.empty()){
            int u = q.front();
            q.pop();

        for(int i = 0; i < edge[u].size(); i++){

            if(vis[edge[u][i]] == 0){
                int v = edge[u][i];

                vis[v] = 1;

                cost[v] = cost[u] + 1;

                if(v == d)
                    return cost[v];

                q.push(v);
            }
        }
     }
 }

int main()
{
    string s, st[205];
    int i, j, k, c = 0, test, flag;

    cin >> test;

    while(test--){
        flag = 0;
        while(cin >> s){

        if(mp[s] == 0){
            st[c] = s;
            c++;
            mp[s] = c;
        }

        if(s == "*")
        {
            flag = 1;
            int co = 0;

            for(i = 0; i < c - 1; i++){
                for(j = i + 1; j < c; j++){
                        if(st[i].size() != st[j].size())
                        continue;
                           co = 0;

                    for(k = 0; k < st[i].size();k++){
                        if(st[i][k] != st[j][k]){
                           co++;
                        }
                    }

                    if(co == 1){
                        edge[mp[st[i]]].push_back(mp[st[j]]);
                        edge[mp[st[j]]].push_back(mp[st[i]]);
                    }
                }
            }

            getchar();

            while(getline(cin, s)){

                if(s.size() == 0)
                    break;

                stringstream ss(s);
                string s2[3], t;

                k = 0;
                while(ss >> t){
                    s2[k] = t;
                    k++;
                }
                //cout << s2[0] << " " << s2[1] << endl;

                int res = bfs(mp[s2[0]], mp[s2[1]]);
                cout << s2[0] << " " << s2[1] << " " << res << endl;

                for(i = 0; i <= 200; i++)
                    vis[i] = 0;
            }
        }

if(flag){
            c = 0;
        mp.clear();
        for(i = 0; i < 202; i++){
            edge[i].clear();
            st[i].clear();
            vis[i] = 0;
        }

    break;
}
    }
if(test)
    printf("\n");

}
    return 0;
}
