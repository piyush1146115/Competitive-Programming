#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 200005

int cum[MAX][5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int test;
	
	cin >> test;
	
	string s;
	
	while(test--){
		cin >> s;
		
		int n = (int)s.size();
		
		
		
		for(int i = 1; i <= n; i++){
			cum[i][s[i - 1] - '0']++;
			
			cum[i][1] += cum[i - 1][1];
			cum[i][2] += cum[i - 1][2];
			cum[i][3] += cum[i - 1][3];
			
			
		}
		
		int ans = 0;
		int lo = 3, hi = n, mid;
		
		while(lo <= hi){
			mid = (lo + hi)/2;
			int l , r;
			
			l = 1;
			r = l + mid -1;
			
			//cout << l << ' ' << r << endl;
			
			bool flag = true;
			while(r <= n){
				flag = true;
				
				if((cum[r][1] - cum[l - 1][1]) == 0) flag = false;
				if((cum[r][2] - cum[l - 1][2]) == 0) flag = false;
				if((cum[r][3] - cum[l - 1][3]) == 0) flag = false;
				
				if(flag){
					break;
				}
				r++;
				l++;
			}
			
			if(flag){
				hi = mid - 1;
				ans = mid;
			}
			else{
				lo = mid + 1;
			}
		}
		
		for(int i = 1; i <= n; i++)
			cum[i][1] = cum[i][2] = cum[i][3] = 0;
			
		cout << ans << endl;
	}
}
