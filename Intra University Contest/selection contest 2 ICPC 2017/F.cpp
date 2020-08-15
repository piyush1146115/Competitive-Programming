#include<bits/stdc++.h>
using namespace std;
#define mxx 305
int ara[mxx][mxx];
int row[100000], col[100000];
int main()
{
	int r,c;
	
	while(scanf("%d %d", &r, &c) == 2){
	int cnt = 0;
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cnt++;
			row[cnt] = i;
			col[cnt] = j;
			scanf("%d",&ara[i][j]);
		}
	}
	
	int flag = 1;
	
	for(int i = 0; i < r; i++){
		int k = row[ara[i][0]];
		for(int j = 0; j < c; j++){
			if(row[ara[i][j]] != k){
				flag = 0;
				break;
			}
		}
		if(flag == 0)
		break;
	}
	
	for(int i = 0; i < c; i++){
		int k = col[ara[0][i]];
		for(int j = 0; j < r; j++){
			if(col[ara[j][i]] != k){
				flag = 0;
				break;
			}
		}
		if(flag == 0)
		break;
	}
	
	cnt = 0;
	int ans;
	
	if(flag != 0){
		
		for(int i = 0; i < r; i++){
			if(row[ara[i][0]] != i)
			cnt++;
		}
		if(cnt % 2 == 1)
		cnt++;
		
		ans = (cnt/2);
		
		cnt = 0;
		
		for(int i = 0; i < c; i++){
			if(col[ara[0][i]] != i)
			cnt++;
		}
		if(cnt % 2 == 1)
		cnt++;
		
		ans += (cnt/2);
	}
	
	if(flag == 0){
		printf("*\n");
	}
	else{
		printf("%d\n",ans);
	}
}
}
