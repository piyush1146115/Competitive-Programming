#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test, n;
	
	scanf("%d", &test);
	string s;
	
	for(int tc = 1; tc <= test; tc++){
		cin >> n  >> s;
		
		int cnt = 0, ans = 0;
		
		for(int i = 0 ; i < n; i++){
			if(s[i] == '.')
			cnt++;
			else{
				if(cnt > 0)
				cnt++;
			}
			
			if(cnt == 3)
			{
				cnt = 0;
				ans++;
			}
		}
		if(cnt> 0)
		ans++;
		
		printf("Case %d: %d\n",tc, ans);
	}
}
