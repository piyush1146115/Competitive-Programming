#include<bits/stdc++.h>
using namespace std;
int vis[28][28][28];
int mp[52][5][28];
int n;
int stx, sty, stz;
int fx, fy, fz;


struct st{
	int x, y, z, cost;
};

bool valid(int x, int y, int z)
{
	if(vis[x][y][z] == 1)
	return false;
	
	for(int i = 0; i< n; i++){
		if(mp[i][0][x] == 1 && mp[i][1][y] == 1 && mp[i][2][z] == 1){
			return false;
		}
	}
	return true;
}

int bfs()
{
	st p;
	p.x = stx;
	p.y = sty;
	p.z = stz;
	p.cost = 0;
	
	vis[p.x][p.y][p.z] = 1;
	queue<st> q;
	q.push(p);
	
	while(!q.empty()){
		p = q.front();
		q.pop();
		st pp;
		
		pp = p;
		pp.x = p.x - 1;
		if(pp.x == -1){
			pp.x = 25;
		}
		if(valid(pp.x, pp.y, pp.z)){
			vis[pp.x][pp.y][pp.z] = 1;
			pp.cost = p.cost + 1;
			if(pp.x == fx && pp.y == fy && pp.z == fz){
				return pp.cost;
			}
			q.push(pp);
		}
		
		pp = p;
		pp.x  = (p.x + 1) % 26;
		
		if(valid(pp.x, pp.y, pp.z)){
			vis[pp.x][pp.y][pp.z] = 1;
			pp.cost = p.cost + 1;
			if(pp.x == fx && pp.y == fy && pp.z == fz){
				return pp.cost;
			}
			q.push(pp);
		}
		
		pp = p;
		pp.y  = (p.y + 1) % 26;
		
		if(valid(pp.x, pp.y, pp.z)){
			pp.cost = p.cost + 1;
			vis[pp.x][pp.y][pp.z] = 1;
			if(pp.x == fx && pp.y == fy && pp.z == fz){
				return pp.cost;
			}
			q.push(pp);
		}
		
		pp = p;
		pp.y  = (p.y - 1);
		
		if(pp.y == -1)
		pp.y = 25;
		
		if(valid(pp.x, pp.y, pp.z)){
			pp.cost = p.cost + 1;
			vis[pp.x][pp.y][pp.z] = 1;
			if(pp.x == fx && pp.y == fy && pp.z == fz){
				return pp.cost;
			}
			q.push(pp);
		}
		
		pp = p;
		pp.z  = (p.z - 1);
		
		if(pp.z == -1)
		pp.z = 25;
		
		if(valid(pp.x, pp.y, pp.z)){
			pp.cost = p.cost + 1;
			vis[pp.x][pp.y][pp.z] = 1;
			if(pp.x == fx && pp.y == fy && pp.z == fz){
				return pp.cost;
			}
			q.push(pp);
		}
		
		pp = p;
		pp.z  = (p.z + 1) % 26;
		
		if(valid(pp.x, pp.y, pp.z)){
			pp.cost = p.cost + 1;
			vis[pp.x][pp.y][pp.z] = 1;
			if(pp.x == fx && pp.y == fy && pp.z == fz){
				return pp.cost;
			}
			q.push(pp);
		}
		
	}
	
	return -1; 
}

int main()
{
	int test;
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		
		memset(mp, 0, sizeof(mp));
		memset(vis, 0, sizeof(vis));
		
		string s, t;
		cin >> s >> t;
		stx = s[0] - 'a';
		sty = s[1] - 'a';
		stz = s[2] - 'a';
		
		fx = t[0] - 'a';
		fy = t[1] - 'a';
		fz = t[2] - 'a';
		
	
		scanf("%d", &n);
		string X, Y, Z;
		for(int i = 0; i < n; i++){
			cin >> X >> Y >> Z;
			
			for(int j = 0; j < X.size(); j++)
			mp[i][0][X[j] - 'a'] = 1;
			
			for(int j = 0; j< Y.size(); j++)
			mp[i][1][Y[j] - 'a'] = 1;
			
			for(int j = 0; j< Z.size(); j++)
			mp[i][2][Z[j] - 'a'] = 1;
		}
		
		if(!valid(stx, sty, stz) || !valid(fx, fy, fz))
		{
			printf("Case %d: -1\n",tc);
			continue;
		}
		else if(s == t){
			printf("Case %d: 0\n",tc);
			continue;
		}
		
		int ans = bfs();
		
		printf("Case %d: %d\n",tc, ans);
	}
}
