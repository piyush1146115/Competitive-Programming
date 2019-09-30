#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	string s[n + 5];
	
	for(int i = 0; i < n; i++)
	cin >> s[i];
	
	for(int i = n - 1; i > 0; i--){
		
		int len = min(s[i].size(), s[i - 1].size());
		
		for(int j = 0 ; j < len; j++){
			
				if(s[i][j] > s[i - 1][j])
				break;
				
				else if(s[i][j] < s[i - 1][j])
				{
					s[i- 1].erase(j);
					break;
				}  
		}
		
		 if(s[i-1]>s[i])
            s[i-1].erase(s[i].size());
	}
		
	for(int i = 0; i  < n; i++)
	cout << s[i] << endl;
	
	return 0;
}
