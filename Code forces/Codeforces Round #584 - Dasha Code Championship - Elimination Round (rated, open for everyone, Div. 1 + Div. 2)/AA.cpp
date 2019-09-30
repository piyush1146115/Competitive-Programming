#include<bits/stdc++.h>
using namespace std;
#define MAX 200

int ara[MAX];

int main() {
   // __FastIO;   //Be aware to use it!
	int n;
	cin >> n;
	
	
	for(int i = 0 ;i < n; i++){
		cin >> ara[i];
	}
	
	
	int ans = 0;
	
	sort(ara, ara+ n);
	
	for(int i = 0; i < n; i++){
		if(ara[i] > 0){
			ans++;
			for(int j = i + 1; j < n; j++){
				if(ara[j] % ara[i] == 0){
					ara[j] = 0;
				}
			}
		}
	}

	cout << ans << endl;
    return 0;
}

