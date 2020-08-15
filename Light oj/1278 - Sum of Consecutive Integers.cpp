/*
 * FILE: 1278 - Sum of Consecutive Integers.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK: http://www.lightoj.com/volume_showproblem.php?problem=1278
 *
 * DATE CREATED: 10.12.2017 21:01:07 +06
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
#define MAX             10000109

ll BM( ll a , ll b , ll m )
{
    if ( b == 0 ) return 1 ;
    ll x = BM(a,b/2,m);
    x = ( x * x )%m ;
    if( b % 2 ) x = ( x * a ) % m ;
    return x ;
}


/********************* Code starts here ************************/

bool chk[MAX + 5];

vector<ll> prime;

void sieve()
{
	
	for(ll i = 2; i <= MAX; i++){
		if(chk[i] == 0){
			for(ll j = i * i; j <= MAX; j += i){
				chk[j] = 1;
			}
			prime.pb(i);
			//debug1(i);
			//getchar();
		}
	}
}

int main() {
sieve();	
	int test;
	/*ll n;
	
	forr(n, 1, 1025){
		ll cnt = 0;
		for(int i = 1; i <= n/2; i++){
			ll sum = i;
			for(int j = i + 1; j <n ;j++){
				sum += j;
				if(sum == n){
					cnt++;
				}
				if(sum > n)
				break;
			}
		}
		debug2(n, cnt);
	}
	*/
	
	scanf("%d", &test);
	
	forr(tc ,1, test){
		ll n;
		scanf("%lld", &n);
		ll sq = (ll)sqrt(n) + 1;
		ll ans = 1;
		for(int i = 0 ; prime[i] <= sq; i++){
			//debug3(i, prime[i], n);
			//debug1(sq);

			ll factor = 0;
			if(n % prime[i] == 0){
				while(n  % prime[i] == 0){
					//debug1(prime[i]);
					n /= prime[i];
					factor++;
				}
				if(prime[i] != 2){
				ans *= (factor + 1);
			}
			sq = (ll)sqrt(n) + 1;
			}
		}
		
		//debug1(n);
		
		if(n > 1){
			if(n != 2){
				//debug1(n);
				ans *= 2;
			}
		}
		
		ans--;
		printf("Case %d: %lld\n",tc, ans);
	}
    return 0;
}
