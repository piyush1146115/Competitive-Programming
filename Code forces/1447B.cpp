#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	
	int test;
	cin >> test;
	
	while(test--){
		int m, n;
		cin >> m >> n;
		
		int k, ans = 0, cnt = 0, mn = INT_MAX;
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >> k;
				if(k <= 0){
					k *= -1;
					cnt++;
				}
				ans += k;
				mn = min(mn, k);
			}
		}
		
		if(cnt % 2 == 1){
			ans -= (mn * 2);
		}
		
		cout << ans << endl;
	}
}
