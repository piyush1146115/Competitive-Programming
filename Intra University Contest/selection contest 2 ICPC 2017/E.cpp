#include<bits/stdc++.h>
using namespace std;
int ara[100005];

int main()
{
	int n;
	
	scanf("%d", &n);
	map<int, int> mp;
	for(int i = 1; i <= n; i++){
		scanf("%d",&ara[i]);
		
		ara[i] = ara[i] + ara[ i - 1];
		mp[ara[i]] = 1;
	}
	
	if(ara[n] % 3 != 0)
	{
		printf("0\n");
		return 0;
	}
	int cnt = 0;
	
	int div = ara[n] / 3;
	
	for(int i = 1; i <= n; i++){
		if(mp[ara[i] + div] == 1 && mp[ ara[i] + div * 2] == 1)
		cnt++;
	}
	
	printf("%d\n",cnt);
}
