#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mxx 200005

int N, x, flag;

struct st{
	ll l, r, cst, dur;
}ara[mxx];

bool comp(st a, st b)
{
	if(a.l == b.l){
		if(a.dur == b.dur){
			return a.cst < b.cst;
		}
		else
		return a.dur < b.dur;
	}
	}
	else
	return a.l < b.l;
}

ll bin_2(ll dur, ll lo)
{
	ll hi = N - 1, mid;
	ll ans = -1;
	
	while(lo <= hi){
		mid = (hi + lo)/2;
		
		if(dur + ara[mid].dur == x){
			ans = mid;
			hi = mid - 1;
		}
		else if(dur + ara[mid].dur > x){
			hi = mid - 1;
		}
		else{
			lo = mid + 1;
		}
	}
	if(ans== -1)
	return ans;
	
	return ara[ans].cst;
}

ll bin_1(ll dur, ll fin, ll lo)
{
	ll hi = N - 1, mid;
	ll ans = -1;
	while(lo <= hi)
	{
		mid = (lo + hi)/2;
		if(ara[mid].l > fin){
			ans = mid;
			hi = mid - 1;
		}
		else{
			lo = mid + 1;
		}
	}
	if(ans == -1)
	return -1;
	else{
		return bin_2(dur, ans);
	}
}

int main()
{
	scanf("%d %d",&N, &x);
	
	for(int i = 0; i < N; i++){
	scanf("%lld %lld %lld",&ara[i].l, &ara[i].r, &ara[i].cst);
	ara[i].dur = ara[i].r - ara[i].l + 1;
}

sort(ara, ara + N, comp);
ll ans = 100000000000;

for(int i = 0; i < N; i++){
	flag = i;
	ll res = bin_1(ara[i].dur, ara[i].r);
	if(res != -1)
	ans = min(ans, res + ara[i].cst);
}

if(ans == 100000000000)
printf("-1\n");
else
printf("%lld\n",ans);

}

