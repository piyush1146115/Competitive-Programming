#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test, ara[15];
	
	scanf("%d", &test);
	
	while(test--){
	
	for(int i = 0; i < 5; i++)
	scanf("%d", &ara[i]);
	
	int flag = 1;
	
	for(int i = 0; i < 4; i++)
	{
			if(ara[i + 1] - ara[i] != 1)
			flag = 0;
	}
	
	if(flag)
	printf("Y\n");
	else{
	printf("N\n");
	}
}
	
	//khujtese
	
}
