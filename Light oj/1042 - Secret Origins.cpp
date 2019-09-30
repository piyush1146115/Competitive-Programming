#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll ara[40];

int main()
{
	ll s = 1;
	ara[0] = 1;
	for(int i = 1; i <= 35; i++){
		s *= 2;
		ara[i] = s;
	}
	
	int test;
	ll arr[40];
	scanf("%d", &test);
	
	for(int tc =1 ; tc <= test; tc++){
		ll n;
		scanf("%lld",&n);
		memset(arr, 0, sizeof(arr));
		ll sum = n, cnt = 0;
		
		for(int i = 33; i >= 0; i--){
			if(sum >= ara[i]){
				arr[i] = 1;
				sum -= ara[i];
				cnt++;
			}
		}
		//cout << sum << endl;
		
		int flag = 0, pos;
		
		for(int i = 0; i < 35; i++){
			if(arr[i] == 1){
				flag = 1;
			}
			if(flag == 1 && arr[i] == 0){
				pos = i;
				arr[pos - 1] = 0;
				arr[pos] = 1;
				break;
			}
		}
		int cn = 0;
		for(int i = 0; i < pos; i++){
			if(arr[i] == 1){
				cn++;
			}
		}
		ll ans = ara[cn] - 1;
		
		for(int i = pos; i < 35; i++){
			if(arr[i] == 1){
				ans += ara[i];
			}
		}
		printf("Case %d: %lld\n",tc, ans);
	}
}
