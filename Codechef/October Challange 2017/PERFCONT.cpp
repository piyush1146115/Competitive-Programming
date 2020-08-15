#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	
	scanf("%d", &test);
	
	while(test--){
	long long  n, p;
	
	scanf("%lld %lld", &n,&p);
	
	
	
	int cake = 0, hh = 0;
	for(int i = 0; i < n;i++){
		long long  k;
		scanf("%lld",&k);
			if((k * 10) <= p)
			hh++;
			else if(k * 2 >= p)
			cake++;
		
	}
	
	if(cake == 1 && hh == 2)
	{
		printf("yes\n");
	}
	else{
		printf("no\n");
	}
}
	
}
