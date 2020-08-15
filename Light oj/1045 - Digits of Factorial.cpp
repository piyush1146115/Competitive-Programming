#include<bits/stdc++.h>
using namespace std;
double ara[1000005];

int main()
{
	double x = 0.0;
	ara[0] = 0.0;
	
	for(int i = 1; i <= 1000000; i++){
		x += log10(i);
		ara[i] = x;
	}
	
	int test;
	scanf("%d",&test);
	
	for(int tc = 1; tc <= test; tc++){
		int n, b;
		
		scanf("%d %d",&n, &b);
		
		double x = 0.0;
		
	/*for(int i = 1; i <= n; i++){
		x += log10(i)/ log10(b);
	}
	
		printf("%lf\n",x);*/
		
		double res = ara[n] / log10(b);
	
	int ans = (int)res + 1;
		
		printf("Case %d: %d\n",tc, ans);
	}
	return 0;
}
