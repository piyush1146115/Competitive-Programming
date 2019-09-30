#include<bits/stdc++.h>
using namespace std;
int ara[100005];

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i = 1;i <= n; i++)
	scanf("%d", &ara[i]);
	
	int p1 = 1, p2 = n;
	int s1 = ara[p1], s2 = 0;
	int alice = 1, bob = 0;
	
	while(p1 < p2){
		if(s1 <= s2){
			p1++;
			alice++;
			s1 += ara[p1];
		}
		else{
			s2 += ara[p2];
			p2--;
			bob++;
		}
	}
	
	printf("%d %d\n",alice, bob);
	//main();
	return 0;
}
