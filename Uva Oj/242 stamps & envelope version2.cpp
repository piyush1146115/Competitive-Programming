#include<bits/stdc++.h>
using namespace std;

int dp[12][12][1005];
int ans[15];
int S, N, sz;
vector<int> v[15], vec[15];
map<int , int> chk;
int ara[105];

 void fun(int state, int pos, int value)
{
	if(pos == sz || state > S)
	{
	//	chk[value] = 1;
		return;
	}
	
	chk[value]  = 1;
	
	if(dp[state][pos][value] != -1)
	return;
	
	fun(state + 1, pos, value + ara[pos]);
	fun(state, pos + 1, value);
	
	//cout <<" p1-- "  << p1 << " p2-- " << p2 << " p1 + p2-- " << p1 + p2 << " state-- " << state << " pos-- " << pos <<  endl;
	//getchar();
	dp[state][pos][value] = 1;
	return;
}


int main()
{
	while(scanf("%d", &S) == 1){
		
		memset(ans, 0, sizeof(ans));
		
		if(S == 0)
		break;
		
		scanf("%d", &N);
		
		for(int i = 0; i < N; i++){
			int n;
			scanf("%d", &n);
			while(n--){
				int m;
				scanf("%d", &m);
				v[i].push_back(m);
				vec[i].push_back(m);
			}
			sort(v[i].begin(), v[i].end());
		}
		
		//for(int i = 0; i < N; i++){
		//	for(int j = 0; j < v[i].size(); j++)
		//	cout << v[i][j] << " " << endl;
		//}
		
		int mx = -999999;
		
		for(int i = 0; i < N; i++){
			sz = v[i].size();
			memset(dp, -1, sizeof(dp));
			
			for(int j = 0; j < sz; j++)
			ara[j] = v[i][j];
			
			fun(0, 0, 0);
			
			int cnt = 0;
			
			for(int j = 1; ; j++)
				{
					if(chk[j] == 0)
					break;
					
					cnt++;
				}
		//	cout << i << " " << cnt << endl;
			ans[i] = cnt;
			mx = max(mx, cnt);
			chk.clear();
		}
		
		int mm = 999999;
		
		for(int i = 0; i < N; i++){
			
			int ss = v[i].size();
			
			if(ans[i] == mx){
				mm = min(mm, ss);
			}
		}
		
		vector<int> aa;
		
		for(int i = 0; i < N; i++){
			if(ans[i] == mx && v[i].size() == mm){
			//	cout << i << endl;
				aa.push_back(i);
			}
		}
		
		int flag = 1;
		
		if(aa.size() == 1){
			printf("max coverage = %d :",mx);
			
			for(int k = 0; k < v[aa[0]].size(); k++)
			printf(" %d",vec[aa[0]][k]);
			
			printf("\n");
			
		}
		else{
			for(int i = mm - 1; i >= 0; i--){
				int mn = 999999;
				
				for(int j = 0; j < aa.size(); j++){
				  mn = min(mn, v[aa[j]][i]);	
				}
				
				int ct = 0, indx = 0;
				
				for(int j = 0; j < aa.size(); j++){
				  if(mn == v[aa[j]][i]){
					ct++;
					indx = aa[j];  
				  }	
				}
				
				if(ct == 1){
					flag = 0;
					printf("max coverage = %d :",mx);
			
			for(int k = 0; k < vec[indx].size(); k++)
			printf(" %d",vec[indx][k]);
			
			printf("\n");
			break;
				}
				
				if(flag == 0)
				break;
			}
			
			if(flag){
				printf("max coverage = %d :",mx);
			
			for(int k = 0; k < vec[aa[0]].size(); k++)
			printf(" %d",vec[aa[0]][k]);
			
			printf("\n");
			}
		}
		
		aa.clear();
		
		for(int i = 0; i <= N; i++){
		v[i].clear();
		vec[i].clear();
	}
	}
}
