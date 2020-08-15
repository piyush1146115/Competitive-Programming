#include<bits/stdc++.h>
using namespace std;

map<string, int> tar, cost;
map<string, int> coss;

int main()
{
	int n , m;
	
	cin >> n >> m;
	vector<string> v;
	string s, s2;
	
	for(int i = 0; i < n; i++){
		cin >> s;
		tar[s] = 1;
		cost[s] = 10000000;
		//cos[s] = 10000000;
		v.push_back(s);
	}
	
	int exp;
	
	for(int i = 0; i < m ; i++){
		cin >> s >> s2 >> exp;
		
		 if(s == "English" || s2 == "English")
		{
			if(s == "English"){
				coss[s2] = exp;
				tar[s2] = 0;
				cost[s2] = 0;
			}
			else{
			coss[s] = exp;
			tar[s] = 0;
			cost[s] = 0;
		}
	}
	 else if(tar[s] == 1 || tar[s2] == 1){
		if(tar[s] == 1)
		cost[s] = min(cost[s], cost[s2] + exp);
		
		if(tar[s2] == 1)
		cost[s2] = min(cost[s2] , cost[s] + exp);
	 }
	}
	
	int ans = 0;
	
	for(int i = 0; i < v.size(); i++)
	ans += coss[v[i]] + cost[v[i]];
//	cout << cost[v[i]] << " " << v[i] << endl;
	
	cout << ans << endl;
}
