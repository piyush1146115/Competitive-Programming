#include<bits/stdc++.h>
using namespace std;
#define MAX 5005

long long int ara[MAX];

int main()
{
	int test;
	cin >> test;
	int n;
	while(test--){
		cin >> n;
		int v = -1;
		
		for(int i = 0; i < n; i++){
			cin >> ara[i];
			if(ara[i] != ara[0]){
				v = i + 1;
			}
		}
		
		if(v == -1){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
			
			for(int i = 1; i < n; i++){
				if(ara[i] != ara[0]){
					cout << 1 << ' ' << i + 1 << endl;
				}
				else{
						cout << v << ' ' << i + 1 << endl;
					}
			}
			
			
		}
		
		
	}
}
