/*
 * FILE: 1079 - Just another Robbery  Bin Ser Dp.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 25.09.2018 22:55:19 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 25-09-2018   1.0         File Created
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

#define fill(ar)        memset(ar, -1, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"

#define pb              push_back
#define MP              make_pair

#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define gama 0.57721566490
#define PI              acos(-1.0)
#define INF             -13215654648.0
#define MOD             1000000007
#define EPS             1e-7
#define MAX             105

ll BM( ll a, ll b, ll m ) {
    if ( b == 0 ) return 1 ;
    ll x = BM(a, b / 2, m);
    x = (( x % m) * (x % m)) % m;

    if ( b % 2 ) x = (( x % m) * (a % m)) % m ;
    return x ;
}

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/
int M[MAX], n;

double prob[MAX],p, dp[MAX][MAX * MAX];
int mid;

double fun(int ind, int v){
	if(v <= 0){
			return 0.0;
		}
	if(ind == n){
		return 1.0;
	}
	if(dp[ind][v] >= 0.0){
		return dp[ind][v];
	}
	
	double f1 = fun(ind + 1, v - M[ind]);
	double f2 = fun(ind + 1, v);
	
	f1 = f1 + (1.0 - f1)*prob[ind];
	double ret = min(f1, f2);
	dp[ind][v] = ret;
	return ret;
}

int main() {
    //__FastIO;   //Be aware to use it!

    int test;
    scanf("%d", &test);

    for (int tc = 1; tc <= test; tc++) {
        scanf("%lf %d", &p, &n);

        for (int i = 0; i < n; i++) {

            scanf("%d %lf", &M[i], &prob[i]);
        }

        int ans = 0;
        int lo = 0, hi = 10000;
		memset(dp, -1, sizeof(dp));
        while (lo <= hi) {
          
            mid = (lo + hi) / 2;
            double ret = fun(0, mid);
            if (ret <= p) {
	//			debug2(mid, ret);
                ans = max(ans, mid);
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        printf("Case %d: %d\n", tc, ans);
    }
    // memset(dp, -1, sizeof(dp));
    //debug3(dp[1][5], dp[30][100], dp[95][10000]);


    return 0;
}
