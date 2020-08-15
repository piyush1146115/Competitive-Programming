#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin >> test;
	
	while(test--){
		int Pc, Pr;
		cin >> Pc >> Pr;
		
		int Fc, Fr;
		Fc = Pc/9 + ((Pc % 9 == 0)?0:1);
		Fr = Pr/9 + ((Pr % 9 == 0)?0:1);
		
		if(Fr <= Fc){
			cout << 1 << ' ' << Fr << endl;
		}
		else{
			cout << 0 << ' ' << Fc << endl;
		}
	}
}
