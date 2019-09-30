#include<bits/stdc++.h>
using namespace std;
#define mxx 205
int k;
vector<int> v[mxx];
int dp[mxx];

int longest(int u)
{
    if(dp[u] != -1)
        return dp[u];
    int maxi = v[u][2];

    for(int i =0; i  < k; i++){
        if(v[i][0] < v[u][0] && v[i][1] < v[u][1]){
            maxi = max(maxi, v[u][2] + longest(i));
        }
    }
    return dp[u] = maxi;

}

int main()
{
    int n, tc = 0;
    while(scanf("%d", &n) == 1){
        if(n == 0)
            break;
        k = 0;
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++){
            int a, b, c;
            scanf("%d %d %d",&a, &b, &c);
            v[k].push_back(a);
            v[k].push_back(b);
            v[k].push_back(c);
            k++;

            v[k].push_back(c);
            v[k].push_back(b);
            v[k].push_back(a);
            k++;

            v[k].push_back(a);
            v[k].push_back(c);
            v[k].push_back(b);
            k++;

            v[k].push_back(b);
            v[k].push_back(a);
            v[k].push_back(c);
            k++;

            v[k].push_back(c);
            v[k].push_back(a);
            v[k].push_back(b);
            k++;

            v[k].push_back(b);
            v[k].push_back(c);
            v[k].push_back(a);
            k++;
        }
        int ans = 0;

        for(int i = 0; i < k; i++){
            ans = max(ans, longest(i));
        }
        printf("Case %d: maximum height = %d\n",++tc, ans);

        for(int i = 0; i < 200; i++)
            v[i].clear();
    }
return 0;
}
