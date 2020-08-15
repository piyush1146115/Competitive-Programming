#include<bits/stdc++.h>
using namespace std;
int dp[11][3][1000][100];

int n, r;
string s;

 int fun(int pos, int state, int rem, int sum)
{
	if(pos >= n){
		if(sum % r == 0 && rem == 0)
		return 1;
		else
		return 0;
	}
	if(dp[pos][state][rem][sum] != -1){
		return dp[pos][state][rem][sum];
	}
	
	int low, high;
	
	low = 0, high = 9;
	
	if(state == 1)
	high = s[pos] - '0';
	int res = 0;
	for(int i = low; i <= high; i++){
		int n_sum = sum + i;
		int n_rem = (i + rem *10) % r;
		int n_state = 0;
		if(state == 1 && i == high)
		n_state = 1;
		res += fun(pos + 1, n_state, n_rem, n_sum);
	}
	dp[pos][state][rem][sum] = res;
	return dp[pos][state][rem][sum];
	//return res;
}

int main(){
int test;
	scanf("%d",&test);

	for(int tc = 1; tc <= test; tc++){

	string a, b, temp;
	int dif = 0;
	temp = "";
    cin >> a >> b >> r;

	if(a.size() < b.size() ){
		dif = b.size() - a.size();
		while(dif--){
			temp += '0';
		}
		a = temp + a;
	}
	else if(b.size() < a.size()){
		dif = a.size() - b.size();

		while(dif--){
			temp += '0';
		}
		b = temp + b;
	}
	n = a.size();
	s = a;
	int ans = 0;
	
	if(r < 90){
		memset(dp, -1, sizeof(dp));
	int  r1 = fun(0, 1, 0, 0);
	s = b;
	memset(dp, -1, sizeof(dp));
	int  r2 = fun(0, 1, 0, 0);
	  ans = abs(r1 - r2);
	
	int rem = 0, sum = 0;
	for(int i = 0; i < a.size(); i++){
		sum += (a[i] - '0');
		rem = ((a[i] - '0') + rem * 10) % r;
	}
	if(rem == 0 && sum % r == 0)
	ans++;
}
else{
	 ans = 0;
}
//	cout << ans << endl;
printf("Case %d: %d\n",tc, ans);
}
return 0;
}


