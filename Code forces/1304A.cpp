#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long x, y, a, b;
	
	int test;
	cin >> test;
	
	while(test--){
		long long dif;
		cin >> x >> y >> a >> b;
		
		dif = y - x;
		if(dif % (a+b) == 0){
			cout << dif/(a+b) << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
}
