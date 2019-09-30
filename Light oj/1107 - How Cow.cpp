#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		int n, x1, y1, x2, y2;
		
		scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
		
		scanf("%d", &n);
		printf("Case %d:\n",tc);
		
		while(n--){
		int x, y;
		scanf("%d %d",&x, &y);
		
		if(x >= x1 && x <= x2 && y >= y1 && y <= y2)
		printf("Yes\n");
		else
		printf("No\n");
		
		}
	}
	return 0;
}
