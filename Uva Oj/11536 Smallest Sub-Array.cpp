#include<bits/stdc++.h>
using namespace std;
#define mxx 1000005
int ara[mxx];
int  flag[105];

int main()
{
	int test;
	
	scanf("%d", &test);
	int n, m, k;
	
	for(int tc = 1; tc <= test; tc++){
		scanf("%d %d %d",&n, &m, &k);
		
		ara[1] = 1;
		ara[2] = 2 % m;
		ara[3] = 3 % m;
		memset(flag, 0, sizeof(flag));
		
		for(int i = 4; i <= n; i++)
		{
			ara[i] = (ara[ i - 1] + ara[i - 2] + ara[i - 3])%m + 1;
		}
		int cnt = 0, ans = 9999999, p1 = 1, p2 = 1;
		int paisi = 0;
		
		/*for(int i = 1; i <= n; i++)
		printf("%d ",ara[i]);
		
		printf("\n");*/
		
		
		while(p1 <= n && p2 <= n){
			if(ara[p2] <= k){
				if(flag[ara[p2]] == 0){
					cnt++;
				}
				flag[ara[p2]]++;
			}
			p2++;
			
			if(cnt == k){
				paisi = 1;
				while(p1 <= n && cnt == k){
					if(ara[p1] <= k){
						flag[ara[p1]]--;
						if(flag[ara[p1]] == 0){
							cnt--;
						}
					}
					ans = min(ans, p2 - p1);
					p1++;
				}
			}
		}
		
		if(paisi){
			printf("Case %d: %d\n",tc, ans);
		}
		else{
			printf("Case %d: sequence nai\n",tc);
		}
		
	}
}
