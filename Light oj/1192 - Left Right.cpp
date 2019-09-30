#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll ara[2005];

int main()
{
	int test;
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		int k;
		scanf("%d",&k);
		ll m, n;
		
		for(int i = 0; i < k ; i++){
		
		scanf("%lld %lld", &m, &n);
		ara[i] = n - m - 1;
	}
		
		ll ans = 0;
		for(int i = 0; i < k ; i++){
			//ll dif = ara[i + 1] - ara[i];
			ans = ans ^ ara[i];
		}
		
		if(ans){
			printf("Case %d: Alice\n",tc);
		}
		else{
			printf("Case %d: Bob\n",tc);
		}
	}
	
}
