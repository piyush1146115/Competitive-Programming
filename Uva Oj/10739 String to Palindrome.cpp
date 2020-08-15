#include<bits/stdc++.h>
using namespace std;
string  s, a, b;
int dp[1005][1005];

int lcs(int i, int j)
{
    if(i == a.size()|| j == b.size())
    {
        return max((a.size() - i), (b.size() - j));
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
	scanf("%d", &test);

	for(int tc = 1; tc <= test; tc++){
		cin >> a;
		b = a;
		reverse(a.begin(), a.end());
		memset(dp, -1, sizeof(dp));

		int ans = lcs(0, 0);
		a.clear();
		b.clear();

		printf("Case %d: %d\n",tc, ans/2);
	}
	return 0;
}
