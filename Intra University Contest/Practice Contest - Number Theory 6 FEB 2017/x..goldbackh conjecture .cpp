#include<bits/stdc++.h>
using namespace std;
#define mxx 1000005

bool chk[mxx + 10];
vector<int>prime;

void sieve()
{
	for(int  i = 3; i <= 1005; i+= 2)
	{
		if(chk[i] == 0){
			for(int j = i * i ; j <= 1000010; j += (i * 2))
			chk[j] = 1;

	}
}	
	for(int i = 4; i <= 1000005; i += 2)
		chk[i] = 1;
	
	prime.push_back(2);
	
	for(int i = 3; i <= 1000005; i += 2)
	if(chk[i] == 0)
	prime.push_back(i);
		

} 

int main()
{
	sieve();
	
		int test, cs = 0;
		
		scanf("%d", &test);
		
		while(test--){
		int n;
		
		scanf("%d", &n);

			
			int cnt = 0;
			for(int i = 0; prime[i] <= n / 2;i++){
				if(chk[n - prime[i]] == 0){
				cnt++;
				}
			}
				
		printf("Case %d: %d\n",++cs, cnt);
}
		
	return 0;

}
