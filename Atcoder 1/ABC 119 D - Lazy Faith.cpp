/*
 * FILE: ABC 119 D - Lazy Faith.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 09.08.2019 14:14:36 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 09-08-2019	1.0         File Created
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
#define INF             0x7ffffffffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             100005

int Set(int N,int pos){return N=N | (1<<pos);}
int Reset(int N,int pos){return N= N & ~(1<<pos);}
bool Check(int N,int pos){return (bool)(N & (1<<pos));}


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
vll shrimp, temple;
int main() {
    __FastIO;   //Be aware to use it!
    
    ll A, B , Q;
    cin >> A >> B >> Q;
    
    ll k;
    
    rep(i, A){
		cin >> k;
		shrimp.pb(k);
	}
	
	rep(i, B){
		cin >> k;
		temple.pb(k);
	}
	ll a, b, c, d;
	rep(i, Q){
		cin >> k;
		
		ll los = lower_bound(shrimp.begin(), shrimp.end(), k) - shrimp.begin();
		//ll his = upper_bound(shrimp.begin(), shrimp.end(), k) - shrimp.begin();
		ll lot = lower_bound(temple.begin(), temple.end(), k) - temple.begin();
		//ll hit = upper_bound(temple.begin(), temple.end(), k) - temple.begin();
		//debug3(k, los, shrimp[los]);
		//debug3(k, his, shrimp[his]);
		//debug3(k, lot, shrimp[lot]);
		//debug3(k, hit, shrimp[hit]);
		 
		if(los == 0){
			a = -INF;
		}else{
			a = shrimp[los - 1];
		}
		if(los == A){
			b = INF;
		}
		else{
			b = shrimp[los];
		}
		
		if(lot == 0){
			c = -INF;
		}
		else{
			c = temple[lot - 1];
		}
		
		if(lot == B){
			d = INF;
		}else{
			d = temple[lot];
		}
		
		ll sol = max(abs(k - a), abs(k - c));
		sol = min(sol, max(abs(k - b), abs(k - d)));
		sol = min(sol, 2LL * abs(k - a) + abs(k - d));
		sol = min(sol, 2LL * abs(k - c) + abs(k - b));
		sol = min(sol, 2LL * abs(k - b) + abs(k - c));
		sol = min(sol, 2LL * abs(k - d) + abs(k - a));
		
		cout << sol << endl;
	}
    
    return 0;
}
