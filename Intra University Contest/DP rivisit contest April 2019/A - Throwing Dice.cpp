/*
 * FILE: A - Throwing Dice.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 14.04.2019 01:45:45 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 14-04-2019	1.0         File Created
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

ll BM( ll a , ll b)
{
    if ( b == 0 ) return 1 ;
    ll x = BM(a,b/2);
    x = (( x) * (x));
    
    if( b % 2 ) x = (( x) * (a));
    return x ;
}

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/

int main() {
   // __FastIO;   //Be aware to use it!
    int test;
    scanf("%d", &test);
    ll calc[30][155];
    
    forr(tc, 1, test){
		ll n, x;
		scanf("%lld %lld", &n, &x);
		calc[0][0] = 1;
		
		forr(i, 1LL, n){
			forr(j, 1LL, x){
				calc[i][j] = calc[i - 1][j - 1];
				if(j - 2 >= 0){
					calc[i][j] += calc[i - 1][j -2];
				}
				if(j - 3 >= 0){
					calc[i][j] += calc[i - 1][j -3];
				}
				if(j - 4 >= 0){
					calc[i][j] += calc[i - 1][j -4];
				}
				if(j - 5 >= 0){
					calc[i][j] += calc[i - 1][j -5];
				}
				if(j - 6 >= 0){
					calc[i][j] += calc[i - 1][j -6];
				}
			}
		}
		ll sum = 0;
		forr(i, 1, x - 1){
			sum += calc[n][i];
			//debug2(i, calc[n][i]);
		}
		ll lob = BM(6LL, n) - sum;
		ll hor = BM(6LL, n);
		ll ans;
		printf("Case %d: ",tc);
		if(lob % hor == 0){
			ans = lob/hor;
			printf("%lld\n",ans);
		}else{
			ll gc = __gcd(hor, lob);
			hor /= gc;
			lob/= gc;
			printf("%lld/%lld\n",lob, hor);
		}
	}
    
    return 0;
}
