#include<bits/stdc++.h>
using namespace std;
int ara[1005];

int main()
{
	int n, c, t1, t2;
	
	cin >> n >> c >> t1 >> t2;
	
	if(t2 < t1)
	swap(t2, t1);
	
	
	for(int i = 0; i < n; i++)
	cin >> ara[i];
	
	int p1 = 0, p2 = 1;
	ara[n] = c;
	int ans = 0;
	
	while(p1 < n && p2 < n){
		
		int dif = ara[p2] - ara[p1];
		
		if(dif > t2){
			int d = p2 - p1;
			if(d * t1 < t2){
				p1++;
				ans += t1;
				continue;
			}
			else{
				p1 = p2;
				ans += t2;
			}
		}
		else if(dif == t2){
			ans += t2;
			p1 = p2 + 1;
			
		}
	p2++;
	}
	if(p1 < n)
	ans += t1;
	cout << ans << endl;
}
