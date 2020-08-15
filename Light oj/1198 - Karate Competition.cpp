#include<bits/stdc++.h>
using namespace std;
int a[100], b[100], flag[100];
int dp[55][55];
int n;

int fun(int i, int j)
{
	if(i == n || j == n)
	return 0;
	
	if(dp[i][j] != -1)
	return dp[i][j];
	
		int sum = 0;
	
	if(a[i] > b[j]){
		sum = 2 + fun(i + 1, j + 1);
	}
	else if(a[i] == b[j])
	{
		sum = max(sum, 1 + fun(i + 1, j + 1));
		sum = max(fun(i + 1, j), sum);
		//sum = max(fun(i + 1, j + 1), sum);
	}
	else{
		
		sum = max(fun(i, j + 1), sum);
		sum = max(fun(i + 1, j), sum);
	}
	return dp[i][j] = sum;
}

int main()
{
	int test;
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		scanf("%d", &n);
		
		for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
		
		for(int i = 0; i < n; i++)
		scanf("%d", &b[i]);
		
		memset(dp, -1, sizeof(dp));
		
		sort(a, a + n);
		sort(b, b + n);
		
		
			int ans = fun(0, 0);
		
		printf("Case %d: %d\n",tc, ans);
	}
	return 0;
}
