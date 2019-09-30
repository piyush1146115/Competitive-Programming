#include<bits/stdc++.h>
using namespace std;

int  ara[105], pos[105];   

int main()
{
	int test, n;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){		
		scanf("%d", &n);
		
		for(int i = 1; i <= n; i++)
		scanf("%d", &ara[i]);
		
		int cnt = 0;
		
		for(int i = 1; i <= n; i++){
		if(i != ara[i]){
			for(int j = 1; j <= n; j++){
				if(ara[j] == i){
					swap(ara[i], ara[j]);
					cnt++;
					break;
				}
			}
		}
		}
		
		
	//int ans = cnt/2 + (cnt % 2);
		
		printf("Case %d: %d\n",tc, cnt);
	}
	return 0;
}
