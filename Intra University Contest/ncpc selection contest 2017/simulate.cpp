#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int a, b, ro, ra;
	
	while(cin >> a >> b){
	ro = ra = a;
	for(int i = a + 1; i <= b; i++){
	ro |= i;
	ra &= i;
	}
	
	cout << ro
	 << endl << ra << endl;
 }
}
