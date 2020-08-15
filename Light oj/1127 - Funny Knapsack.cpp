#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[35];
ll n, w;
vector<ll> a, b;

void makea(ll m)
{
	for(int i = 0; i < (1 << m); i++){
		ll sum = 0;
		for(int j = 0; j < m; j++){
			if((i & (1 << j))){
				sum += ara[j];
			}
		}
		a.push_back(sum);
	}
}

void makeb(ll m)
{
	for(int i = 0; i < (1 << m); i++){
		ll sum = 0;
		for(int j = 0; j < m; j++){
			if((i & ( 1 << j))){
				sum += ara[j + n/2];
			}
		}
		b.push_back(sum);
	}
}

ll bin()
{
	ll ans = 0;
	
	sort(b.begin(), b.end());
	
	for(int i = 0; i < (int)a.size(); i++){
		ll need = w - a[i];
		ll up = upper_bound(b.begin(), b.end(), need) - b.begin();
		ans += up;
	}
	a.clear();
	b.clear();
	return ans;
}

int main()
{
	int test;
	scanf("%d",&test);
	
	for(int tc = 1; tc <= test; tc++){
		scanf("%lld %lld", &n, &w);
		
		for(int i = 0; i < n; i++)
		scanf("%lld",&ara[i]);
		
		makea(n/2);
		makeb(n - n/2);
		
		ll ans = bin();
		
		printf("Case %d: %lld\n",tc, ans);
	}
}
