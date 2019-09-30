#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll di[20];

ll lcm(ll a, ll b)
{
	ll gcd = __gcd(a, b);
	ll res = (a * b) / gcd;
	return res;
}

int main()
{
	ll n, m;
	//cout << lcm(2, 5) << endl;
	while(scanf("%lld %lld", &n, &m) == 2){
		
		for(int i = 0; i < m; i++)
		scanf("%lld", &di[i]);
		
		ll ans = 0;
		
		for(int i = 0; i < m; i++)
		ans += (n / di[i]);
		
		set<ll> s;
		
		for(int i = 0; i < m; i++){
			for(int j = i + 1; j < m; j++){
				s.insert(lcm(di[i], di[j]));
			}
		}
		
		set<ll> :: iterator  it ;
		ll res = 0;
		
		for(it = s.begin(); it != s.end(); it++){
				res += n /(*(it)) ;  
		}
		
		while(s.size() > 1){
		
		set<ll> :: iterator  it2 ;
		set<ll> s2;
		
		for(it = s.begin(); it != s.end(); it++){
			it2 = it;
			it2++;
			for(; it2 != s.end();it2++){
				ll lc = lcm(*(it2), *(it));
				if(lc <= n)
				s2.insert(lc);
			}
		}
		//s.clear();
		s = s2;
		
		for(it = s.begin(); it != s.end(); it++){
				res -= n /(*(it)) ;  
		}
	}
	
	//cout << res << endl;
		ans -= res;
		
		printf("%lld\n",n - ans);	
	}
}
