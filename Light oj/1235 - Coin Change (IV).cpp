#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ara[25];
ll n, k;
vector<ll> a, b;

void makea(ll m)
{
	for(int i = 0; i < (1 << m) ; i++){
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
		
		for(int j = 0; j < m;j++){
			if(i & (1 << j)){
				sum += ara[n/2 + j];
			}
		}
		b.push_back(sum);
	}
}


int bin()
{
	sort(b.begin(), b.end());
	
	for(int i = 0; i < (int)a.size(); i++){
		ll need = k - a[i];
		if(need < 0)
		continue;
		
		ll up = upper_bound(b.begin(), b.end(), need) - b.begin();
		ll lo = lower_bound(b.begin(), b.end(), need) - b.begin();
		
		if(lo != up)
		return 1;
	}
	
	for(int i = 0; i < (int)a.size(); i++){
		ll need = k - (2 * a[i]);
		if(need < 0)
		continue;
		
		ll up = upper_bound(b.begin(), b.end(), need) - b.begin();
		ll lo = lower_bound(b.begin(), b.end(), need) - b.begin();
		
		if(lo != up)
		return 1;
	}
	
	for(int i = 0; i < (int)b.size(); i++)
	b[i] *= 2;
	
	for(int i = 0; i < (int)a.size(); i++){
		ll need = k - a[i];
		if(need < 0)
		continue;
		
		ll up = upper_bound(b.begin(), b.end(), need) - b.begin();
		ll lo = lower_bound(b.begin(), b.end(), need) - b.begin();
		
		if(lo != up)
		return 1;
	}
	
	for(int i = 0; i < (int)a.size(); i++){
		ll need = k - (2 * a[i]);
		if(need < 0)
		continue;
		
		ll up = upper_bound(b.begin(), b.end(), need) - b.begin();
		ll lo = lower_bound(b.begin(), b.end(), need) - b.begin();
		
		if(lo != up)
		return 1;
	}
	
	return 0;
}

int main()
{
	int test;
	scanf("%d",&test);
	
	for(int tc = 1; tc <= test; tc++){
		scanf("%lld %lld",&n, &k);
		
		for(int i = 0; i < n; i++)
		scanf("%lld",&ara[i]);
		
		makea(n/2);
		makeb(n - n/2);
		
		int ans = bin();
		
		if(ans)
		printf("Case %d: Yes\n",tc);
		else
		printf("Case %d: No\n",tc);
		
		a.clear();
		b.clear();
	}
	return;
}
