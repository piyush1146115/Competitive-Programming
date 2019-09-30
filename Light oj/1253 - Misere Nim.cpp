#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll ara[105];
int main()
{
	int test;
	
	scanf("%d",&test);
	
	for(int tc = 1; tc <= test; tc++){
		int n;
		scanf("%d", &n);
		int flag = 0;
		
		for(int i = 0; i < n; i++){
			scanf("%lld", &ara[i]);
			if(ara[i] != 1)
			flag = 1;
		}
		if(flag){
			ll ans = 0;
			for(int i = 0; i < n; i++)
			ans ^= ara[i];
			
			if(ans)
			printf("Case %d: Alice\n",tc);
			else
			printf("Case %d: Bob\n",tc);
		}
		else{
			if(n % 2 == 0){
				printf("Case %d: Alice\n",tc);
			}
			else
			printf("Case %d: Bob\n",tc);
		}
	}
}
