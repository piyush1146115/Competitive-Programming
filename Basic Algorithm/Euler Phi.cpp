#include<bits/stdc++.h>
using namespace std;
#define mxx 100005

bool mark[mxx];
int phi[mxx];

void sievephi(int n)
{
	int i, j;
	
	//initialization
	
	for(int i = 1; i <= n; i++)
	phi[i] = i;
	
	mark[1] = 1;
	
	for(int i = 2; i <= n; i++){
		if(mark[i] == 0)
		{
			phi[i] = i - 1;
			
			for(j = i + i; j <= n; j += i){
				mark[j] = 1;
				phi[j] = phi[j]/i * (i - 1);
			}
		}
	}
}

int main()
{
	sievephi(100000);
	
	for(int i = 2; i <= 50 ; i++)
	printf("%d %d\n",i, phi[i]);
	
}
