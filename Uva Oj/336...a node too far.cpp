#include<bits/stdc++.h>
#define inf 10000000
using namespace std;
int level[15000];
vector <int> mat[15000];
void bfs(int node)
{
    for(int i = 0; i < 15000; i++)
        level[i] = -1;

    queue <int> q;
    q.push(node);
    level[node] = 0;
    while(!q.empty()){
        int u = q.front();
        for(int i = 0; i < mat[u].size(); i++){
            if(level[mat[u][i]] == -1){
                level[mat[u][i]] = level[u] + 1;
               // printf("%d\n", level[mat[u][i]]);
                q.push(mat[u][i]);
            }
        }
        q.pop();
    }
}
int main()
{

   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "wt", stdout);
    int i, NC, cse = 0;
    set <int> s;

    while(scanf("%d", &NC), NC){

        for(i = 0; i < NC; i++){
            int x, y;

            scanf("%d %d",&x, &y);
            s.insert(x);
            s.insert(y);
            mat[x].push_back(y);
            mat[y].push_back(x);
        }
        int node, ttl, cont ;
        while(scanf("%d %d", &node, &ttl), node || ttl){
            cont = 0;
            bfs(node);
            cse++;
            set <int> :: iterator it;
            for(it = s.begin(); it != s.end(); it++){
                if(level[*it] > ttl || level[*it] == -1)
                    cont++;
              // printf("%d %d\n", *it, level[*it]);
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cse,cont, node, ttl);
        }
        s.clear();
        mat[15000].clear();
    }
    return 0;
}
/*
#include<bits/stdc++.h>

using namespace std;
map< int, int > visited;

void BFS(int s, map< int, vector< int > >G)
{
    queue< int >q;
    q.push(s);
    visited[s] = 0;
    while(!q.empty())
    {
        int top = q.front();
        for(int i=0; i<G[top].size(); i++)
        {
           int n = G[top][i];
           if(!visited.count(n))
           {
               visited[n] = visited[top] + 1;
               q.push(n);
           }
        }
        q.pop();
    }
}



int main()
{
    int edges, cases=0;
    while(scanf("%d",&edges)==1 & edges!=0)
    {
        map< int,vector< int > >G;
        for(int i=0; i<edges; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int ttl, source;
        while(scanf("%d %d", &source, &ttl)==2)
        {
            if(source==0 && ttl==0) break;
            map< int, int>::iterator it;
            visited.clear();
            BFS(source,G);
            int count=0;
            for(it=visited.begin(); it!=visited.end();++it)
            {
                //cout<<(*it).first<<' '<<(*it).second<<endl;
                if((*it).second>ttl){
                    ++count;
                }
            }
            //cout<<G.size()<<' '<<visited.size()<<endl;
            count = count + G.size()-visited.size();
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cases,count, source, ttl);
        }
    }
    return 0;
}
*/
