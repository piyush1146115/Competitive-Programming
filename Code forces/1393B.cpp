#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

int cnt[MAX];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n, temp;
	cin >> n;
	
	int sq = 0, rec = 0;
	
	for(int i = 0; i < n; i++){
		cin >> temp;
		
		sq -= (cnt[temp]/4);
		rec -= (cnt[temp]/2);
		
		cnt[temp]++;
		
		sq += (cnt[temp]/4);
		rec += (cnt[temp]/2);
	}
	
	int q;
	cin >> q;
	
	while(q--){
		char ch;
		
		cin >> ch >> temp;
		
		sq -= (cnt[temp]/4);
		rec -= (cnt[temp]/2);
		
		if(ch == '+')
			cnt[temp]++;
		else
			cnt[temp]--;
		
		sq += (cnt[temp]/4);
		rec += (cnt[temp]/2);
		
		if(sq >= 1 && rec >= 4)
			cout << "YES\n";
		else
			cout << "NO\n";

	}
}

