#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
vector<int> gr[MAX], v1, v2;
bool vis[MAX];

void dfs(int u, int tp)
{
    int tm;
    if(tp == 1)
        tm = 2;
    else
        tm = 1;

    if(tp == 1){
        v1.push_back(u);
    }
    else{
        v2.push_back(u);
    }
    vis[u] = 1;

    for(int i = 0 ; i < gr[u].size(); i++){
        int v = gr[u][i];
        if(vis[v] == 0){
            dfs(v, tm);
        }
    }
}

int main()
{
    long long n;

    scanf("%lld", &n);

    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d %d",&u, &v);
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    dfs(1, 1);

    long long m1 = v1.size();
    long long m2 = v2.size();

    long long pos = m1 * m2;
    long long ans = pos - (n - 1);

    printf("%lld\n",ans);
}
