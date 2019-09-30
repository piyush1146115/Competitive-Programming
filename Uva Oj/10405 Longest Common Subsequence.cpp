#include<bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[1005][1005];

int lcs(int i, int j)
{
    if(i == s1.size() || j == s2.size())
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

        int mx = 0;
    if(s1[i] == s2[j])
    {
        return 1 + lcs(i + 1, j + 1);
    }
    else{
        mx = max(mx, lcs(i, j + 1));
        mx = max(mx, lcs(i + 1, j));
    }

    return dp[i][j] =  mx;
}

int main()
{
    while(getline(cin , s1)){
        getline(cin , s2);

        memset(dp, -1, sizeof(dp));
        int ans = lcs(0, 0);

        printf("%d\n",ans);
    }
    return 0;
}
