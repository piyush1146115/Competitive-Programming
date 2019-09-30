#include<bits/stdc++.h>
using namespace std;

vector<int> gr[50];
bool vis[50];

void dfs(int n)
{
    int i;

    if(vis[n] == 1)
        return;
    vis[n] = 1;
    for(i = 0; i < gr[n].size(); i++)
        dfs(gr[n][i]);
}
int main()
{
    int i, j, k, test, l, a, b, cont;
    string s;

    scanf("%d", &test);

    while(test--){
            cont = 0;
        cin >> s;
        getchar();
        l = s[0] - 'A';
        while(1){
            getline(cin, s);
            if(s == "")
                break;
            a = s[0] - 'A';
            b = s[1] - 'A';
            gr[a].push_back(b);
            gr[b].push_back(a);
        }

        memset(vis, 0, sizeof(vis));

        for(i = 0; i <= l; i++){
            if(vis[i] == 0 ){
                cont++;
                for(j = 0; j < gr[i].size(); j++)
                    if(vis[gr[i][j]] == 0)
                        dfs(gr[i][j]);
            }
        }

    printf("%d\n", cont);

    if(test)
        printf("\n");

        for(i = 0; i < 50; i++)
            gr[i].clear();
    }
    return 0;
}
