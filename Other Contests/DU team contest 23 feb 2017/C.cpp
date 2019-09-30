#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s, c, ans, pat;
	
	cin >> s >> c;
	int cnt  = 0;
	//ans = "";
	
	for(int i = 0; i < s.size(); i++){
		
			int dif = s[i] - c[cnt];
			
			if(dif < 0)
			dif = 26 + dif;
			
			pat.push_back(dif + 65);
			ans.push_back(dif + 65);
			
		//	cout << pat[cnt] <<" " << i << " " << dif <<  endl;
			cnt++;
			if(cnt == c.size()){
		//		ans += pat;
				c = pat;
				//cout << pat << endl;
				cnt = 0;
				pat.clear();
			}
	}
		
	
	cout << ans << endl;
	
}
