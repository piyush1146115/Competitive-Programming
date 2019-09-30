#include<bits/stdc++.h>
using namespace std;

int ar1[10], ar2[6], tot[10];

int main()
{
	
	
	int n, m;
		scanf("%d", &n);
		
	for(int i = 0; i < n ; i++){
		scanf("%d", &m);
		ar1[m]++;
		tot[m]++;
	}
	
	for(int i = 0; i < n ; i++){
		scanf("%d", &m);
		//ar[m]++;
		tot[m]++;
	}
	
	int flag = 0;
	
	for(int i = 1; i <= 5; i++)
	{
	if(tot[i] % 2 != 0)
	flag = 1;
}

	if(flag)
	printf("-1\n");
	else{
	int cnt = 0, dif;
	
	for(int i = 0;i <= 5; i++ )
	{
		dif = abs(tot[i]/2 - ar1[i]);
		cnt += dif;
	}
	printf("%d\n",cnt/2 + cnt % 2);
	}
	return 0;
}
