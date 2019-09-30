#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a, b;
	
	cin >> a >> b;
	
	int ans = 0;
	if(a.size() == b.size())
	{
		int flag = 0;
		for(int i = 0; i < a.size(); i++){
			if(a[i] != b[i])
			{
				flag = 1;
				printf("%d\n",a.size());
				break;
			}
		}
		if(flag == 0)
		printf("-1\n");
	}
	else{
		printf("%d\n",max(a.size(), b.size()));
	}
	
	return 0;
}
