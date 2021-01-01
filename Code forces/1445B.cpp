#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test, a, b, c, d;
	
	cin >> test;
	
	while(test--){
		cin >> a >> b >> c >> d;
		
		cout << max(a+b, c+d) << endl;
	}
}
