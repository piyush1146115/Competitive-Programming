#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<int, int> mp;
	int n, m;
	
	scanf("%d", &n);
	
	int cnt = 0, ans = 0;
	
	n *= 2;
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		mp[m]++;
		if(mp[m] % 2 == 1)
		cnt++;
		
		if(mp[m]  % 2 == 0){
		cnt--;
		mp[m] = 0;
		}
		ans = max(ans, cnt);
	}
	
	cout << ans << endl;
}
