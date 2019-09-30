#include<bits/stdc++.h>
using namespace std;
int ara[150];
int main()
{
	int n;
	
	while(scanf("%d",&n) == 1){
		getchar();
		if(n == 0)
		break;
		
		memset(ara, 0, sizeof(ara));
		
		string s;
		getline(cin, s);
		
		int p1 = 0, p2 = 0, len = s.size();
		int cnt = 0, ans = 0;
		
		while(p1 < len && p2 < len){	
			if(ara[s[p2]] == 0){
				cnt++;
			}
			ara[s[p2]]++;
			p2++;
			if(cnt > n){
				while(cnt > n && p1 < len){
					ara[s[p1]]--;
				
					if(ara[s[p1]] == 0)
					cnt--;
					
						p1++;
				}
			}
			//cout << s[p2]
			ans = max(ans, (p2 - p1));
		}
		
		printf("%d\n",ans);
	}
}
