#include<bits/stdc++.h>
using namespace std;
#define mxx 1005
int dp[mxx][mxx * 6];
int MAX[mxx], wgt[mxx], n;

int fun(int pos, int sum)
{
	//cout << pos <<" " << sum << endl;
	//getchar();
	
	if(sum < 0)
	return -999999;
	if(sum == 0)
	return 0;
	
	if(pos == n)
	return 0;
	
	if(dp[pos][sum] != -1)
	return dp[pos][sum];
	
	int p1 = 0, p2 = 0, p3 = 0;
	
	p1 = 1 + fun(pos +1 , min((sum - wgt[pos]), MAX[pos]));
	p2 = fun(pos + 1, sum);
	
	//p3 = fun(pos + 1, MAX[pos]);
	
	return dp[pos][sum] = max(p3,max(p1, p2));
}

int main()
{
	while(scanf("%d", &n) == 1){
		if(n == 0)
		break;
		
		memset(dp, - 1, sizeof(dp));
		
		for(int i = 0; i < n;i++)
		scanf("%d %d", &wgt[i], &MAX[i]);
		int ans = fun(0, 6000);
		
		printf("%d\n",ans);
	}
	return 0;
}
