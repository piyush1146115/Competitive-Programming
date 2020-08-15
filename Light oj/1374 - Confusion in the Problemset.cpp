#include<bits/stdc++.h>
using namespace std;

map<int, int> mp;
int main()
{
	int test;
	
	scanf("%d", &test);
	int n;
	
	for(int tc = 1; tc <= test; tc++){
		scanf("%d", &n);
		int m;
		
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &m);
			mp[m]++;
		}
		int flag = 1;
		
		for(int i = 1; i <= n; i++){
			int p = i - 1;
			int q = abs(n - i);
			if(mp[p] > 0){
				mp[p]--;
			}
			else if(mp[q] > 0){
				mp[q]--;
			}
			else{
				flag = 0;
				break;
			}
		}
		mp.clear();
		
		printf("Case %d: ",tc);
		
		if(flag)
		printf("yes\n");
		else
		printf("no\n");
		
	}
	return 0;
}
