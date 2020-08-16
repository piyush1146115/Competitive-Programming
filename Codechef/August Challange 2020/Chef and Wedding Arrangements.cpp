#include<bits/stdc++.h>
using namespace std;

#define MAX 1005

int f[MAX];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int test;
	
	cin >> test;
	
	while(test--){
		int n, k;
		vector<int> v[MAX];
		
		cin >> n >> k;
		int ans = 1, cnt = 0;
		
		for(int i = 0; i < n; i++){
			cin >> f[i];
		}
		map<int, int> mp;
		
		
		for(int i = 0; i < n; i++){
			if(mp.find(f[i]) == mp.end()){
				mp[f[i]] = 1;
				v[cnt].push_back(f[i]);
			}
			else{
				cnt++;
				v[cnt].push_back(f[i]);
				mp.clear();
				mp[f[i]] = 1;
			}
		}
		
		mp.clear();
		ans = k;
		for(int i = 0; i < (int)v[0].size(); i++)
			mp[v[0][i]] = 1;
			
		
		for(int i = 1; i <= cnt; i++){
			int sum = 0;
			for(int j = 0; j < (int)v[i].size(); j++){
				mp[v[i][j]]++;
				
				if(mp[v[i][j]] == 2){
					sum += 2;
				}
				else if(mp[v[i][j]] > 2){
					sum++;
				}
			}
			
			if((ans + k) < (ans+sum)){
				mp.clear();
				for(int j = 0; j < (int)v[i].size(); j++)
					mp[v[i][j]]++;
				ans += k;
			}
			else{
				ans += sum;
			}
		}
	
		cout << ans << endl;
	}
}
