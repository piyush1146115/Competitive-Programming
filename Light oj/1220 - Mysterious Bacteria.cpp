/*
 * FILE: 1220 - Mysterious Bacteria.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK: http://www.lightoj.com/volume_showproblem.php?problem=1220
 *
 * DATE CREATED: 10.12.2017 13:17:05 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 10-12-2017	1.0         File Created
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
#define MAX             50005

ll BM( ll a , ll b , ll m )
{
    if ( b == 0 ) return 1 ;
    ll x = BM(a,b/2,m);
    x = ( x * x )%m ;
    if( b % 2 ) x = ( x * a ) % m ;
    return x ;
}


/********************* Code starts here ************************/

vector<ll> prime;
bool chk[MAX + 5];

void sieve()
{
	for(ll i = 2; i <= MAX; i++){
		if(chk[i] == 0){
			for(ll j = i * i; j <= MAX; j+= i){
				chk[j] = 1;
			}
			prime.pb(i);
		}
	}
}
/*
 * There can be negetive numbers as input.
 * for negetive numbers the power must be an odd number
 */
 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    //sieve();
    int test;
    scanf("%d", &test);
    vector<ll> factor;
    forr(tc , 1, test){
		ll n;
		scanf("%lld", &n);
		
//		ll sq = (ll)sqrt(n) + 1;
		/*
		for(int i = 0; prime[i] <= sq; i++){
			if(n % prime[i] == 0){
				ll f = 0;
				while(n % prime[i] == 0){
					f++;
					n /= prime[i];
				}
				sq = (ll)sqrt(n) + 1;
				factor.pb(f);
			}
		}
		if(n > 1){
			factor.pb(1);
		}
		
		ll ans = factor[0];
		
		rep(i, factor.size()){
			ans = __gcd(ans, factor[i]);
		}*/
		
		ll ans = 1;
		ll temp = abs(n);
		ll sq = (ll)sqrt(temp) + 1;
		for(int i = 2; i <= sq; i++){
			ll m = temp;
			if(m % i == 0){
				ll res = 0;
			while(m % i == 0){
				res++;
				m /= i;
			}
			if(n < 0){
				if(res % 2 == 0){
					continue;
				}
			}
			if(m == 1){
				ans = max(res, ans);
				break;
			}
		}
		}
		
		printf("Case %d: %lld\n",tc, ans);
		//factor.clear();
	}
    return 0;
}
