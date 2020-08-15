#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c;
	
	while(cin >> a >> b >> c){
		if((a == 0 || a == 1) && a != b && a != c){
			printf("A\n");
		}
		else if((b == 0 || b == 1) && a != b && b != c){
			printf("B\n");
		}
		else if((c == 0 || c == 1) && c != b && a != c){
			printf("C\n");
		}
		else{
			printf("*\n");
		}
	}
}
