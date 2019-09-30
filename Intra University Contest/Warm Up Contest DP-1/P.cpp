#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll coin[] = {50, 25 ,10 , 5,  1};
ll dp[7500][7];

ll fun(ll sum, int pos)
{
	if(pos == 5){
		if(sum == 0)
			return 1;
		else
			return 0;
	}
	if(dp[sum][pos] != -1)
		return dp[sum][pos];
	ll ret1 = 0, ret2 = 0;
	
	if(sum - coin[pos] >= 0){
	 ret1 = fun(sum - coin[pos], pos);
 }
	 ret2 = fun(sum, pos + 1);
	 
	dp[sum][pos] = ret1 + ret2;
	
	return dp[sum][pos];
}
int main()
{
	ll n;
	memset(dp, -1, sizeof(dp));
	
	while(scanf("%lld",&n) == 1){
		ll ans = fun(n,0);
		printf("%lld\n",ans);
	}
}
