#include<bits/stdc++.h>
using namespace std;
char grid[102][102];
int visit[102][102];
int m, n, cont;

void func(int i, int j)
{
    if(i >= m || j >= n)
        return;
    if(i < 0 || j < 0 )
        return;

        if(visit[i][j] == 0 && grid[i][j] == '@'){
            visit[i][j] = 1;

            func(i,j + 1);
            func(i, j - 1);
            func(i + 1, j);
            func(i - 1, j);
            func(i + 1, j + 1);
            func(i + 1, j - 1);
            func(i - 1, j + 1);
            func(i - 1, j - 1);

        }

}

int main()
{
    int i , j;
    ///freopen("input.txt","r",stdin);

    while(scanf("%d %d", &m, &n) == 2 && m != 0)
    {
        cont = 0;
        memset(visit,0, sizeof(visit));

        for(i = 0; i < m; i++)
                scanf("%s", grid[i]);



        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(visit[i][j] == 0 && grid[i][j] == '@'){
                    cont++;
                func(i, j);
                }
            }
        }
        cout << cont << endl;
    }

}
