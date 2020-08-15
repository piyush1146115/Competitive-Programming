#include<bits/stdc++.h>
using namespace std;
#define mxx 105
vector<int> g[mxx];
int n, m, flag;
int status[mxx];
int cnt = 0, con = 0;
int dis[mxx], mp[mxx];

void dfs(int pos, int d)
{
	if(dis[pos] == 0)
	dis[pos] = d;
	con++;
		
	if(d % 2 == 0)
	cnt++;
	
	status[pos] = 1;
	
	for(int i = 0; i < (int)g[pos].size(); i++){
		int v = g[pos][i];
		//cout << " pos " << pos << " v " << v <<  " d " << d << " status " << status[v] << endl;
		//getchar();	
		if(status[v] == 0){
			status[v] = 1;
			dfs(v, d + 1);
		}
		else if(status[v] == 1){
			int dif = abs(dis[pos] - dis[v]);
			if(dif % 2 == 0 && dif != 0){
				//cout <<  " pos " << pos << " dis " << dis[pos] << " dis[v] " << dis[v] <<  endl;
	//getchar();
				flag = 1;
			}
		}
		else{
			if(d % 2 == 1 && dis[v] % 2 != 0){
				cnt++;
			}
		}
	}
	
	status[pos] = 2;
}

int main()
{
	int test;
	scanf("%d",&test);
	
	for(int tc = 1; tc <= test; tc++){
		scanf("%d %d",&n, &m);
		flag = 0;
		
		for(int i = 0; i < m; i++){
			int u, v;
			scanf("%d %d",&u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		memset(status, 0, sizeof(status));
		cnt = 0, con = 0;
		memset(dis, 0, sizeof(dis));
		
		
		dfs(1, 0);
		int ans;
		
		//cout << cnt << endl;
		
		if(flag){
			ans = con;
		}
		else{
			ans = cnt;
			
		}
		
		if(con == 1)
		ans = 0;
		
		printf("Case %d: %d\n",tc, ans);
		
		for(int i = 0; i <= n; i++)
		g[i].clear();
	}
}

/*.
5 5

1 2
2 3
3 4
1 4
3 5
* 


7 7

1 2
2 3
3 4
3 5
4 6
5 6
4 7
*/
