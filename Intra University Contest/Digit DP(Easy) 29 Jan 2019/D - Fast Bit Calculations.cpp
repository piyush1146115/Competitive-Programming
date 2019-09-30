/*
 * FILE: D - Fast Bit Calculations.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 30.01.2019 22:40:14 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 30-01-2019	1.0         File Created
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
string s;
int sz;
ll dp[33][3][3][33];

ll fun(int pos, int boro, int prev, ll cnt)
{
	if(pos >= sz){
		return cnt;
	}
	
	if(dp[pos][boro][prev][cnt] != -1){
		return dp[pos][boro][prev][cnt];
	}
	
	int hi = 1;
	if(boro == 1){
		hi = s[pos] - '0';
	}
	
	ll ret = 0, n_cnt;
	int n_boro;
	
	for(int i = 0; i <= hi; i++){
		n_cnt = cnt;
		n_boro = boro;
		if(i < hi){
			n_boro = 0;
		}
		if(prev == 1 && i == 1){
			n_cnt = cnt + 1;
		}
		ret += fun(pos + 1, n_boro, i, n_cnt);
	}
	return dp[pos][boro][prev][cnt] = ret;
}

int main() {
    __FastIO;   //Be aware to use it!
    
    int test;
    scanf("%d", &test);
    ll num;
    
    forr(tc, 1, test){
		s.clear();
		fill(dp);
		scanf("%lld", &num);
		//cin >> s;
		while(num != 0){
			s.pb((char)(num % 2 + 48));
			num /= 2;
		}
		reverse(all(s));
		sz = (int)s.size();
		//debug1(s);
		ll ans = fun(0, 1, 0, 0);
		printf("Case %d: %lld\n",tc, ans);
	}
	
    return 0;
}
