#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
	int test;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		string s;
		cin >> s;
		ll d;
		scanf("%lld", &d);
		
		d = abs(d);
		
		int sz = (int)s.size();
		ll  mul = 1, sum = 0;
		
		for(int i = sz - 1; i >= 0; i--){
			if(s[i] >= '0' && s[i] <= '9'){
			ll n = s[i] - '0';
			n = (mul * n) % d;
			sum = (sum + n) % d;
			mul *= 10;
			mul = mul % d;
		}
		}
		
		if(sum == 0){
			printf("Case %d: divisible\n",tc);
		}
		else
		printf("Case %d: not divisible\n",tc);
		
	}
}
