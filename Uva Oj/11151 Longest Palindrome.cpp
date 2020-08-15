#include<bits/stdc++.h>
using namespace std;
#define mxx 1005
string a, b;
int dp[mxx][mxx];

int lcs(int i, int j)
{
    if(i == a.size() || j == b.size())
        return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

    int ans = 0;

    if(a[i] == b[j]){
        ans = 1 + lcs(i + 1, j + 1);
    }
    else{
        ans = max(ans,lcs(i + 1, j));
        ans = max(ans, lcs(i, j + 1));
    }
    return dp[i][j] = ans;
}

int main()
{
   int test;
   scanf("%d", &test);
   getchar();

   while(test--){

    memset(dp, -1, sizeof(dp));
    getline(cin , a);
    b = a;
    reverse(a.begin(), a.end());

   int ans = lcs(0, 0);

   printf("%d\n",ans);
   }
}
