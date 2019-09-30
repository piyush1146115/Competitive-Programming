#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a, b;
	
	cin >> a >> b;
	int ans = 0;
	
	while(1){
	if(a > b)
	break;
	
	 a *= 3;
	 b *= 2;
	 
	 ans++;
	}
	
	cout << ans << endl;
}
