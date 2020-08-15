#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll sq(ll n)
{
	ll ans = 0;
	while(n != 0){
		ll p = n % 10;
		n /= 10;
		ans += (p * p);
	}
	return ans;
}

int main()
{
	ll a, b;
	
	while(scanf("%lld %lld",&a, &b) == 2){
		
		if(a == 0 && b == 0)
		break;
		
		map<ll, int> mp1, mp2;
		mp1[a] = 1;
		mp2[b] = 1;
		ll n = a, m = b;
		int cnt1 = 1, cnt2 = 1 ,ans = 11;
		
		while(1){
			 n = sq(n);
			 cnt1++;
			 if(mp1[n] == 0){
			 //cnt1++;
			 mp1[n] = cnt1;
		 }
			 if(mp2[n] >= 1){
				 ans = cnt1 + mp2[n];
				 break;
			 }
			 
			 m = sq(m);
			 cnt2++;
			  if(mp2[m] == 0){
			 //cnt2++;
			 mp2[m] = cnt2;
		 }
		
			 if(mp1[m] >= 1){
				 ans = cnt2 + mp1[m];
				 break;
			 }
			  
			
			 //cout << n <<" " <<  m <<  endl;
			// getchar();
			 
			if(mp2[7] >= 1){
				for(int i = 2 ; i <= 9; i++){
					if(i == 7)
					continue;
					
					if(mp1[i] >= 1){
						ans = 0;
					}
				}
				if(ans == 0)
				break;
		}
		
			if(mp2[1] >= 1){
				for(int i = 2 ; i <= 9; i++){
					if(i == 7)
					continue;
					
					if(mp1[i] >= 1){
						ans = 0;
					}
				}
				if(ans == 0)
				break;
		}
		
			
			if(mp1[1] >= 1){
				for(int i = 2 ; i <= 9; i++){
					if(i == 7)
					continue;
					
					if(mp2[i] >= 1){
						ans = 0;
					}
				}
				if(ans == 0)
				break;
		}
			
			if(mp1[7] >= 1){
				for(int i = 2 ; i <= 9; i++){
					if(i == 7)
					continue;
					
					if(mp2[i] >= 1){
						ans = 0;
					}
				}
				if(ans == 0)
				break;
		}
		}
	
		if(a == b)
		ans = 2;
		
		printf("%lld %lld %d\n",a,b, ans);
		mp1.clear();
		mp2.clear();
	}
	return 0;
}
