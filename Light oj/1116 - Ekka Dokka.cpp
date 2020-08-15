#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	
	scanf("%d", &test);
	
	
	for(int tc = 1; tc <= test; tc++){
		long long n;
		cin >> n;
		
		printf("Case %d: ",tc);
		
		if(n % 2 != 0)
		printf("Impossible\n");
		else{
			long long even, odd;
			
			odd = n;
			even = 1;
			
			while(odd % 2 == 0)
			{
				odd/= 2;
				even *= 2;
			}
			
			cout << odd << " " << even << endl;
		}
	}
	return 0;
}
