#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int k;
	
	cin >> s >> k;
	

	
		int c = 0, cnt = 0, i = s.size() - 1;
		
		while(c != k && i >= 0){
		if(s[i] == '0'){
		c++;
		}
		else
		{
			cnt++;
		}
		i--;
		}
		
		if(c == k)
		printf("%d\n",cnt);
		else
		{
			printf("%d\n",cnt + (c -1 ));
		}
	return 0;
}
