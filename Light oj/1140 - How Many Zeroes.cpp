#include<bits/stdc++.h>
using namespace std;
long long int dp[25][3][250][3];
long long int n;
 string s;

long long int fun(long  long int pos,long long int state, long long int cnt,long long  int flag)
{

if(pos >= n){
return cnt;
}
if(dp[pos][state][cnt][flag] != -1){
return dp[pos][state][cnt][flag];
}

long long int high = 9;

if(state == 1)
high = s[pos] - '0';

long long int sum = 0;

for(int i = 0; i <= high; i++){
	long long int n_state = 0, n_cnt = cnt;
	if(i == high && state == 1)
	{
			n_state = 1;
	}
	
	int n_flag = 0;
	if(flag == 1 || i > 0)
	n_flag = 1;

	if(flag == 1 && i == 0)
	 n_cnt = cnt + 1;

	sum += fun(pos + 1, n_state, n_cnt, n_flag);
}
dp[pos][state][cnt][flag] = sum;
return dp[pos][state][cnt][flag];
}


int main()
{
	int test;
	scanf("%d",&test);

	for(int tc = 1; tc <= test; tc++){

	string a, b, temp;
	int dif = 0;
	temp = "";
    cin >> a >> b;

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
	memset(dp, -1, sizeof(dp));
	long long r1 = fun(0, 1, 0, 0);
	s = b;
	memset(dp, -1, sizeof(dp));
	long long r2 = fun(0, 1, 0, 0);
	long long int ans = abs(r1 - r2);
	int flag = 0;

	for(int i = 0; i < a.size();i++){
		if(a[i] > '0' || (i == a.size() - 1)){
			flag = 1;
		}
		if(flag == 1 && a[i] == '0')
		ans++;
	}

//	cout << ans << endl;
printf("Case %d: %lld\n",tc, ans);
}
return 0;
}


