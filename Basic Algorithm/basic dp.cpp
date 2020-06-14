#include<bits/stdc++.h>
using namespace std;
string s;
//int dp[10][15][15];
int n;
int fun(int pos, int state, int cnt)
{
	int sum = 0, low = 0, high = 9, next_state;
	
	 if(pos >= n){
		return cnt;
	}	
	if(state == 1){
	high = s[pos] - 48;
	}
	for(int i = low; i <= high; i++)
	{
		int n_cnt = cnt;
		if(state == 0){
		next_state = 0;
		}
		else{
			if(i == high){
				next_state = 1;
			}
			else{
				next_state = 0;
			}
		}
		if(i == 2)
		n_cnt = cnt + 1;
		
		sum += fun(pos + 1, next_state, n_cnt);
	}
	
//	dp[pos][state][cnt] = sum;
	//return dp[pos][state][cnt];
	return sum;
}

int main()
{
	//memset(dp, -1, sizeof(dp));
		cin >> s;
	n = s.size();
	
	int res = fun(0, 1, 0);	
	cout << res << endl;
}
