#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pii pair<int, int>
#define mp make_pair
#define pb push_back

ll ara[1005];

int main()
{
	ll  test;
	
	cin >> test;
	
	ll cs = 0;
	
	while(test--){
		ll n, m;
		
		scanf("%lld",&n);
		
		for(int i = 0; i < n; i++)
		{
			scanf("%lld", &ara[i]);
			
		}
		
		
		printf("Case %lld:\n",++cs);
		
		scanf("%lld",&m);
		
		for(int i = 1; i <= m; i++){
			ll k;
		scanf("%lld",&k);
		ll ans = 0;
		for(int j = 0 ; j < n; j++){
			ans ^= ara[j] % (k + 1);
		}
		printf("Query %d: ",i);
		if(ans == 0)
		printf("Lose\n");
		else
		printf("Win\n");
		}
	}
	
	
}
