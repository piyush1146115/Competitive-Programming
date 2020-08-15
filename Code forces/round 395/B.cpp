#include<bits/stdc++.h>
using namespace std;
#define mxx 200005

long long ara[mxx];

int main()
{
	int n, i, j;
	
	cin >> n;
	
	for( i = 1;i <= n; i++)
		scanf("%lld", &ara[i]);
		
	for(i = 1; i <= (n - i + 1) ; i++)
	{
		if(i % 2 == 1)
		swap(ara[i], ara[n - i + 1]);
	}
	
	printf("%lld",ara[1]);
	
	for(i = 2; i <= n ;i++)
	printf(" %lld",ara[i]);
	
	printf("\n");
}
