#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin >> test;
	int cnt[30];
	while(test--){
		
		string s, p;
		cin >> s >> p;
		memset(cnt, 0, sizeof(cnt));
		
		for(int i = 0; i < (int)s.size(); i++){
			cnt[s[i] - 'a']++;
		}
		int flag = 0;
		for(int i = 0; i <(int)p.size(); i++){
			cnt[p[i]-'a']--;
			if(p[i] > p[0] && flag == 0){
				flag = -1;
			}
			if(p[i] < p[0] && flag == 0){
				flag = 1;
			}
		}
		string ans;
		
		for(int i = 0; i < 26; i++){
			if((p[0] - 'a') < i){
				break;
			}
			
			if(flag == 1){
				if((p[0] - 'a') <= i)
					break;
			}
			
			while(cnt[i] > 0){
				cnt[i]--;
				ans.push_back((char)(i + 'a'));
			}
		}
		
		for(int i = 0; i <(int)p.size(); i++){
			ans.push_back(p[i]);
		}
		
		
		for(int i = 0; i < 26; i++){
			while(cnt[i] > 0){
				cnt[i]--;
				ans.push_back((char)(i + 'a'));
			}
		}
		cout << ans << endl;
		ans.clear();
	}
}
