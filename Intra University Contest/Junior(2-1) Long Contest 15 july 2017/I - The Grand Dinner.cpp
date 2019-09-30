#include<bits/stdc++.h>
using namespace std;

struct st{
	int cap , ind;
	
	bool operator < (const st &p)const{
		return cap > p.cap;
	}
};

st table[105];
int ara[105];
int ans[75][105];

int main()
{
	int n, m;
	
	while(scanf("%d %d", &m, &n) == 2){
		
		if(n == 0 && m == 0)
		break;
		
		for(int i = 0; i < m;i++)
		scanf("%d", &ara[i]);
		
		for(int i = 0; i < n; i++){
		scanf("%d", &table[i].cap);
		table[i].ind = i + 1;
	}
	sort(table, table + n);
	int flag = 0;
	
	/*for(int i = 0; i < n;i++)
	{
		printf("%d ",table[i].cap);
	}*/
	
	for(int i = 0; i < m; i++){
		int temp = 0, val = ara[i];
		for(int j = 0; j < n; j++){
			if(table[j].cap > 0){
				table[j].cap--;
				ans[i][temp] = table[j].ind;
				temp++;
				val--;
			}
			if(val == 0)
			break;
		}
		if(val > 0){
		flag = 1;
		break;
	}
	}
	if(flag)
	printf("0\n");
	else{
		printf("1\n");
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j < ara[i]; j++){
				printf("%d", ans[i][j]);
				if(j != ara[i] - 1)
				printf(" ");
			}
			printf("\n");
		}
	}
	
	}
}
