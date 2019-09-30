#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define pii pair<int, int>
#define DB(a) cout <<#a <<" " << a << endl;

int main()
{
	int n, k;
	scanf("%d %d",&n, &k);
	int ara[105];
	int cnt, cnt6, cnt4, cnt2, cnt1;
	cnt = cnt2 = cnt4 = cnt6 = cnt1 = 0;
	
	for(int i = 0; i < k;i++){
		scanf("%d",&ara[i]);
		if(ara[i] >= 8){
			cnt++;
			ara[i] = ara[i] % 8;
		}
	}
	
	for(int i = 0; i < k; i++){
		if(ara[i] == 0){
			continue;
		}
		else if(ara[i] == 1){
			cnt1++;
		}
		else if(ara[i] <= 2){
			cnt2++;
		}
		else if(ara[i] <= 4){
			cnt4++;
		}
		else if(ara[i] <= 6){
			cnt6++;
		}
		else if(ara[i] <= 7){
			cnt6++;
			cnt1++;
		}
	}
	
	n -= cnt;
	
	int flag = 1;

	
	for(int i = 1; ; i++){
		if(n < 0)
		{
			flag = 0;
			break;
		}
		if(cnt6 <= 0)
		{
			break;
		}
		
		cnt6--;
		if(cnt2 >= 1){
		cnt2--;
	}
	else{
		cnt1--;
	}
		n--;
		
	}
	
	if(n>= 1){
		int ann = cnt4/2;
		n -= ann;
		
		if(cnt4 % 2 == 1){
			n--;
			cnt4--;
			if(cnt2 >= 2)
			cnt2 -= 2;
			else if(cnt2 >= 1){
				cnt1--;
				cnt2--;
			}
			else{
				cnt1 -= 2;
			}
		}
		if(n < 0){
			flag = 0;
		}
	}
	
		/*DB(cnt2);
	DB(cnt6);
	DB(cnt4);
	DB(cnt1);
	DB(n);*/
	
	for(int i = 1;; i++){
		if(n < 0)
		{
			flag = 0;
			break;
		}
		
		if(cnt2<= 0){
			break;
		}
		
		//cnt6--;
		if(cnt2 <= 1){
			cnt2--;
			cnt1 -= 3;
		}
		else if(cnt2 <= 2){
			cnt2 -= 2;
			cnt1 -= 2;
		}
		else{
		cnt2 -= 3;
		
		cnt1--;
	}
	n--;
	}
	
	/*	DB(cnt2);
	DB(cnt6);
	DB(cnt4);
	DB(cnt1);
	DB(n);*/
	
	while(1){
		
		if(cnt1 <= 0)
		break;
		n--;
		cnt1 -= 4;
	}
	
	if(n >= 0)
	printf("YES\n");
	else
	printf("NO\n");
	
	//main();
}

