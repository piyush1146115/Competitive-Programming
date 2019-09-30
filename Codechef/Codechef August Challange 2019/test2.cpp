#include<stdio.h>
int main()
{
	/*int n, ls;
	scanf("%d %d", &n, &ls);
	
	int ans = n >> ls;
	
	printf("n === %d \t ls === %d\t ans === %d\n", n, ls, ans);
	*/
	
	int n;
	int ara[15];
	scanf("%d", &n);
	int i = 0;
	for(i = 0; i < n; i++){
		scanf("%d", &ara[i]);
	}
	
	int mx = (1 << n) -1;
		int j = 0, ck, sum;
	for(i = 0; i < mx; i++){
		sum = 0;
		for(j = 0; j < n; i++){
			ck = 1 << j;
			if(ck & i > 0){
				sum += ara[i];
			} 
		}
	}
//3147483648 == -1147483648
//3147483649 == -1147483647
//3147483650 == -1147483646
//3147483651 ==  -1147483645
}
