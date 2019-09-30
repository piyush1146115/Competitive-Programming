#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e13
ll n, k, p;
ll dp[1005][2005];
ll a[2005], b[2005];
 
ll fun(int i, int j)
{
	if(i == n)
	return 0;
	if(j == k)
	return inf;
	if(dp[i][j] != -1)
	return dp[i][j];
	
	ll sum = inf;
	 sum = min(sum, max(abs(a[i] - b[j]) + abs(b[j] - p) , fun(i + 1, j + 1)));
	sum = min(sum, fun(i, j + 1));
	
	return dp[i][j] = sum;
}


int main()
{
	
	memset(dp, -1, sizeof(dp));
	
	scanf("%lld %lld %lld", &n, &k, &p);
	
	for(int i = 0; i < n; i++)
	scanf("%lld", &a[i]);
	
	for(int i = 0; i < k; i++)
	scanf("%lld", &b[i]);
	
	sort(a, a + n);
	sort(b, b + k);
	
	ll ans = fun(0, 0);
	
	printf("%lld\n",ans);
	
}

