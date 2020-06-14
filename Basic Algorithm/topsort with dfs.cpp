#include<bits/stdc++.h>
using namespace std;
#define mxx 20005

int visited[mxx], cycle, taken[mxx];
vector<int> edge[mxx];
vector<int> ans;
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

}

void take(int p)
{
    if(!taken[p]) {
        for(int i = 0; i < edge[p].size(); i++) {
            take(edge[p][i]);
        }

        //ans.push_back(p)
        taken[p] = 1;
    }
}

int main()
{
    int test, tc = 0;
    map<string, int> mp;

    scanf("%d", &test);

    while(test--) {
        int m;
        scanf("%d", &m);

        int cnt = 0;

        memset(taken, 0 , sizeof(taken));
        memset(visited, 0 , sizeof(visited));

        while(m--) {

            string a, b;
            cin >> a >> b;

            if(mp[a] == 0)
                mp[a] = ++cnt;

            if(mp[b] == 0)
                mp[b] = ++cnt;

            edge[mp[b]].push_back(mp[a]);

        }

        cycle = 0;
        int n = cnt;

        for(int i = 1; i <= n; i++)
            visit(i);

        if(cycle)
            printf("Case %d: No\n", ++tc);
        else
            printf("Case %d: Yes\n",++tc);

        mp.clear();

        for(int i = 0; i <= n ; i++)
            edge[i].clear();
    }
    return 0;
}
