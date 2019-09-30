#include<bits/stdc++.h>
using namespace std;

int fx[] = { 0, 1, -1, 0};
int fy[] = { 1, 0, 0, -1};
string s[25];
int vis[25][25];
int n, m;

bool valid(int x, int y)
{
	if(x >= 0 && y >= 0 && x < n && y < m && s[x][y] != '#' && vis[x][y] == 0)
	{
		return true;
	}
	else
	return false;
}

int dfs(int x, int y)
{
	vis[x][y] = 1;
	
	int sum = 0;
	for(int i = 0; i < 4; i++){
		int xx = x + fx[i];
		int yy = y + fy[i];
		if(valid(xx, yy))
		sum += (1 + dfs(xx, yy));
	}
	return sum;
}

int main()
{
	int test;
	scanf("%d" ,&test);
	
	for(int tc = 1; tc <= test; tc++){
		scanf("%d %d",&m, &n);
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i++)
		cin >> s[i];
		
		int stx, sty;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(s[i][j] == '@'){
					stx = i;
					sty = j;
					break;
				}
			}
		}
		int ans = 1 + dfs(stx, sty);
		
		printf("Case %d: %d\n",tc, ans);
	}
}
