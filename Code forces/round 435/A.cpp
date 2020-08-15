#include<bits/stdc++.h>
using namespace std;
int ara[105], mp[105];

int main()
{
	int n, k;
	
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
	cin >> ara[i];
	mp[ara[i]] = 1;
}
int cnt = 0;
for(int i = 0; i < k; i++){
	if(mp[i] == 0){
		cnt++;
	}
}
if(mp[k] == 1)
cnt++;

cout << cnt << endl;
//main();
}

