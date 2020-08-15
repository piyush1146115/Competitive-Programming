#include<bits/stdc++.h>
using namespace std;
int mat[15][105];
int dp[15][105];

int n, m, ans;
vector<int> res;

int fun(int row, int col)
{
    if(row == n || col == m)
        return 0;

        if(dp[row][col] != -1)
            return dp[row][col];

    int ret1, ret2, ret3;
        ret1 = ret2 = ret3 = 9999999;

            int p, q;
            p = row - 1;
            if(p < 0)
                p = n - 1;

            q = row + 1;
            if(q == n)
                q = 0;

            int ret;
            ret1 = mat[row][col] + fun(p,col + 1);
            ret2 = mat[row][col] + fun(q,col + 1);
            ret3 = mat[row][col] + fun(row,col + 1);

    ret = min(ret1, min(ret2, ret3));
    dp[row][col] = ret;
    return dp[row][col];
}


void path(int i, int col)
{
    if(col == m)
        return;

        res.push_back(i + 1);
        ans -= mat[i][col];

            int p, q;
            p = i - 1;
            if(p < 0)
                p = n - 1;

            q = i + 1;
            if(q == n)
                q = 0;

        if(dp[p][col + 1] == ans && dp[q][col + 1] == ans && dp[i][col+ 1] == ans)
            path(min(i, min(p, q)), col + 1);
        else if(dp[p][col + 1] == ans && dp[q][col + 1] == ans)
            path(min(p, q), col + 1);
        else if(dp[p][col + 1] == ans && dp[i][col + 1] == ans)
            path(min(p, i), col + 1);
        else if(dp[q][col + 1] == ans && dp[i][col + 1] == ans)
            path(min(q, i), col + 1);
        else{
            if(dp[i][col + 1] == ans)
                path(i, col + 1);
            else if(dp[p][col + 1] == ans)
                path(p, col + 1);
            else
                path(q , col + 1);
        }
}

int main()
{
    while(scanf("%d %d",&n, &m) == 2){
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d",&mat[i][j]);
            }
        }
        int ret1, ret2, ret3;
         ans = 9999999;
        ret1 = ret2 = ret3 = 9999999;

        for(int i = 0; i < n; i++){
            int p, q;
            p = i - 1;
            if(p < 0)
                p = n - 1;
            q = i + 1;
            if(q == n)
                q = 0;

            ret1 = mat[i][0] + fun(p,1);
            ret2 = mat[i][0] + fun(q,1);
            ret3 = mat[i][0] + fun(i,1);

        dp[i][0] =  min(ret1, min(ret2, ret3));
        ans = min(ans, dp[i][0]);
        }
        int r = ans;
        for(int i = 0; i < n; i++){
         if(dp[i][0] == ans){
           // ans -= mat[i][0];
            path(i, 0);

            //res.push_back(i + 1);
            break;
         }
        }

        printf("%d",res[0]);

        for(int i = 1; i < res.size(); i++)
            printf(" %d",res[i]);
        printf("\n");
        printf("%d\n",r);
        res.clear();
    }
}
