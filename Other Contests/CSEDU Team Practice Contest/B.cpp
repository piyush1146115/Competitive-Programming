#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mxx 1000005
#define inf 10000000000000
#define inff 1000000000000000000
ll dp[mxx][5];
int dx[] = { 1, 1, 0, 1};
int dy[] = { 1, -1, 1, 0};

int row, col = 2;
int g[mxx][5];

bool valid(int x, int y)
{
	if(x >= 0 && y >= 0 && x < row && y <= col)
	return true;
	else
	return false;
}

ll fun(int r, int c)
{
	if(r == row - 1 && c == 1)
	return g[r][c];
	
	if(dp[r][c] != inff)
	return dp[r][c];
	
		ll ans = inf;
	
	for(int i = 0; i < 4; i++){
		int xx = r + dx[i];
		int yy = c + dy[i];
		if(valid(xx, yy)){
			ans = min(ans, g[r][c] + fun(xx, yy));
		}
	}
	return dp[r][c] = ans;
}

int main()
{
	int tc = 0;
	
	while(scanf("%d",&row) == 1){
		if(row  == 0)
		break;
		for(int i = 0; i < row ; i++){
			for(int j = 0; j < 3; j++){
				scanf("%d",&g[i][j]);
				dp[i][j] = inff;
			}
		}
		//memset(dp, - 1, sizeof(dp));
		
		ll ans = fun(0, 1);
	//	cout << ans << endl;
	printf("Case %d: %lld\n",++tc, ans); 
	}
}
/*
 * 4
13 7 5
7 13 6
14 3 12
15 6 16
0
* */
