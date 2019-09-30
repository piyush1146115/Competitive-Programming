#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<char, char> mc;
map<char, int> mp;

int main()
{
	string prev, pres, ty;
	
	cin >> prev >> pres >> ty;
	
	for(int i = 0; i < prev.size(); i++){
		if(prev[i] >= 'a' && prev[i] <= 'z')
		{
			prev[i] -= 32;
		}
		if(pres[i] >= 'a' && pres[i] <= 'z')
		{
			pres[i] -= 32;
		}
		
	}
	
	for(int i = 0 ; i < prev.size(); i++)
	{
		char ch = prev[i] + 32;
		mc[ch] = pres[i] + 32;
		mc[prev[i]] = pres[i];
		mp[prev[i]] = 1;
		mp[ch] = 1;
	}
	
	for(int i = 0; i < ty.size(); i++){
		if(mp[ty[i]] == 0){
			cout << ty[i];
		}
		else{
			cout << mc[ty[i]] ;
		}
	}
	cout << endl;
}
