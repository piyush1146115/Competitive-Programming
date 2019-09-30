#include<bits/stdc++.h>
using namespace std;
#define mxx 1000005
bool chk[mxx + 25];
int dif[80000];

vector<int> prime;

void sieve()
{
	prime.push_back(2);
	
	for(int i = 3; i <= 1010; i+= 2){
		if(chk[i] == 0){
			for(int j = i * i; j <= 1000010; j += (i * 2))
			chk[j] = 1;
		}
	}
	
	for(int i = 3; i <= 1000010; i+= 2)
	if(chk[i] == 0)
	prime.push_back(i);
}

int main()
{
	sieve();
//	cout << prime.size() << endl;
	int test;
	
	scanf("%d",&test);
	
	while(test--)
	{
		memset(dif, 0 , sizeof(dif));
		
		int lo, hi;
		scanf("%d %d", &lo, &hi);
		int cnt = 0, mx = 0, ans = 0;
		for(int i = 0; prime[i] <= hi; i++ ){
			if(i > 0)
			{
				if(prime[i -1] <= hi && prime[i -1] >= lo && prime[i] <= hi && prime[i] >= lo)
				{
					dif[prime[i] - prime[i - 1]]++;
					if(dif[prime[i] - prime[i - 1]] > mx)
					{
						mx = dif[prime[i] - prime[i - 1]];
						ans = prime[i] - prime[i - 1];
					}
				}
			}
		}
		
		for(int i = 0 ; i < 79000; i++){
			if(dif[i] == mx)
			cnt++;
			}
			
			if(cnt > 1)
			printf("No jumping champion\n");
			else{
				printf("The jumping champion is %d\n", ans);
			}
	}
	return 0;
}
