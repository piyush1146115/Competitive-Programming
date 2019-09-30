/*
 * FILE: C - A Perfect Murder.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 29.03.2019 00:42:16 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 29-03-2019   1.0         File Created
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
#define MAX             1005

ll BM( ll a, ll b, ll m ) {
    if ( b == 0 ) return 1 ;
    ll x = BM(a, b / 2, m);
    x = (( x % m) * (x % m)) % m;

    if ( b % 2 ) x = (( x % m) * (a % m)) % m ;
    return x ;
}

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/
vi gr[MAX];
int DP[MAX][5], vis[MAX];

int fun(int pos, int state, int from) {
    int v, ret1, ret2;
	//debug2(pos,state);
	//getchar();
    vis[pos] = 1;
    ret1 = ret2 = 0;
    
    
    if(DP[pos][state] != -1){
		return DP[pos][state];
	}
	
	if (state == 0) {
        ret1 = 1;
    }
    rep(i, gr[pos].size()) {
        v = gr[pos][i];
        if (v != from) {
            if (state == 0) {
                ret1 += fun(v, 1, pos);
                ret2 += fun(v, 0,pos);
            } else {
                ret2 += fun(v, 0,pos);
            }
        }
    }
    return  DP[pos][state] = max(ret1, ret2);

}

int main() {
    // __FastIO;   //Be aware to use it!

    int test;

    scanf("%d", &test);

    forr(tc, 1, test) {
        int n, m, u, v;
        scanf("%d %d", &n, &m);

        rep(i, m) {
            scanf("%d %d", &u, &v);
            gr[u].pb(v);
            gr[v].pb(u);
        }

        clr(vis);
        fill(DP);
        int ret = 0;

        forr(i, 1, n) {
            if (vis[i] == 0) {
               // ret +=  max(fun(i, 0, -1), 1 + fun(i, 1, -1));
				ret += fun(i, 0, -1);
            }
        }
        printf("Case %d: %d\n", tc, ret);
        rep(i, n + 1) {
            gr[i].clear();
        }
    }
    return 0;
}

/*
10 9
8 7
9 7
7 1
6 10
1 6
1 3
1 2
2 4
4 5
*/

