/*
 * FILE: 1270 - Tiles (II).cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 28.05.2019 13:08:28 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 28-05-2019   1.0         File Created
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

int Set(int N, int pos) {
    return N = N | (1 << pos);
}
int Reset(int N, int pos) {
    return N = N & ~(1 << pos);
}
bool Check(int N, int pos) {
    return (bool)(N & (1 << pos));
}


ll BM( ll a, ll b, ll m ) {
    if ( b == 0 ) return 1 ;
    ll x = BM(a, b / 2, m);
    x = (( x % m) * (x % m)) % m;

    if ( b % 2 ) x = (( x % m) * (a % m)) % m ;
    return x ;
}

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/

int grid[MAX][MAX];
int n, m;


bool chk(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0)
        return true;

    return false;
}

int fun() {

    int cnt = 0;
    int flag = 0;
    rep(i, n) {
        rep(j, m) {
            if (grid[i][j] >= 1) {
                cnt++;
            }
        }
    }

    if (cnt == (m * n)) {
        return 1;
    }

    int ret = 0;

    rep(i, n) {
        rep(j, m) {
            if (grid[i][j] == 0) {

                if (chk(i + 1, j)) {
                    flag = 1;
                    grid[i][j] = grid[i + 1][j] = 1;
                    ret += fun();
                    grid[i][j] = grid[i + 1][j] = 0;
                }
                if (chk(i, j + 1)) {
                    flag = 1;
                    grid[i][j] = grid[i][j + 1] = 1;
                    ret += fun();
                    grid[i][j] = grid[i][j + 1] = 0;
                }
                if (chk(i + 1, j) && chk(i + 1, j + 1)) {
                    flag = 1;
                    grid[i][j] = grid[i + 1][j + 1] = grid[i + 1][j] = 1;
                    ret += fun();
                    grid[i][j] = grid[i + 1][j + 1] = grid[i + 1][j] = 0;
                }
                if (chk(i, j + 1) && chk(i + 1, j)) {
                    flag = 1;
                    grid[i][j] = grid[i][j + 1] = grid[i + 1][j] = 1;
                    ret += fun();
                    grid[i][j] = grid[i][j + 1] = grid[i + 1][j] = 0;
                }
                if (chk(i , j + 1) && chk(i + 1, j + 1)) {
                    flag = 1;
                    grid[i][j] = grid[i ][j + 1] = grid[i + 1][j + 1] = 1;
                    ret += fun();
                    grid[i][j] = grid[i ][j + 1] = grid[i + 1][j + 1] = 0;
                }
                if (chk(i + 1, j) && chk(i + 1, j - 1)) {
                    flag = 1;
                    grid[i][j] = grid[i + 1][j] = grid[i + 1][j - 1] = 1;
                    ret += fun();
                    grid[i][j] = grid[i + 1][j] = grid[i + 1][j - 1] = 0;
                }
                if (flag)
                    return ret;

            }
        }
    }

    return ret;

}

int main() {
    //__FastIO;   //Be aware to use it!

    int test;
    scanf("%d", &test);
    string s[MAX];

    forr(tc, 1, test) {
        clr(grid);

        scanf("%d %d", &n, &m);

        rep(i, n) {
            cin >> s[i];
        }

        rep(i, n) {
            rep(j, m) {
                if (s[i][j] == '#') {
                    grid[i][j] = 2;
                }
            }
        }

        int ans = fun();

        printf("Case %d: %d\n", tc, ans);
    }
    return 0;
}
