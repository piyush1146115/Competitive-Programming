#include<bits/stdc++.h>
using namespace std;
int mat[20][20];
int dp[(1 << 16) + 5][20];
int n;
int Set(int N, int pos)
{
    return N = N | (1 << pos);
}

bool check(int N, int pos)
{
    return (bool) (N & (1 << pos));
}

int call(int mask, int pos)
{
    if(pos == n)
        return 0;
    if(mask == (1 << n) - 1)
        return 0;
   if(dp[mask][pos] != -1)
       return dp[mask][pos];

    int ret = 0;
    for(int i = 0; i < n; i++){
        if(check(mask, i) == 0){
            ret =max(ret, mat[pos][i] + call(Set(mask, i), pos + 1));
        }
    }

    dp[mask][pos] = ret;
    return ret;
}

int main()
{
    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++){
        scanf("%d", &n);
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n;j++){
                scanf("%d", &mat[i][j]);
            }
        }

        int ans = call(0, 0);

        printf("Case %d: %d\n",tc, ans);
    }
    return 0;
}
