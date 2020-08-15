#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mxx 100005

ll ara[mxx], n;

bool fun(ll m)
{
	ll dif;
	
	for(int i = 1; i <= n; i++){
		dif = ara[i] - ara[i - 1];
		if(dif > m)
		return 0;
		if(dif == m)
		m--;
	}
	
	return 1;
}
int main()
{
	int test;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		
		scanf("%lld", &n);
		
		for(int i = 1; i <= n; i++)
		scanf("%lld", &ara[i]);
		
		ll lo = 1, hi = 1000000005, ans;
		
		while(lo <= hi){
			ll mid = (lo + hi)/2;
			
			if(fun(mid)){
				ans = mid;
				hi = mid - 1;
			}
			else{
				lo = mid + 1;
			}
		}
		printf("Case %d: %lld\n",tc, ans);
	}
	
	return 0;
	
}
