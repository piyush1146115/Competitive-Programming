#include<bits/stdc++.h>
using namespace std;
int ara[100005];
int main()
{
	int n;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n ; i++)
	{
		scanf("%d" ,&ara[i]);
	}
	
	sort(ara, ara + n);
	int flag = 1;
	//for()
	for(int i = 0; i < n - 2; i++)
	if((ara[i] + ara[i + 1] > ara[i + 2]) && (ara[i + 2] + ara[ i + 2] > ara[i]) && (ara[i] + ara[i + 2] > ara[i + 1]))
	{
		printf("YES\n");
		flag = 0;
		break;
}
	if(flag)
	printf("NO\n");
}
