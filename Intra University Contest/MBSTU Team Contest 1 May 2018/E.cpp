/*
 * FILE: E.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 01.05.2018 08:53:37 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 01-05-2018   1.0         File Created
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

int n, m, s, t;
vi gr[MAX];
bool vis[MAX], up[MAX], re[MAX];
int val[MAX];

void dfs(int u, int flag) {
/*
    debug2(u, flag);
    getchar();
*/
    vis[u] = 1;
    if (flag && val[u] > 0) {
        for (int i = 0; i < (int)gr[u].size(); i++) {
            int v = gr[u][i];
            if (up[v] == 0){
                val[v] += val[u];
				re[v] = 1;
			}
        }

            val[u] = 0;
            up[u] = 1;

            for (int i = 0; i < (int)gr[u].size(); i++) {
                int v = gr[u][i];
                //  val[v] += val[u];
                if (vis[v] == 0) {
	//				re[v] = 1;
                    dfs(v, 0);
                }
            }
        
    } else {
        for (int i = 0; i < (int)gr[u].size(); i++) {
            int v = gr[u][i];
            //  val[v] += val[u];
            if (vis[v] == 0 && re[v] == 0) {
			//	re[v] = 1;
                dfs(v, 1);
            }
        }
    }

}
int main() {

    while (scanf("%d %d %d %d", &n, &m, &s, &t) == 4) {
        clr(val);
        rep(i, m) {
            int x, y;
            scanf("%d %d", &x, &y);
            gr[y].pb(x);
            gr[x].pb(y);
        }
        val[s] = 1;

        for (int i = 1; i <= t; i++) {
            clr(vis);
            clr(up);
            clr(re);
            dfs(s, 1);
            /*
            for(int j = 0; j < n; j++){
                debug3(i, j, val[j]);
                debug1(up[j]);
            }*/
        }
        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += val[i];

        printf("%d\n", sum);

        rep(i, n + 1) {
            gr[i].clear();
        }
    }

    return 0;
}
