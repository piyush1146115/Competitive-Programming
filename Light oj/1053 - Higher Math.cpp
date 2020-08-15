#include<bits/stdc++.h>
using namespace std;

long long int sq(int a)
{
	return a * a;
}

int main()
{
	int test;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		int a, b, c;
		
		scanf("%d %d %d", &a, &b, &c);
		
		if((sq(a) + sq(b) == sq(c)) || (sq(b) + sq(c) == sq(a)) || (sq(a) + sq(c) == sq(b))){
			printf("Case %d: yes\n", tc);
		}
		else{
		printf("Case %d: no\n", tc);
		} 
	}
}
