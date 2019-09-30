/*
 * FILE: G - Divisible Group Sums.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 27.03.2019 06:23:32 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 27-03-2019	1.0         File Created
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
#define MAX             205

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

ll n,ara[MAX],D;
ll DP[205][22][12];

ll fun(ll pos, ll sum, ll M)
{
	/*debug3(pos,sum, M);
	getchar();
	*/
	if(M== 0){
		if(sum == 0){
			return 1LL;
		}
		else{
			return 0LL;
		}
	}
	if(pos == n){
		return 0LL;
	}
	
	if(DP[pos][sum][M] != -1){
		return DP[pos][sum][M];
	}
	
	ll ret1 =  0, ret2 = 0;
	if(M > 0){
	ret1 = fun(pos + 1, ((sum + ara[pos])%D + D)%D, M - 1);
}
	ret2 = fun(pos + 1, sum, M);
	
	return DP[pos][sum][M] = (ret1+ret2);
}

int main() {
   // __FastIO;   //Be aware to use it!
    
    ll test, q, m, ans;
    scanf("%lld", &test);
    
	
    
    forr(tc, 1LL, test){
		
		scanf("%lld %lld", &n, &q);
		
		rep(i, n){
			scanf("%lld", &ara[i]);
		}
		
		printf("Case %lld:\n",tc);
		
		while(q--){
			memset(DP, -1, sizeof(DP));
			scanf("%lld %lld", &D, &m);
			ans = fun(0,0,m);
			printf("%lld\n",ans);
		}
		
		
	}
    
    return 0;
}
