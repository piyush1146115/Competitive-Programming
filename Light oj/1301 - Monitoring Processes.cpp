#include<bits/stdc++.h>
using namespace std;
#define mxx 50005
#define ll long long
struct st{
	ll s, t;
	
	bool operator < (const st &p)const{
		if(p.s == s)
		return t < p.t;
		else
		return s < p.s;
	}
}ara[mxx];

int main()
{
	int test;
	
	scanf("%d",&test);
	
	for(int tc = 1; tc <= test; tc++){
		int n;
		scanf("%d", &n);
		
		for(int i = 0; i < n; i++){
			scanf("%lld %lld",&ara[i].s, &ara[i].t);
		}
		sort(ara, ara + n);
		
		priority_queue<ll>pq;
		int ans = 1;
		pq.push(-ara[0].t);
		/*for(int i = 0; i < n; i++){
			printf("%lld %lld\n",ara[i].s, ara[i].t);
		}*/
		
		for(int i = 1; i < n; i++){
			ll val = -pq.top();
			
			if(val < ara[i].s){
				pq.pop();
				pq.push(-ara[i].t);
			}
			else{
				ans++;
				pq.push(-ara[i].t);
			}
		}
		printf("Case %d: %d\n",tc, ans);
	}
}
