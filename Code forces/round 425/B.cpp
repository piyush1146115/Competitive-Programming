#include<bits/stdc++.h>
using namespace std;
#define mxx 100005
string q[mxx];
int mp[30];
int main()
{
	string s, good;
	
	cin >> good;
	
	for(int i = 0; i < good.size(); i++)
	mp[good[i] - 'a'] = 1;
	
	cin >> s;
	int n;
	scanf("%d", &n);
	//getchar();
	
	
		
	for(int i = 0; i < n; i++)
	cin >> q[i];
	
	int pos = -1;
	
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '*'){
			pos = i;
			break;
		}
	}
	
	string s1, s2;
	if(pos != -1){
		for(int i = 0; i < pos; i++)
		s1.push_back(s[i]);
		
		for(int i = pos + 1;i < s.size(); i++)
		s2.push_back(s[i]);
	}
	
		//cout << "s1 " << s1 << " s2 " << s2 << endl;
		//getchar();
		
	
	if(pos == -1){
		for(int i = 0; i < n; i++){
			int flag = 1;
			
			if(q[i].size() != s.size()){
				printf("NO\n");
				continue;
			}
			
			for(int j = 0; j < s.size(); j++){
				if(s[j] == '?'){
					if(mp[q[i][j] - 'a'] != 1){
						flag = 0;
						break;
					}
				}
				else{
					if(q[i][j] != s[j]){
						flag = 0;
						break;
					}
				}
			}
			if(flag)
			printf("YES\n");
			else{
				printf("NO\n");
			}
		}
	}
	else{
	
		
		for(int i= 0; i < n;i++){
			int flag = 1;
			
			if(q[i].size() < (s1.size() + s2.size())){
				printf("NO\n");
				continue;
			}
			string c1, c2;
			
			for(int j = 0; j < pos && j < q[i].size(); j++){
				c1.push_back(q[i][j]);
			}
			
			int cnt = s2.size();
			
			for(int j = q[i].size() - 1; j >= pos && cnt > 0; j--){
				c2.push_back(q[i][j]);
				cnt--;
			}
			
			reverse(c2.begin(), c2.end());
			
			//cout << c1 << " " << c2 << endl;
			
			if(c1.size() != s1.size() || c2.size() != s2.size()){
				printf("NO\n");
				continue;
			}
			
			for(int j = 0; j < c1.size(); j++){
				if(s1[j] == '?'){
					if(mp[c1[j] - 'a'] != 1){
						flag = 0;
						break;
					}
				}
				else{
					if(c1[j] != s1[j]){
						flag = 0;
						break;
					}
				}
			}
				
			for(int j = 0; j < c2.size(); j++){
				if(s2[j] == '?'){
					if(mp[c2[j] - 'a'] != 1){
						flag = 0;
						break;
					}
				}
				else{
					if(c2[j] != s2[j]){
						flag = 0;
						break;
					}
				}
			}
			
			for(int j = s1.size() ; j + s2.size() < q[i].size();j++ ){
				if(mp[q[i][j] - 'a'] == 1){
					flag = 0;
					break;
				}
			}
			
			if(flag)
			printf("YES\n");
			else
			printf("NO\n");
			
		}
	}
	
	//main();
	
}
