#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int test;
	cin >> test;
	
	while(test--){
		vector<ll> v;
		ll n, x, temp;
		
		cin >> n >> x;
		
		for(int i = 0; i < n; i++){
			cin >> temp;
			v.push_back(temp);
		}
		
		sort(v.begin(), v.end(), greater<int>());
		
		ll mn = 1e11, cnt = 0, ans = 0;
		for(int i = 0; i < (int)v.size(); i++){
			mn = min(mn, v[i]);
			cnt++;
			if((mn*cnt) >= x){
				mn = 1e11, cnt = 0;
				ans++;
			}
		}
		cout << ans << endl;
	}

}
