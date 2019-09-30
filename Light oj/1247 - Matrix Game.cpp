#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll ara[105];

int main()
{
	int test;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		int r, c;
		
		scanf("%d %d", &r, &c);
		memset(ara, 0, sizeof(ara));
		
		for(int i = 0; i < r; i++){
			ll k;
			for(int j = 0; j < c; j++){
				scanf("%lld",&k);
				ara[i] += k;
			}
		}
		
		ll ans = 0;
		
		for(int i = 0; i < r; i++)
		ans ^= ara[i];
		
		if(ans)
		printf("Case %d: Alice\n",tc);
		else
		printf("Case %d: Bob\n",tc);
	}
}
