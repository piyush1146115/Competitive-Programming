#include<bits/stdc++.h>
using namespace std;
 int ara[105];
int main()
{
	int test;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		int n, p, m;
		 scanf("%d %d %d", &n, &p, &m);
		 

		 for(int i = 0; i < n; i++)
		 scanf("%d", &ara[i]);
		 
		// sort(ara, ara + n);
		 int sum = 0, cnt = 0;
		 
		 for(int i = 0; i < n; i++)
		 {
			 if(i >= p)
			 break;
			 
			 sum += ara[i];
			 
			 if(sum > m)
			 break;
			
			// cout << i << " " << p <<  endl ;
			
			 cnt++;
		 }
		 
		 printf("Case %d: %d\n",tc, cnt);
	}
	return 0;
}
