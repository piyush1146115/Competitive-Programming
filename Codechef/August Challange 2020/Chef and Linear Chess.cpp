#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
typedef long long ll;

int main()
{
	ll T, N, K, ans = -1, mn = 10000000000;
	
	cin >> T;
	
	while(T--){
		ans = -1, mn = 10000000000;
		cin >> N >> K;
		ll temp, dif, div;
		for(int i = 0; i < N; i++){
			cin >> temp;
			dif = K - temp;
		//	cout << K << " " << temp << ' ' << dif << endl; 
			if((dif >= 0) && (dif % temp == 0)){
				div = dif/temp;
				if(div < mn){
					ans = temp;
					mn = div;
				}
			}
		}
			cout << ans << endl;
		
	}
}
