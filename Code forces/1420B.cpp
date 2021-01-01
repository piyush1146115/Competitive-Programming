#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int test;
	cin >> test;
	
	while(test--){
		int n;
		cin >> n;
		vector< long long int> v;
		
		long long k;
		
		for(int i = 0; i < n; i++){
			cin >> k;
			v.push_back(k);
		}
		
		sort(v.begin(), v.end());
		
		long long mx = v[n - 1], po = 1, dif, ans = 0;
		
		while(po <= mx){
			int lo = lower_bound(v.begin(), v.end(), po) - v.begin();
			int up = upper_bound(v.begin(), v.end(), (po*2LL - 1)) - v.begin();
			
			dif = up - lo;
			if(dif > 0){
				ans += ((dif)*(dif - 1))/2;
			}
			po *= 2;
		}
		
		cout << ans << endl;
	}
}
