/*
 * FILE: F. Palindrome.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 21.02.2019 13:27:24 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 21-02-2019	1.0         File Created
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
#define MAX             10005

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

int n, m;
pii ara[MAX];
string s;

bool chk()
{
	for(int i = 0; i < m; i++){
		if(s[ara[i].first - 1] == s[ara[i].second -1]){
			continue;
		}
		else{
			if(s[ara[i].first - 1] == '?' || s[ara[i].second - 1] == '?'){
				if(s[ara[i].first - 1] == '?'){
					s[ara[i].first - 1] = s[ara[i].second - 1];
				}
				else{
					s[ara[i].second - 1] = s[ara[i].first - 1];
				}
			}else{
				return false;
			}
		}
	}
	
	return true;
}

bool check()
{
	if(!chk()){
		return false;
	}
	//ckk;
	for(int i = 0; i < n; i++){
		if(s[i] != s[n - i - 1] && (s[i] != '?' && s[n - i - 1] != '?')){
			return false;
		}
	}
	return true;
}
int main() {
    __FastIO;   //Be aware to use it!
    
    int test;
    cin >> test;
    
    while(test--){
		cin >> n >> m >> s;
		
		rep(i, m){
			cin >> ara[i].first >> ara[i].second;
		}
		if(check()){
			//ckk;
			ll ans = 1;
			int iter = n/2 + (n %2);
			int flag = 0;

			for(int i = 0; i < iter; i++){
				if(s[i] == '?' && s[n - i - 1] == '?'){
					ans *= 26;
					ans %= MOD;
					flag = 1;
				}
			}
			cout << ans << endl;
		}
		else{
			cout << "0" << endl;
		}
	}
    return 0;
}
