#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	scanf("%d",&test);
	
	
	for(int tc = 1; tc <= test; tc++){
		int n, k;
		scanf("%d %d",&n, &k);
		
		char s[30];
		
		for(int i = 0; i < n;i++){
			s[i] = i + 'A';
		}
		
		printf("Case %d:\n",tc);
		
		do{
			k--;
			for(int i = 0; i < n; i++)
			printf("%c",s[i]);
			
			printf("\n");
		}while(next_permutation(s, s + n) && k);
		
		
	}
	return 0;
}
