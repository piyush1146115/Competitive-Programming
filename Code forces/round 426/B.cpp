#include<bits/stdc++.h>
using namespace std;
#define mxx 1000005
string s;
int ara[150], mp[150];
int main()
{
	int n, k;
	
	cin >> n >> k >> s;
	
	for(int i = 0; i < n; i++){
		mp[s[i]- 'A']++;
	}
	
	int cnt = 0, flag = 0;
	
	for(int i = 0; i < n; i++){
		
		if(ara[s[i] - 'A'] == 0)
		cnt++;
		
		if(cnt > k){
			flag= 1;
			break;
		}
		ara[s[i] - 'A']++;
		
		if(ara[s[i]- 'A'] == mp[s[i] - 'A'])
		cnt--;
	}
	
	if(flag){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}
