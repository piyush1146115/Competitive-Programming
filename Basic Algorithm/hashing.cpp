#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long 

ll power(int b, int p)
{
	if(p == 0)
	return 1;
	if(p % 2 == 0){
		ll ret = power(b, p/2) % mod;
		return (ret * ret) % mod;
	}
	else{
		return (b * (power(b, p -1) % mod))% mod;
	}
}

ll multiply(ll a , ll b)
{
	return ((a % mod) * (b % mod))%mod;
}
/*
ll add(ll a , ll b)
{
	return ((a % mod) + (b % mod)) % mod;
}*/

int main()
{
	int test;
	scanf("%d", &test);
		
		ll ara[110];
		ll sum = 0;
		for(int i = 1; i < 105; i++){
			sum += power(29, i);
			sum %= mod;
			ara[i] = sum;
		}
		
		
	for(int tc = 1; tc <= test; tc++){
	string s;
	
	cin >> s;
	ll fow = 0;
	
	for(int i = 0; i < (int)s.size();i++){
			//fow += multiply((s[i] - 'a' + 1) , power(29, i + 1));
			fow += ((s[i] - 'a' + 1) * power(29, i + 1));
			fow %= mod;
	}
	
	ll bck = 0, cnt = 0;
	
	for(int  i = (int)s.size() - 1; i >= 0; i--){
//		bck += multiply((s[i] - 'a' + 1) , power(29, ++cnt));
		bck += ((s[i] - 'a' + 1) * power(29, ++cnt));
		bck %= mod;
	}
	
	int q;
	scanf("%d", &q);
	printf("Case %d:\n",tc);
	
	while(q--){
		char ch, op;
		int t;
		ll tml, tmr;
		tml = tmr = 0;
		getchar();
		scanf("%c %c %d", &op, &ch, &t);
	//	cout << op << " " << ch << " " << t << endl;
		
		if(op == 'L'){
			
			tml = (ch - 'a' + 1) * ara[t];
			tmr = (ch - 'a' + 1) * ara[t];
			tmr = multiply(tmr, power(29, cnt));
			bck += tmr;
			bck %= mod;
			
			fow = multiply(fow, power(29, t));
			//fow = add(fow, tml);
			fow += tml;
			fow %= mod;
			
			if(fow == bck){
				printf("Yes\n");
			}
			else{
				printf("No\n");
			}	
		}
		else
		{	
			tmr = (ch - 'a' + 1) * ara[t];
			tml = (ch - 'a' + 1) * ara[t];
			tml = multiply(tml, power(29, cnt));
			
			fow += tml;
			fow %= mod;
			bck = multiply(bck, power(29, t));
			bck += tmr;
			bck %= mod;
			
			if(bck == fow){
				printf("Yes\n");
			}
			else{
				printf("No\n");
			}
		}
		cnt += t;
	}
}
}
