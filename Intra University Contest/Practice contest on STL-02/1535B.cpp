#include <bits/stdc++.h>
using namespace std;

int t, n, ans, ar[100010];

bool cmp(int x, int y) {
    
    if(x == y)
        return false;

	if (x % 2 == 1) {
		return false;
	}
	 if(y % 2 == 1){
		return true;
	}

	return false;
}


int main() {
	cin >> t;
	
	while (t--) {
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}

		ans = 0;

		sort(ar, ar + n, cmp);
		
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (__gcd(ar[i], (2 * ar[j])) > 1) {
					ans++;
				}
			}
		}

		cout << ans << endl;
	}
}
