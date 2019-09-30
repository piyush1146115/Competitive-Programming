#include<bits/stdc++.h>
using namespace std;
#define mxx 12

int vis[mxx][mxx], cost[mxx][mxx], cont[mxx][mxx];

struct st{
	int x, y, cost;
};

int dx[] = {+1, +1, +2, +2, -1, -1, -2, -2};
int dy[] = {+2, -2, +1, -1, +2, -2, +1 , -1};
int row, col;
string s[mxx];

bool valid(int x, int y)
{
	if(x >= 0 && y >= 0 && x < row && y < col && vis[x][y] == 0)
	return true;
	
	return false;
}

void bfs(int x, int y, int n)
{
	cont[x][y]++;
	//cost[x][y]++;
	
	vis[x][y] = 1;
	st p;
	p.x = x;
	p.y = y;
	p.cost = 0;
	
	queue<st> q;
	q.push(p);
	
	while(!q.empty()){
	p = q.front();
	q.pop();
	
		for(int j = 0; j < 8; j++){
			int xx = p.x + dx[j];
			int yy = p.y + dy[j];
			if(valid(xx, yy)){
				vis[xx][yy] = 1;
				st pp;
				pp.x = xx;
				pp.y = yy;
				pp.cost = p.cost + 1;
				int cst = pp.cost/ n;
				if(pp.cost % n != 0)
				cst++;
				
				cost[xx][yy] += cst;				
				cont[xx][yy]++;
				q.push(pp);
			}
		}
}
}

int main()
{
	int test;
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		scanf("%d %d",&row, &col);
		
		memset(cost,0 , sizeof(cost));
		memset(cont, 0, sizeof(cont));
		
		for(int i = 0; i < row; i++)
		cin >> s[i];
		
		
		int cnt = 0;
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col ;j++){
				if(s[i][j] >= '1' && s[i][j] <= '9'){
					int num = s[i][j] - '0';
					memset(vis, 0, sizeof(vis));
					bfs(i, j, num);
					cnt++;
				}
			}
		}
		
		int ans = 1 << 30, flag = 0;
		
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if(cont[i][j] == cnt){
					flag = 1;
					//cout << " x >> " << i << "  y >> " << j << endl;
					ans = min(ans, cost[i][j]);
				}
			}
		}
		
		if(flag)
		printf("Case %d: %d\n",tc, ans);
		else
		printf("Case %d: -1\n",tc);
	}
}
