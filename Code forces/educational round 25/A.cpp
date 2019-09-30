#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string s;
	
	cin >> n >> s;
	vector<int> ans;
	
	for(int i = 0; i < n; i++){
		int cnt = 0;
			
		if(s[i] == '1'){	
		while(i < n && s[i] == '1'){
			i++;
			cnt++;
		}
		i--;	
	}
	else{
		while(i < n && s[i] == '0')
		{
			i++;
			cnt++;
		}
		i--;
		cnt--;
		while(cnt--){
			ans.push_back(0);
			}
			continue;
	}	
		ans.push_back(cnt);
	}
	
	for(int i = 0; i < ans.size(); i++){
	cout << ans[i];
}
if(ans[ans.size() - 1] == 0)
	cout << 0;
	cout << endl;
	//main();
}
