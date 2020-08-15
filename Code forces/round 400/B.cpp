#include<bits/stdc++.h>
using namespace std;
#define mxx 1000005

int chk[mxx];

void sieve( int n)
{
	for(int i = 4; i <= n; i += 2)
	chk[i] = 1;
	
	for(int i = 3; i * i <= n; i += 2){
	if(chk[i] == 0){
		for(int j = i * i; j <= n; j += (i * 2))
		chk[j] = 1;
	}
	}
	
}

int main()
{
	
	int n;
	
	cin >> n;
	
	sieve(n + 1);
	int cnt = 0;
	
	for(int i = 2; i <= n + 1; i++){
		if(chk[i] == 0){
			cnt++;
		}
	}
	
	
	if(cnt == n)
	cout << 1 << endl;
	else
	cout << 2 << endl;
	
	
	//printf("%d\n", ans);
	
	for(int i = 2; i <= n + 1; i++){
	if(chk[i] == 0)
	printf("1 ");
	else
	printf("2 ");
}	
	printf("\n");
	
}
