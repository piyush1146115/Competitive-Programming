#include<bits/stdc++.h>
using namespace std;
int rn[205][205], used[205][205];

int main()
{
	int test, n;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
	scanf("%d", &n);
	vector<int> em[105];
	
	memset(used, 0, sizeof(used));
	
	for(int i = 1; i <= n; i++){
	for(int j = 1; j <= n; j++){
	int u;
	scanf("%d", &u);
	em[i].push_back(u);
	}
}
	for(int i = n + 1; i <= n*2; i++){
		for(int j = 1; j <= n; j++){
			int u;
			scanf("%d", &u);
		rn[i][u] = j;
		}
	}
	
	map<int, int> ans;
	queue<int> q;
	
	for(int i = 1; i <= n; i++){
	q.push(i);
	}
	
		while(!q.empty()){
		int f = q.front();
			for(int i = 0; i < em[f].size(); i++){
			if(used[f][i] == 0){
				
				used[f][i] = 1;
				if(ans[em[f][i]] == 0){
				ans[em[f][i]] = f;
				q.pop();
				break;
				}
				else{
					int v = ans[em[f][i]];
					if(rn[em[f][i]][f] < rn[em[f][i]][v]){
					ans[em[f][i]] = f;
					q.pop();
					q.push(v);
					break;
					}
				}
			}
			}
		}
		
		printf("Case %d:", tc);
		
		for(int i = n + 1; i <= 2 * n; i++){
			printf(" ");
		printf("(%d %d)",ans[i], i);
		}
		printf("\n");
		
	}
}
