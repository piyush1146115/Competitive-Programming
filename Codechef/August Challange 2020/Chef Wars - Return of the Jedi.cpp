#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int sum, T, P, H;
	
	cin >> T;
	
	
	while(T--){
		
		cin >> H >> P;
		
		sum = 0;
		
		while(P > 0){
			sum += P;
			P /= 2;
		}
		
		if(sum >= H){
			cout << 1 << endl;
	}
	else{
		cout << 0 << endl;
	}
}

}
