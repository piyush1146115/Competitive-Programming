#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, test;
	
	cin >> test;
	
	for(int tc = 1; tc <= test; tc++)
	{
		long long sum = 0;
		
		scanf("%d", &n);
		
		for(int i = 0; i < n; i++){
		int m;
		scanf("%d",&m);
		
		if(m > 0)
		sum += m;
		}
		
		printf("Case %d: %lld\n",tc, sum);
	}
	return 0;
}
