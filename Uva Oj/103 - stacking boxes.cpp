#include<bits/stdc++.h>
using namespace std;
vector<int> vec[35];
int n, k, dp[35];
int dir[35];

bool compare(vector<int> a, vector<int> b)
{

    for(int i = 0; i < b.size(); i++)
    {
        if(a[i] <= b[i])
            return false;
    }

    return true;
}

int longest(int u)
{
    if(dp[u] != -1)
        return dp[u];

    int maxi = 0;
    for(int v = 0; v < n; v++)
    {
        if(v == u)
            continue;
        if(compare(vec[v], vec[u]))
        {
            if(longest(v) > maxi)
            {
                maxi = longest(v);
                dir[u] = v;
            }
        }
    }

    dp[u] = maxi + 1;
    return dp[u];
}

int main()
{
    while(scanf("%d %d",&n, &k) == 2)
    {
        memset(dp, - 1, sizeof(dp));
        memset(dir, - 1, sizeof(dir));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < k; j++)
            {
                int m;
                scanf("%d",&m);
                vec[i].push_back(m);
            }
        }

        for(int i = 0; i < n; i++)
            sort(vec[i].begin(), vec[i].end());

        int lis = 0, start;

        for(int i = 0; i < n; i++)
            if(longest(i) > lis)
            {
                start = i;
                lis = longest(i);
            }

        cout << lis << endl << start + 1;

        while(dir[start] != -1){
            printf(" %d",dir[start] + 1);
            start = dir[start];
        }
        printf("\n");

        for(int i = 0; i < n; i++)
            vec[i].clear();
    }
return 0;
}
