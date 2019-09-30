#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll a, b;
	
	cin >> a >> b;
	
	ll mn = min(a, b);
	
	ll ans = 1;
	
	for(int i = 1; i <= mn; i++)
	ans *= i;
	
	cout << ans << endl;
}
