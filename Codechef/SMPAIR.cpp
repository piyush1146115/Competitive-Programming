#include<bits/stdc++.h>
using namespace std;
#define mxx 100005

int ara[mxx];

int main()
{
	int test, n;
	
	scanf("%d", &test);
	
	while(test--){
		scanf("%d", &n);
		int min1 = 10000000, min2 = 10000000;
		
		for(int i = 0; i < n ; i++){
			scanf("%d", &ara[i]);
		}
		
		for(int i = 0; i < n; i++){
			if(min1 > ara[i]){
				min2 = min(min1, min2);
				min1 = ara[i];
			}
			else if(min2 > ara[i]){
				min2 = ara[i];
			}
		}
		int ans;
		ans =  min1 + min2;
		printf("%d\n",ans);
	}
}
