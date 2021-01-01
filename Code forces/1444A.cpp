#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long p, q, t;
	cin >> t;
	
	while(t--){
		cin >> p >> q;
		
		if(p % q != 0){
			cout << p << endl;
		}
		else{
			long long ans = 1;
			
			for(long long i = 2; i*i < q; i++){
				if(q % i == 0){
					if((p/i) < q)
						ans = max(ans, p/i);
					if(p/(q/i) < q)	
						ans = max(ans, p/(q/i));
				}
			}
			cout << ans << endl;
		}
	}
}
