#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m, d, total;
	
	cin >> m >> d;
	
	if(m == 2)
	total = 28;
	else if(m == 4 || m == 6 || m == 9 || m == 11)
	total = 30;
	else
	total = 31;
	
	int rem = 8 - d;
	
	int ans = 1;
	
	rem = total - rem;
	
	ans += (rem / 7);
	
	if(rem % 7 != 0)
	ans++;
	
	cout << ans << endl;
}
