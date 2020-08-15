#include<bits/stdc++.h>
using namespace std;
#define mxx 35

long long int dp[mxx][mxx], dp2[mxx][mxx][mxx * 2];

string a, b;
long long int ans;

long long int lcs(int i, int j)
{
    if(i == a.size() || j == b.size())
    return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    long long int sum = 0;
    if(a[i] == b[j])
        sum = 1 + lcs(i + 1, j + 1);
    else{
        sum = lcs(i + 1, j);
        sum = max(sum, lcs(i, j + 1));
    }
    dp[i][j] = sum;

    return sum;
}

long long int way(int i, int j, int n)
{
    if(i == a.size() && j == b.size())
    {
        if(n == ans)
            return 1;
        else
            return 0;
    }
    if(n > ans)
    return 0;

    if(i > a.size() || j > b.size())
        return 0;

    if(dp2[i][j][n] != -1)
        return dp2[i][j][n];

         long long int sum = 0;
        if(a[i] == b[j])
            sum =  way(i + 1, j + 1, n + 1);
        else{
            sum += way(i + 1, j, n + 1);
            sum += way(i, j + 1, n + 1);
        }
        dp2[i][j][n] = sum;
        return sum;
}

int main()
{
    int test;

    scanf("%d",&test);

    for(int tc = 1; tc <= test; tc++){

        memset(dp, -1, sizeof(dp));
        memset(dp2, -1, sizeof(dp2));
        cin >> a >> b;

         ans = a.size() + b.size() - lcs(0, 0);
         long long int res = way(0, 0, 0);

         printf("Case %d: %lld %lld\n",tc, ans, res);
    }

}
