#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	s[k -1] = (char)tolower(s[k - 1]);
	cout << s << endl;
}
