#include<bits/stdc++.h>
using namespace std;
#define ll long long 
vector<string> v, vs;

int main()
{
	string s;
	
	cin >> s;
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		string st;
		cin >> st;
		v.push_back(st);
	}
	
	for(int i = 0; i < n ; i++){
		string temp;
		
		for(int j  = 0; j < n; j++){
		temp = v[i] + v[j];
		vs.push_back(temp);	
		}
	}
	
	int ans = 0;
	
	for(int i = 0; i < (int)vs.size(); i++){
		for(int j = 0; j < (int)vs[i].size() - 1; j++){
			if(vs[i][j] == s[0] && vs[i][j + 1] == s[1]){
				ans = 1;
			}
		}
	}
	
	if(ans)
	printf("YES\n");
	else
	printf("NO\n");
	
}
