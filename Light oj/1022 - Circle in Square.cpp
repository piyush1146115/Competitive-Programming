#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)

#define eps 1e-10

int main()
{
	double r, res;
	int test;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++)
	{
		scanf("%lf", &r);
		
		res = (r * r) * (4 - pi);
		res += eps;
		
		printf("Case %d: %.2lf\n",tc,  res);
	}
	return 0;
}
