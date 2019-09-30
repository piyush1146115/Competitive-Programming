#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<string> vs;
		int freq[30];
	while(n--){
		string s;
		cin >> s;
		memset(freq, 0 , sizeof(freq));
		string temp;
		for(int i = 0; i < (int)s.size(); i++){
			if(freq[s[i] - 'a'] == 0){
				temp.push_back(s[i]);
				freq[s[i] - 'a']++;
			}
			else{
				freq[s[i] - 'a']++;
			}
		}
		sort(temp.begin(), temp.end());
		vs.push_back(temp);
	}
	
	map<string, int> mp;
	int cnt = 0;
	for(int i = 0; i < (int)vs.size(); i++){
		if(mp.find(vs[i]) == mp.end()){
			//cout << vs[i] << endl;
			cnt++;
		}
		mp[vs[i]] = 1;
	}
	
	cout << cnt << endl;
}
