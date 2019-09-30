#include<bits/stdc++.h>
using namespace std;
#define mxx 100005
int ara[mxx];
int main()
{
	int test, n;
	
	cin >> test;
	
	for(int tc = 1; tc <= test; tc++){
	scanf("%d",&n);
	
	for(int i = 0;i <n; i++){
	scanf("%d", &ara[i]);
	}
	int x = ara[0];
	for(int i = 1; i < n; i++){
	x ^= ara[i];
	}
	//cout << x << endl;
	int ans = 10000000;
	for(int i = 0; i < n; i++){
	ans = min(ans, ara[i] ^ x);
	}
	cout << ans << endl;
	}
	return 0;
}
