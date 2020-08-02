#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ara[105];
int main()
{
	int test, n;
	
	cin >> test;
	
	while(test--){
		cin >> n;
		
		for(int i = 0; i < n; i++){
			cin >> ara[i];
			
			if(i % 2 == 0){
				if(ara[i] < 0){
					ara[i] *= -1;
				}
			}
			else{
				if(ara[i] > 0){
					ara[i] *= -1;
				}
			}
		}
		
		
		for(int i = 0; i < n; i++){
			cout << ara[i] << ' ';
		}
		cout << endl;
	}
	
}
