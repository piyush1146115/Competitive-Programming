#include<bits/stdc++.h>
using namespace std;
#define mxx 100015

long long ara[mxx];

int main()
{
	int test;
	
	long long int w, h, f;
	
	scanf("%d", &test);
	
	while(test--){
	scanf("%lld %lld %lld", &f, &h, &w);

	ara[0] = 0;
	
	for(int i = 1; i <= f; i++)
	scanf("%lld", &ara[i]);
	
	ara[f + 1] = w;
	
	sort(ara, ara + f + 1);
	
		long long int dif = 0, ans = 123121414;
	for(int i = 1; i <= f + 1; i++)
	{
		dif = ara[i] - ara[i - 1];
		ans = min(ans , dif);
	}
printf("%lld\n", ans * h);	
	
}	
return 0;
}
