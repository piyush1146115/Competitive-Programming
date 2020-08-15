#include<bits/stdc++.h>
using namespace std;
#define mxx 1005
#define ll long long

ll ara[mxx], n, l, c;
ll dp[mxx], dp2[mxx];

ll fun(int pos)
{
	if(pos == n)
	return 0;
	
	ll ans = 1 << 30;
	ll sum = 0;
	
	if(dp[pos] != -1)
	return dp[pos];
	
	for(int i = pos; i < n; i++){
		sum += ara[i];
		if(sum <= l){
			ans = min(ans, 1 + fun(i + 1));
		}
		else
		break;
	}
	
	return dp[pos] = ans;
}

ll dis(int pos)
{
	if(pos == n)
	return 0;
	
	ll ans = 1 << 30;
	
	ll sum = 0;
	
	if(dp2[pos] != -1)
	return dp2[pos];
	
	for(int i = pos; i < n; i++){
		sum += ara[i];
		if(sum <= l){
			ll ret =  1 + fun(i + 1);
			if(ret == fun(pos)){
				ll C;
				if(l == sum)
				C = 0;
				else if(l - sum > 10){
					ll dif = (l - sum) - 10;
					C = dif * dif;
				}
				else{
					C = -c;
				}
				ans = min(ans, C + dis(i + 1));
			}
		}
		else
		break;
	}
	return dp2[pos] = ans;
}

int main()
{
	int tc = 0;
	
	while(scanf("%lld", &n) == 1){
		
		if(n == 0)
			break;
		
		scanf("%lld %lld",&l, &c);
		
		for(int i = 0; i < n ; i++)
		scanf("%lld", &ara[i]);
		
		memset(dp, -1,sizeof(dp));
		memset(dp2, -1,sizeof(dp2));
		
		ll ans = fun(0);
		ll diss = dis(0);
		
		if(tc)
		printf("\n");
		
		printf("Case %d:\nMinimum number of lectures: %lld\nTotal dissatisfaction index: %lld\n",++tc,ans, diss);
	}
	return 0;
}
