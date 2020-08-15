#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ara[10005];
	
	int n, m;
	
	while(scanf("%d %d", &n ,&m) == 2){
		
		memset(ara, 0, sizeof(ara));
		
		for(int i = 0; i < m; i++){
			int k;
			scanf("%d",&k);
			ara[k] = 1;
		}
		vector<int> v;
		
		for(int i = 1; i <= n; i++ ){
			if(ara[i] == 0)
			v.push_back(i);
		}
		
		if(v.size() == 0){
			printf("*\n");
		}
		else{
			printf("%d",v[0]);
			
			for(int i = 1; i < (int)v.size(); i++)
			printf(" %d",v[i]);
			printf("\n");
		}
	}
}
