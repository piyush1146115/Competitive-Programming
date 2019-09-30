#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

int main()
{
	ll n, k;
	cin >> n >> k;
	ll div;
	div = n / k;
	if(div % 2 == 0){
		cout << "NO\n";
	}
	else{
		cout << "YES\n";
	}
	
}
