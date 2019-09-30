#include<bits/stdc++.h>
using namespace std;
#define mxx 1005
int ara[10][mxx];
int dp[10][mxx];

int n, x;

int fun(int i, int j)
{
	if(j == n){
	if(i == 0)
		return 0;
		else
		return 1 << 28;
	}
	if(dp[i][j] != -1)
	return dp[i][j];
	
	int ans = 1 << 30;
	
	if(i == 0){
			ans = min(ans, (60 - ara[i][j]) + fun(i + 1, j + 1));
			ans = min(ans, (30 - ara[i][j]) + fun(i, j + 1));
	}
	else if(i == 9){
			ans = min(ans, (20 - ara[i][j]) + fun(i - 1, j + 1));
			ans = min(ans, (30 - ara[i][j]) + fun(i, j + 1));
	}
	else{
		
			ans = min(ans, (20 - ara[i][j]) + fun(i - 1, j + 1));
			ans = min(ans, (30 - ara[i][j]) + fun(i, j + 1));
			ans = min(ans, (60 - ara[i][j]) + fun(i + 1, j + 1));
	}
	return dp[i][j] = ans;
}

int main()
{
	int test;
	
	scanf("%d", &test);
	
	while(test--){
		memset(dp, -1, sizeof(dp));
		scanf("%d", &x);
		
		n = x / 100;
		
		for(int i =  9; i >= 0; i--){
			for(int j = 0; j < n; j++){
				scanf("%d",&ara[i][j]);
			}
		}
		
		int ans = fun(0, 0);
		
		printf("%d\n\n",ans);
	}
	return 0;
}
