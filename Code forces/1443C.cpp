#include<bits/stdc++.h>
using namespace std;

#define MAX 200005

long long int a[MAX], b[MAX];

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int test;
	cin >> test;
	
	while(test--){
		int n;
		cin >> n;
		vector<pair<long long int, long long int> > v;
		
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		
		for(int i = 0; i < n; i++){
			v.push_back(make_pair(a[i], b[i]));
		}
		
		sort(v.begin(), v.end());
		
		long long int ans = v[n - 1].first, sum = 0;
		
		for(int i = n - 1; i >= 0; i--){
			ans = min(ans, max(v[i].first,sum));
			sum += v[i].second;
		}
		ans = min(ans, sum);
		
		cout << ans << endl;
	}
	
}
