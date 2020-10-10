#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 100005

ll ara[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> ara[i];
	
	ll mn = 0;
	
	sort(ara, ara + n);
	
	for(int i = 0; i < n; i++)
		mn += (ara[i] - 1);
	
	ll p = 1, sum = 0;
	for(ll v = 2; v < MAX; v++){
	  p = 1, sum = 0;
		for(int i = 0; i < n; i++){
			sum += abs(ara[i] - p);
			if(sum > mn)
				break;
			p *= v;
		}
		mn = min(mn, sum);
	}
	
		p = 1;s
	for(int i = 0; i < n; i++){
			sum += abs(ara[i] - p);
			if(sum > mn)
				break;
			p *= ara[1];
		}
		mn = min(mn, sum);
		
		cout << mn << endl;
}	
