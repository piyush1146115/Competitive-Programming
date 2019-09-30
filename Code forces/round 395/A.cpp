#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, z;
	
	cin >> n >> m >> z;
	
	int cnt = 0;
	for(int i = m; i <= z; i+= m){
		if(i % n == 0)
		cnt++;
	}
	
	cout << cnt << endl;
}
