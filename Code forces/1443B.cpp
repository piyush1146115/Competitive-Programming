#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int test, a, b;
	long long ans;
	cin >> test;
	
	while(test--){
	string s;
	
	cin >> a >> b >> s;
	
	
	int flag = 0, zero = 0;
	ans = 0;

	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] == '1'){
			if(flag == 0){
				ans += a;
				flag = 1;
			}
			if(zero > 0){
				ans += min(zero * b,  a);
			}
			zero = 0;
		}
		else{
			if(flag)
				zero++;
		}
	}
	
	cout << ans << endl;
}
	
}
