#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
#define mxx 40000
int dp[mxx];

int longest(int u)
{
    if(dp[u] != -1)
        return dp[u];

    int maxi = 0;

    for(int v = u + 1; v < vec.size(); v++){
        if(vec[v] < vec[u]){
            if(longest(v) > maxi){
                maxi = longest(v);
            }
        }
    }
    dp[u] = maxi + 1;
    return dp[u];
}

int main()
{
    int n, flag = 0, tc = 0,nl = 0;

    while(scanf("%d", &n) == 1){
        if(flag == 1 && n == -1){
            break;
        }
        if(n == -1){
            flag = 1;
           int  ans = 0;
            memset(dp, -1, sizeof(dp));
            for(int i = 0; i < vec.size(); i++){
                ans = max(ans , longest(i));
            }
            if(nl)
                printf("\n");

            nl = 1;

           printf("Test #%d:\n  maximum possible interceptions: %d\n",++tc, ans);
           vec.clear();
        }
        else{
        flag = 0;
        vec.push_back(n);
        }
    }
}
