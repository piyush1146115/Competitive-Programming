#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	
	scanf("%d %d", &n, &k);
	
	double ans = 0.0;
	for(int i = 1; i <= n; i++){
		if(i < k){
			ans += ((double)(1.00/(double)n)*pow(0.5,ceil(log2((double)k/(double)i))));
		}else{
			ans += (double)(1.00/(double)n);
		}
	}
	
	printf("%.12lf\n",ans);
}
