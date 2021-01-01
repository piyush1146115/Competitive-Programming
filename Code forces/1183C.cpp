#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	
	ll n, k, a, b;
	
	ll test;
	
	cin >> test;
	
	while(test--){
		cin  >> k >> n >> a >> b;
		
		if(b*n >= k){
			cout << -1 << endl;
		}
		else{
			ll p, lo = 0, hi = n, mid, ans = 0;
			
			while(lo <= hi){
				mid = (lo + hi)/2;
				p = (mid*a) + (n - mid)*b;
				
				if(p < k){
					lo = mid + 1;
					ans = mid;
				}
				else{
					hi = mid - 1;
				}
			}
			
			cout << ans << endl;
		}
	}
	
	
}
