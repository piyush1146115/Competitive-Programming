#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		long long int a, b;
		scanf("%lld %lld", &a, &b);
		
		printf("Case %d: ",tc);
		
		if(a > b)
		swap(a, b);
		long long gc = __gcd(a, b);
		
		printf("%lld\n",(a + b)/gc);
	}
	
	
	//cout << __gcd(98876767,12234) << endl;
}
