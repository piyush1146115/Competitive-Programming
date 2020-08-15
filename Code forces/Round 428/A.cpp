#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define pii pair<int, int>
#define DB(a) cout <<#a <<" " << a << endl;

int main()
{
	int n, k;
	cin >> n >> k;
	int ara[105];
	
	for(int i = 0; i < n; i++){
		cin >> ara[i];
	}
	int sum = 0, cnt = 0, ch = 0;
	
	for(int i = 0; i < n; i++){
		sum += ara[i];
		cnt++;
		if(sum >= 8){
			ch += 8;
			sum -= 8;
		}
		else{
			ch += sum;
			sum = 0;
		}
		if(ch >= k){
			break;
		}
	}
	
	if(ch >= k){
		cout << cnt << endl;
	}
	else{
		cout << -1 << endl;
	}
	//main();
	
}

