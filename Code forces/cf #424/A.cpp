#include<bits/stdc++.h>
using namespace std;
#define ll long long
	int ara[105];
	
int main()
{

	int n;
	scanf("%d", &n);
	
	
	for(int i = 1; i <= n; i++)
	scanf("%d", &ara[i]);
	
	int less = 0, eq = 0, flag = 0;
	
	for(int i = 1; i <=n ;i++){
		
		if(ara[i] < ara[i - 1])
		less = 1;
		
		if(ara[i] == ara[i - 1])
		eq = 1;
		
		if(less || eq)
		{
			if(ara[i] > ara[i - 1])
			{
				flag = 1;
				break;
			}
		}
		if(less){
			if(ara[i] == ara[i - 1])
			flag = 1;
		}
	}
	
	if(!flag)
	printf("YES\n");
	else
	printf("NO\n");
	
}
