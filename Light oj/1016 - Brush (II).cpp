#include<bits/stdc++.h>
using namespace std;
#define mxx 50005

struct st{
	
	long long x, y;
	
	bool operator <(const st &p)const{
		
		return y < p.y;
	}
}ara[mxx];


int main()
{
	int test, n, w;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		scanf("%d %d",&n, &w);
		
		for(int i = 0; i < n; i++){
			scanf("%lld %lld", &ara[i].x, &ara[i].y);
		}
		
		sort(ara, ara + n);
		long long int k = ara[0].y;
		int cnt  = 1;
		
		for(int i = 0; i < n; i++){
			if(k + w >= ara[i].y){
				continue;
			}
			else{
				k = ara[i].y;
				cnt++;
			}
		}
		
		printf("Case %d: %d\n",tc, cnt);
	}
	return 0;
}
