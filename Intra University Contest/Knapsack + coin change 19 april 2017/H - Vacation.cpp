#include<bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[105][105];

int fun(int p1, int p2)
{
    if(p1 == s1.size())
        return 0;
    if(p2 == s2.size())
        return 0;

    if(dp[p1][p2] != -1)
        return dp[p1][p2];

    int v1 = 0, v2 = 0, v3 = 0;

    if(s1[p1] == s2[p2]){
        v1 = 1 + fun(p1 + 1, p2 + 1);
    }
    else{
        v2 = fun(p1, p2 + 1);
        v3 = fun(p1 + 1, p2);
    }

    dp[p1][p2] = max(v1, max(v2, v3));

    return dp[p1][p2];
}

int main()
{
    int tc = 0;

    while(getline(cin ,s1)){
        if(s1 == "#")
            break;

        getline(cin , s2);

        memset(dp, -1, sizeof(dp));

        int ans = fun(0, 0);

        printf("Case #%d: you can visit at most %d cities.\n",++tc,ans);
    }
}
