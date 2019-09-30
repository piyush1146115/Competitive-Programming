#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	int n, k;
	
	scanf("%d %d",&n, &k );
	
	set<string> ss;
	
	for(int i = 0; i < n; i++){
		string s;
		for(int j = 0; j < k; j++){
			int temp;
			scanf("%d", &temp);
			char c = temp + '0';
			//cout << c << endl;
			s.push_back(c);
		}
		//cout << s << endl;
		ss.insert(s);
	}
	vector<string> vs;
	
	for(auto x : ss){
		vs.push_back(x);
		//cout << x << endl;
	}
	
			int flag = 0;
	for(int i = 0; i < (int)vs.size(); i++){
		//cout << vs[i] << endl;
		
		for(int j = 0; j < (int)vs.size(); j++){
	
			for( k = 0; k < (int)vs[j].size(); k++){
				if((vs[j][k] - '0' + vs[i][k] - '0') > 1){
					break;
				}
			}
			if(k == (int)vs[j].size() && i != j)
			flag = 1;
		}
		
		for(  k = 0; k < (int)vs[i].size(); k++){
		if(vs[i][k] != '0')
		break;
	}
	if(k == (int)vs[i].size())
	flag = 1;
	}
	
	if(flag)
	printf("YES\n");
	else
	printf("NO\n");
	
}
