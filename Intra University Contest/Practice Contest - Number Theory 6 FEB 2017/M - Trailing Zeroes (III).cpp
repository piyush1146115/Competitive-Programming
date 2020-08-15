#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll power[15];
int main()
{
	ll n = 5, ind = 0;
	
	while(n <= 100000000)
	{
//		printf("%d\n",n);
		power[++ind] = n;
		n *= 5;
	}


}
