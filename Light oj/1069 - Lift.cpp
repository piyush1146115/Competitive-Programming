#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,test,  m;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++)
	{
		int s, d;
		
		cin >> s >> d;
		
		int res = abs(d - s) + s ;
		res *= 4;
		
		res += 19;
		
		printf("Case %d: %d\n",tc, res);
	}
	
	return 0;
}
