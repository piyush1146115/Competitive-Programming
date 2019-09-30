#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
int main()
{
	ll n, k, t;
	cin >> n >> k >> t;
	ll ans;
	if(t <= n && t <= k){
		ans = t;
	}
	else if(t > n && t <= k){
		ans = n;
	}
	else if(t <= n && t > k){
		ans = k;
	}
	else if(t  > n && t > k){
		ans = max(0ll, n - t + k);
	}
	
	cout << ans << endl;
	//main();
}

