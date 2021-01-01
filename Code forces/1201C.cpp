#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll ara[200005];

int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k;
	
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		cin >> ara[i];
	}
	
	sort(ara, ara + n);
	
	if(ara[n/2] + k <= ara[n/2 + 1])
		cout << ara[n/2] + k << endl;
	else{
		int ind = n/2 + 1, cnt = 1;
		
		while(ind < n && k > 0){
			ll dif = ara[ind] - ara[ind - 1];
			ara[ind - 1] += min(dif, k/cnt);
			
			k -= dif*cnt;
			if(k >= 0)
				ind++;
			cnt++;
		}
		
		if(k <= 0 ){
			ind--;
			cout << ara[ind] << endl;
		}
		else{
			ll add = k/cnt;
			cout << ara[n - 1] + add << endl;
		}
	}
	
}
