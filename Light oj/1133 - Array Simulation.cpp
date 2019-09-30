#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll ara[105];

int main()
{
	int test;
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
	int n, m;
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i++){
		scanf("%lld", &ara[i]);
	}
	
	while(m--){
		string ch;
	cin >> ch;
	
		//scanf("%c", &ch);
		if(ch == "S"){
			int d;
			scanf("%d",&d);
			
			for(int i = 0; i < n; i++)
			ara[i] += d;
			
		}
		else if(ch == "M"){
			int d;
			scanf("%d", &d);
			
			for(int i = 0; i < n; i++){
				ara[i] *= d;
			}
		}
		else if(ch == "D"){
			int d;
			scanf("%d",&d);
			
			for(int i = 0; i < n; i++)
			ara[i] /= d;
		}
		else if(ch == "P")
		{
			int x, y;
			scanf("%d %d",&x,&y);
			swap(ara[x], ara[y]);
		}
		else{
			for(int i = 0; i < n/2; i++){
				swap(ara[i], ara[n - i - 1]);
			}
		}
	}
	
	printf("Case %d:\n%lld",tc, ara[0]);
	
	for(int i = 1; i < n; i++)
	printf(" %lld",ara[i]);
	
	printf("\n");
}
	
	
}
