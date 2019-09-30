#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
bool chk[33000];

void sieve()
{
	for(int i = 3; i <= 182; i += 2)
	{
		if(chk[i] == 0)
		{
			for(int j = i * i; j <= 32900; j += (i * 2))
			chk[j] = 1;
		}
	}
	
	prime.push_back(2);
	
	for(int i = 3; i <= 32900; i += 2)
	if(chk[i] == 0)
	prime.push_back(i);
}

int main()
{
	sieve();
	
	int hi, lo;
	while(scanf("%d %d", &lo, &hi) == 2){
		
		if(lo == 0 && hi == 0)
		break;
		
		if(hi < lo)
		swap(lo, hi);
		
		int flag = 0;
		
		vector <int> v;
		for(int i = 0 ; i < prime.size() - 2 ; i++){
			
		if(prime[i+ 2] - prime[i + 1] == prime[i + 1] - prime[i]){
				//printf("%d %d %d",v[i], v[i + 1], v[i + 2]);
				v.push_back(prime[i]);
				v.push_back(prime[i + 1]);
				v.push_back(prime[i + 2]);
				
				int dif = prime[i + 1] - prime[i];
				i += 3;
				
				while( i < prime.size() && prime[i] - prime[i - 1] == dif)
					{
						//printf(" %d", v[i]);
						v.push_back(prime[i]);
						i++;
					}
					i-= 3;
					//printf("\n");
					
					
					
					if(v[0] > lo && v[v.size() - 1] < hi)
					{
						flag = 1;
						printf("%d",v[0]);
						for(int j = 1 ; j < v.size(); j++)
						printf(" %d", v[j]);
						
						printf("\n");
					}
					
					v.clear();
					
			}
			
		}
		
		
		
		
	}
	return 0;
}
