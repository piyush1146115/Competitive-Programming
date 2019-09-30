#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++)
	{
		long long n, m;
		
		scanf("%lld %lld",&n, &m);
		
		long long s = m, s2 = 0, ans = 0;
		
	/*	for(int i = 1; s < n; i++){
		ans -=  ((s * (s + 1)));
		
		ans += ((s2 * (s2 + 1)));
	//	cout << s << endl;
		//cout << ans << endl;
		s += (2 * m);
		s2 += (2 * m);
	}
	
	ans += (n * (n + 1)) /2;
		*/
		ans = (n* m)/2;
		
		printf("Case %d: %lld\n",tc, ans);
	}
	return 0;
}
