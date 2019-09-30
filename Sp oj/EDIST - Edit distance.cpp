#include<bits/stdc++.h>
using namespace std;
#define mxx 2005
int dp[mxx][mxx];
//char a[mxx], b[mxx];
string a, b;
int l1 , l2;

int lcs(int i, int j)
{
    if(i == l1 || j == l2)
    {
        return max((l1 - i), (l2 - j));
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    int ret = 9999999;
    if(a[i] == b[j])
    {
        ret = min(ret, lcs(i + 1, j + 1));
    }
    else
    {
        ret = min(ret, 1 + lcs(i + 1, j));
        ret = min(ret, 1 + lcs(i, j + 1));
        ret = min(ret, 1 + lcs(i + 1, j + 1));
    }

    dp[i][j] = ret;
    return ret;
}

int main()
{
    int test;
    cin >> test;
   // scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {
        //scanf("%s %s",a, b);
        cin >> a >> b;
        memset(dp, -1,sizeof(dp));

        l1 = a.size();
        l2 = b.size();

        int ans = lcs(0, 0);
       // printf("%d\n",ans);
       cout << ans << endl;
    }
    return 0;
}
