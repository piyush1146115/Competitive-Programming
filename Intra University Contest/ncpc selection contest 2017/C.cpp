#include<bits/stdc++.h>
using namespace std;
#define ull  long long

int main()
{
	int test, cs = 0;
	
	scanf("%d", &test);
	
	while(test--){
		
		ull up, lo,tmp, bit, cnt;
		
		cnt = 0;
		bit = 1;
		//cin >> lo >> up;
			
		scanf("%lld %lld", &lo, &up);
		
		if(lo > up)
		swap(lo, up);
		
		tmp = up;
		
		while(bit < up){
		cnt++;
		bit *= 2;
		}
		
		ull dif = up - lo;
		up = (up & lo);
		
		
		for(int i = 0; i < cnt; i++){
		ull n = 1 << i;
		if((up & n) != 0){
		if(dif >= n)
		up ^= n;
		}
		}
		
//		cout << up << endl;
		
		
		cnt = 0;
		bit = 1;
		
		while(bit < tmp){
		cnt++;
		bit *= 2;
		}
		
	
		
		
		for(int i = 0; i < cnt; i++){
		ull n = 1 << i;
		if((tmp & n) == 0){
		//	cout << tmp << " " << dif << " " << n << endl;
		if(dif >= n)
		tmp |= n;
		}
		}
		
	//	cout << tmp << endl;
	printf("Case %d: %lld %lld\n",++cs, tmp, up);
}
return 0;
}
