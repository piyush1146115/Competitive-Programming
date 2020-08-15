/*
 * FILE: B - How Many Zeroes.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 29.01.2019 20:35:53 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 29-01-2019	1.0         File Created
 *
 */


/*
// _______________________________________________________________/\\\_________
//  ______________________________________________________________\/\\\_________
//   ___/\\\\\\\\\___/\\\____/\\\__/\\\____________________________\/\\\_________
//    __/\\\/////\\\_\///____\//\\\/\\\___/\\\____/\\\__/\\\\\\\\\\_\/\\\_________
//     _\/\\\\\\\\\\___/\\\____\//\\\\\___\/\\\___\/\\\_\/\\\//////__\/\\\\\\\\\\__
//      _\/\\\//////___\/\\\_____\//\\\____\/\\\___\/\\\_\/\\\\\\\\\\_\/\\\/////\\\_
//       _\/\\\_________\/\\\__/\\_/\\\_____\/\\\___\/\\\_\////////\\\_\/\\\___\/\\\_
//        _\/\\\_________\/\\\_\//\\\\/______\//\\\\\\\\\___/\\\\\\\\\\_\/\\\___\/\\\_
//         _\///__________\///___\////_________\/////////___\//////////__\///____\///__
//
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef double              lf;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<pii>         vpii;
typedef vector<int>         vi;
typedef vector<long long>   vll;

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()

#define fill(ar)   		memset(ar, -1, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"

#define pb              push_back
#define MP 				make_pair

#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define gama 0.57721566490
#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             100005

ll BM( ll a , ll b , ll m )
{
    if ( b == 0 ) return 1 ;
    ll x = BM(a,b/2,m);
    x = (( x % m) * (x % m))%m;
    
    if( b % 2 ) x = (( x % m) * (a %m)) % m ;
    return x ;
}

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/
ll dp[20][3][3][20];
string s;

ll fun(int pos,int boro, int isStart, int cnt)
{
	if(pos >= (int)s.size()){
		return cnt;
		
	}
	
	if(dp[pos][boro][isStart][cnt] != -1){
		return dp[pos][boro][isStart][cnt];
	}
	
	int hi = 9;
	if(boro){
		hi = s[pos] - '0';
	}
	
	ll ret = 0;
	
	for(int i = 0; i <= hi; i++){
		int n_cnt = cnt, n_boro = 0, n_start = isStart;
		if(i == 0 && isStart == 1){
				n_cnt = cnt + 1;
		}
		if(boro == 1 && i == hi){
			n_boro = 1;
		}
		if(i > 0){
			n_start = 1;
		}
		ret += fun(pos + 1, n_boro,n_start, n_cnt);
	}
	
	
	dp[pos][boro][isStart][cnt] = ret;
	return ret;
}


int main() {
    //__FastIO;   //Be aware to use it!
	
	int test;
	scanf("%d", &test);
	string a, b, temp;
	
	forr(tc, 1, test){
		fill(dp);
		cin >> a >> b;
		temp.clear();
		int dif = abs((int)a.size() - (int)b.size());
		while(dif--){
			temp.pb('0');
		}
		
		if((int)a.size() < (int)b.size()){
			a = temp + a;
		}
		else{
			b = temp + b;
		}
		
	//	debug2(a, b);
		
		s= a;
		ll hi = fun(0, 1, 0, 0);
		fill(dp);
		s = b;
		ll lo = fun(0, 1, 0, 0);
		ll ans = abs(hi - lo);
		int flag = 0;
		rep(i, a.size()){
			if(i == ((int)a.size() -1) || a[i] > '0'){
				flag = 1;
			}
			if(flag && a[i] == '0'){
				ans++;
			}
			//debug3(i, a[i], ans);
		}
		//debug2(hi, lo);
		printf("Case %d: %lld\n",tc, ans);
	}
	
    return 0;
}
