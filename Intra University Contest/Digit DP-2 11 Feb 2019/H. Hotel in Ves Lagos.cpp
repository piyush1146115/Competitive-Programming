/*
 * FILE: H. Hotel in Ves Lagos.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 14.02.2019 09:20:34 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 14-02-2019   1.0         File Created
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
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             100005

ll BM( ll a, ll b, ll m ) {
    if ( b == 0 ) return 1 ;
    ll x = BM(a, b / 2, m);
    x = (( x % m) * (x % m)) % m;

    if ( b % 2 ) x = (( x % m) * (a % m)) % m ;
    return x ;
}

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/

vi ans;
ll dp[21][11][4];

ll fun(int pos, int pres, int isStart) {
    if (pos == 19) {
        if (isStart) {
            return 1;
        } else {
            return 0;
        }
    }
    
    if(dp[pos][pres][isStart] != -1){
		return dp[pos][pres][isStart];
	}
    ll ret = 0;
   
	for(int i = 0; i < 10; i++){
		if(pres == 1 && i == 3){
			continue;
		}
		ret += fun(pos + 1, i, isStart|(i > 0));
	}
	dp[pos][pres][isStart] = ret;
    return ret;
}

void path(int pos, int pres, int isStart, ll n) {
    if (pos == 19) {
        return;
    }


    ll ret = 0, prev = 0;

    	for(int i = 0; i < 10; i++){
		if(pres == 1 && i == 3){
			continue;
		}
		ret += fun(pos + 1, i, isStart|(i > 0));
		if(n <= ret){
			ans.pb(i);
			path(pos + 1, i, isStart|(i > 0),n - prev);
			break;
		}
		prev = ret;
	}
    
}

int main() {
    //__FastIO;   //Be aware to use it!
	freopen("hotel.in","r",stdin);
	freopen("hotel.out","w",stdout);
    ll n;
    int test;
    fill(dp);
    
    scanf("%d", &test);

    while (test--) {
        scanf("%lld", &n);
		
        path(0, 0, 0, n);

        while (ans[0] == 0) {
            ans.erase(ans.begin());
        }

        rep(i, ans.size()) {
            printf("%d", ans[i]);
        }

        ans.clear();
        printf("\n");
    }
    
    return 0;
}
