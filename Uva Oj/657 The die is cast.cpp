#include<bits/stdc++.h>
using namespace std;
bool vis[52][52];
char gr[52][52];
int co, row, col;
void dfs(int i, int j);

void f(int i, int j)
{
    if(i  < 0 || j < 0 || i >= row || j >= col || gr[i][j] == '.')
    return;
    if(gr[i][j] == 'X')
    {
        co++;
        dfs(i, j);
    }

        gr[i][j] = '.';
        f(i + 1, j);
        f(i - 1, j);
        f(i, j + 1);
        f(i, j - 1);
}

void dfs(int i, int j)
{
        if(i  < 0 || j < 0 || i >= row || j >= col || gr[i][j] != 'X')
            return;

       gr[i][j] = '*';
        vis[i][j] = 1;
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j -1);
        dfs(i, j + 1);
}

int main()
{
   //freopen("input.txt" , "r", stdin);
    int  i, j, k, cs = 0;
    vector<int> ans;

    while(scanf("%d %d",&col, &row) == 2){

        if(row == 0 && col == 0)
            break;

        for(i = 0; i < row; i++)
            scanf("%s", gr[i]);

        memset(vis, 0, sizeof(vis));

        for(i = 0; i < row; i++){
            for(j = 0; j < col; j++){
                if(gr[i][j] != '.' ){
                  //  vis[i][j] = 1;
                    co = 0;
                    f(i, j);
                    ans.push_back(co);
                }
            }
        }
        sort(ans.begin(), ans.end());

        printf("Throw %d\n%d", ++cs, ans[0]);
        for(i = 1; i < ans.size(); i++){
            printf(" %d",ans[i]);
        }
        printf("\n\n");
        ans.clear();
    }
}
