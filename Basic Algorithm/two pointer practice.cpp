#include<bits/stdc++.h>
using namespace std;

int ara[100];

int main()
{
	string s;
	int k;
	scanf("%d", &k);
	
	
	while(cin >> s){

		int p1 = 0, p2 = 0;
		int len = s.size();
		
		int cnt = 0,ans = 999999;
		
		memset(ara, 0, sizeof(ara));
		
		while(p1 < len && p2 < len){
			
			int q = s[p2] - '0';
			p2++;
			
			if(q <= k && ara[q] == 0){
				cnt++;
			}
			
			ara[q]++;
			
			if(cnt == k){	
				while(cnt == k && p1 < len){
					q = s[p1] - '0';
					ara[q]--;
					if(q <= k && ara[q] == 0){
						cnt--;
						//break;
					}
					ans = min(ans, p2 -p1);
					p1++;
				}
			}
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
