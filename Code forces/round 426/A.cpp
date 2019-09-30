#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long  n;
	map<char, int > mp;
	
	mp['v'] = 1;
	mp['<'] = 2;
	mp['^'] = 3;
	mp['>'] = 4;
	
	map<int, char> mp2;
		
	mp2[1] = 'v';
	mp2[2] = '<';
	mp2[3] = '^';
	mp2[4] = '>';
	
	//mp['v'] = 0;
	char ch1, ch2;
	cin >> ch1 >> ch2;
	
	int in = mp[ch1];
	//int fn = mp[ch2];
	//mod = 4;
	cin >> n;
	
	n = n % 4;
	
	long long  cl = in +  n;
	if(cl > 4){
		cl = (cl % 4);
	}
	int acl = in - n;
	if(acl <= 0)
	acl += 4;
	if(mp2[cl] == ch2 && mp2[acl] == ch2){
		printf("undefined\n");
	}
	else if(mp2[cl] == ch2){
		printf("cw\n");
	}
	else if(mp2[acl] == ch2){
		printf("ccw\n");
	}
	
	
	
}
