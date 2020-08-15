#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int n;
	string a, b, q, p;
	
	cin >> a >> b;
	cin >> n;
	map<string, int> mp;
	cout << a << " " << b << endl;
	vector<string> v;
	v.push_back(a);
	v.push_back(b);
	
	while(n--){
	cin >> a >> b;
	mp[a] = 1;
	v.push_back(b);
	
	for(int i = 0; i < v.size(); i++){
	if(mp[v[i]] == 0){
	cout << v[i] << " ";
	break;
}	
	}
	
	cout << b << endl;
}

return 0;
}
