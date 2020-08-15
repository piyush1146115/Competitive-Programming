
#include<bits/stdc++.h>
using namespace std;
#define MAX 1005

map<string, string> mp;
string cm[MAX], ipp[MAX];
int main() {

	int n, m;
	cin >> n >> m;
	
	for(int i = 1 ; i <= n; i++){
		string s1, s2;
		cin >> s1 >> s2;
		s2 += ';';
		mp[s2] = s1;
		
	//	cout << mp[ss] << endl;
	}
		for(int i = 1;i <= m;i++){
		cin >> cm[i] >> ipp[i];
		//cout << s << " " << ss << " #" << mp[ss] << endl ;
	}
			for(int i = 1;i <= m;i++){
	//	cin >> com[i] >> ip[i];
		cout << cm[i] << " " << ipp[i] << " #" << mp[ipp[i]] << endl ;
	}
	
    return 0;
}
