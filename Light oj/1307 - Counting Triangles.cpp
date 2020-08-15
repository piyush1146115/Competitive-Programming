#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[2005];
ll sum;

int bin(int b , int e)
{
	int lo = b, hi = e;
	int ans = -1;
	
	while(lo <= hi){
		int mid = (lo + hi)/2;
		if(ara[mid] < sum){
			ans = mid;
			lo = mid + 1;
		}
		else{
			hi = mid - 1;
		} 
		
	}
	return ans;
}
int main()
{
	int test;
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		int n;
		scanf("%d",&n);
		//vector<ll> v;
		
		for(int i = 0; i < n; i++){
			scanf("%lld",&ara[i]);
		}
		//sort(v.begin(), v.end());
		sort(ara, ara+ n);
		ll ans = 0;
		for(int i = 0; i < n - 2; i++){
			for(int j = i + 1; j < n - 1; j++){
				 sum = ara[i] + ara[j];
				//ll up = upper_bound(v.begin(), v.end(), sum - 1)- v.begin();
				//cout << " i >> " << i << " j >> " <<j << " sum >> " << sum << " up >> " << up << endl;
				//getchar();
				int up = bin(j + 1, n - 1);
				if(up > j){
					ans += (up - j);
				}
			}
		}
		
		printf("Case %d: %lld\n",tc, ans);
	}
	return 0;
}
