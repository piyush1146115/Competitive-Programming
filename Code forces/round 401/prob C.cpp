#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m, n;
	
	scanf("%d %d",&m, &n);
	
	int ara[m + 5][n + 5];
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d",&ara[i][j]);
		}
	}
	
	int sorted[m + 5][n + 5];
	int res[m + 5];
	//memset(, 0, sizeof()
	
	for(int i = 0; i <= m; i++)
	res[i] = 1000000;
	
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
		if(i == 1)
		sorted[i][j] = 1;
		else if(ara[i][j] >= ara[i- 1][j])
		sorted[i][j] = sorted[i - 1][j];
		else
		sorted[i][j] = i;
		
		res[i] = min(sorted[i][j] , res[i]);
		}
	}
	
	int q;
	
	scanf("%d", &q);
	
	while(q--){
	int l, r;
	
	scanf("%d %d",&l, &r);
	
	cout << l << " " << res[r] << endl;
	
	if(res[r] <= l)
	printf("Yes\n");
	else
	printf("No\n");
}	
	return 0;
}

