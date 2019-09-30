#include<bits/stdc++.h>
using namespace std;
int chk[1005],  chk2[1005];

int main()
{
	string a, b;
	int n;
	cin >> n;
	cin >> a >> b;
	
	sort(b.begin(), b.end());
	sort(a.begin(), a.end());
	
	reverse(a.begin(), a.end());
	
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[j] <= b[i] && chk[j] == 0){
				cnt++;
				chk[j] = 1;
				break;
			}
		}
	}
	
	cout << n - cnt << endl;
	 cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[j] < b[i] && chk2[j] == 0){
				cnt++;
				chk2[j] = 1;
				break;
			}
		}
	}
	
	cout << cnt << endl;
	
}

