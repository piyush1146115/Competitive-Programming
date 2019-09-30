#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s, t;
	cin >> s >> t;
	reverse(s.begin(), s.end());
	
	if(s == t){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	//main();
}
