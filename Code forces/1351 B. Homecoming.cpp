#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 100005

ll ara[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	int test;
	
	cin >> test;
	
	string s;
	ll a, b, p;
	
	while(test--){
		
		cin >> a >> b >> p >> s;
		
		int n = (int)s.size();
		if(s[0] == 'A')
			ara[0] = a;
		else
			ara[0] = b;
		
		for(int i = 1; i < n - 1; i++){
			if(s[i] != s[i - 1]){
				if(s[i] == 'A')
					ara[i] = a;
				else
					ara[i] = b;
			}
			else{
				ara[i] = ara[i - 1];
				ara[i - 1] = 0;
			}
		}
		
		ara[ n - 1] = 0;
		
		for(int i = n - 2; i >= 0; i--)
			ara[i] = ara[i] + ara[i + 1];
		
		int ans = n;
		for(int i = 0; i < n ; i++){
			if(p >= ara[i]){
				ans = i + 1;
				break;
			}
		}
		
		cout << ans << endl;
		
		for(int i = 0; i <= n; i++)
			ara[i] = 0;
	}
	
}
