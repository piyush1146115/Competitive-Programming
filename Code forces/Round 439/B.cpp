#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long 
int main()
{
	ll a , b;
	
	cin >> a >> b;
	
	ll ans = 1, i = a + 1;
	
	while(i <= b){
		ans = ((ans % 10) * (i % 10)) % 10 ;
		if( ans == 0)
		break;
		
		i++;
	}
	
	cout << ans % 10 << endl;
	
	//main();
}
