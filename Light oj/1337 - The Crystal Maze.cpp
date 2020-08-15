#include<bits/stdc++.h>
using namespace std;
#define mxx 505

string s[mxx];
int row, col;
int vis[mxx][mxx],vis2[mxx][mxx];
int dp[mxx][mxx];
int cnt;

int fx[] = { 0, 1, -1, 0};
int fy[] = { 1, 0, 0, -1};

bool valid(int x, int y)
{
	if(x >= 0 && y >= 0 && x < row && y < col && s[x][y] != '#' && vis[x][y] == 0)
	{
		return true;
	}
	else
	return false;
}

void dfs(int x, int y)
{
	vis[x][y] = 1;
	if(s[x][y] == 'C')
	cnt++;
	
	for(int i = 0; i < 4; i++){
		int xx = x + fx[i];
		int yy = y + fy[i];
		if(valid(xx, yy)){
			dfs(xx, yy);
		}
	}
}

bool valid2(int x, int y)
{
	if(x >= 0 && y >= 0 && x < row && y < col && s[x][y] != '#' && vis2[x][y] == 0)
	{
		return true;
	}
	else
	return false;
}

void dfs2(int x, int y)
{
	vis2[x][y] = 1;
	dp[x][y] = cnt;
	
	for(int i = 0; i < 4; i++){
		int xx = x + fx[i];
		int yy = y + fy[i];
		if(valid2(xx, yy)){
			dfs2(xx, yy);
		}
	}
}

int main()
{
	int test;
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		int q;
		scanf("%d %d %d",&row, &col, &q);
		
		for(int i = 0; i < row; i++)
		cin >> s[i];
		
		memset(vis, 0, sizeof(vis));
		memset(vis2, 0, sizeof(vis2));
		memset(dp, 0, sizeof(dp));
		
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if(vis[i][j] == 0 && s[i][j] == '.'){
						cnt = 0;
						dfs(i, j);
						dfs2(i, j);
				}
			}
		}
		
		printf("Case %d:\n",tc);
		
		while(q--){
			int x, y;
			scanf("%d %d",&x, &y);
			printf("%d\n",dp[x - 1][y - 1]);
		}
	}
}
