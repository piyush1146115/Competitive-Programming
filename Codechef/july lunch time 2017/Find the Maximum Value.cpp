#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll ara[105];

int main()
{
	int test;
	scanf("%d", &test);
	getchar();
	string s;
	
	for(int tc = 1; tc <= test; tc++){
		getline(cin, s);
		
		stringstream ss(s);
		ll n = 0, m;
		while(ss >> m){
			ara[n++] = m;
		}
		
		ll mx = -1;
		//cout << "n " << n << endl;
		int flag = 0;
		
		for(int i = 0; i < n; i++){
			if(ara[i] == n - 1){
			continue;
		}
		flag = 1;
			mx = max(mx, ara[i]);
		}
		
		ss.clear();
		
		if(flag)
		printf("%lld",mx);
		
		printf("\n");
	}
	return 0;
}

