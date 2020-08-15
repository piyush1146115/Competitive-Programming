#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int n, m;
	string s, t;
	
	cin >> n >> m >> s >> t;
	int mn = 100000;
	vector<int> ans;
	
	for(int i = 0; (i + (n - 1)) < m; i++){
		int cnt = 0;
		vector<int> vec;
		for(int j = 0; j < n; j++){
			if(s[j] != t[i + j]){
				cnt++;
				vec.push_back(j + 1);
			}
		}
		if(cnt < mn)
		{
			mn = cnt;
			ans = vec;
		}
	}
	
	cout << mn << endl;
	if(mn > 0)
	cout << ans[0];
	
	for(int i = 1; i < ans.size(); i++)
	cout << " " << ans[i];
	
	cout << endl;
}

