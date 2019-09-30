#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c;
	
	while(scanf("%d %d %d",&a, &b, &c) == 3){
		if(a == 0&& b == 0 && c == 0)
		break;
		
		if(b - a == c - b)
		printf("AP %d\n",c + (b - a));
		else{
			long long ans = c * (b / a);
			printf("GP %lld\n",ans);
		}
	}
}
