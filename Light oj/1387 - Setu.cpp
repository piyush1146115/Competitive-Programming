#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		long long total = 0;
		
		int n;
		
		scanf("%d", &n);
		
		printf("Case %d:\n",tc);
		while(n--){
			string s;
			int m;
			cin >> s;
			
			if(s == "report")
				cout << total << endl;
			else{
				cin >> m;
				total += m;
			}
		}
	}
}
