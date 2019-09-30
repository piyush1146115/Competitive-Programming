#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	
	scanf("%d", &test);
	
	for(int tc =1; tc <= test; tc++){
		long long n;
		
		scanf("%lld", &n);
		
		int sum = 0;
		while(n != 0){
		sum += (n % 2);
		n = n/ 2;
		}
		
		printf("Case %d: ",tc);
		
		//cout << sum << endl;
		if(sum % 2 != 0){
			printf("odd\n");
		}
		else{
		printf("even\n");
		}
	}
	return 0;
}
