#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int test;
	
	cin >> test;
	int n;
	string s;
	
	while(test--){
		cin >> n >> s;
		
		int c = 0, ac = 0;
		
		for(int i = 0; i < n; i++){
			if(s[i] == '>')
				c++;
				
			if(s[i] == '<')
				ac++;
		}
		
	//	cout << c << ' ' << ac << endl;
		
		if(c == 0 || ac == 0){
			cout << n << endl;
		}
		else{
			int cnt = 0;
			
			for(int i = 0; i < n; i++){
				if(s[i] == '-'){
					cnt++;
					
					if(s[(i+1) % n] != '-')
						cnt++;
				}
			}
			
			cout << cnt << endl;
		}
		
	}
	
}
