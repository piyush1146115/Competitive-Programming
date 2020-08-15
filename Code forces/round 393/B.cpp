#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n, m, k;
	
	cin >> n >> m >> k;
	
	ll rem = m - n;
	ll ans = 1;

	ll bin = rem;
	ll sum = 0, st = k - 1, en = n - k;
	
	while(bin > 0 ){
		sum = bin;
		if(st > 0)
		sum += ( (bin * st) - ((st * (st - 1) / 2)));
		if(en > 0)
		sum += ( (bin * en) - ((en * (en - 1) / 2)));
		
		if(sum - rem == 0){
			ans = bin + 1;
			break;
		}
		
		if((sum - rem <= n) && (sum - rem) > 0)
		{
			ans += bin;
			break;
		}
		
		if(sum > rem){
	//	loop = bin;
		bin/= 2;
	}
		if(sum < rem)
		bin++;
	
	}
	
cout << ans << endl;
}
