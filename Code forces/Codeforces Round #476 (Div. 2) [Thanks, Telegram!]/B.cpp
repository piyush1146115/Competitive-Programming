/*
 * FILE: B.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 25.04.2018 23:28:37 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 25-04-2018   1.0         File Created
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
string s[105];

int main() {
    __FastIO;   //Be aware to use it!
    ll n, m;

    cin >> n >> m;

    rep(i, n) {
        cin >> s[i];
    }

    ll ax = 1, ay = 1, mx = 0;

    rep(i, n) {
        rep(j, n) {
            if (s[i][j] != '#') {

                ll cnt = 0, lft = 0, upp = 0, rht = 0, dwn = 0;

                for (ll k = i; k >= 0; k--) {
                    if (s[k][j] != '#') {
                        upp++;
                    } else
                        break;
                }

                for (ll k = i; k < n; k++) {
                    if (s[k][j] != '#') {
                        dwn++;
                    } else
                        break;
                }

                for (ll k = j; k >= 0; k--) {
                    if (s[i][k] != '#') {
                        lft++;
                    } else
                        break;
                }

                for (ll k = j; k < n; k++) {
                    if (s[i][k] != '#') {
                        rht++;
                    }
                     else
                        break;
                }
                /*
                if(i == 15 && j == 6){
					debug3(lft, rht, upp);
					debug1(dwn);
				}*/

                if (upp >= m) {
                    cnt++;
                    cnt += min(m - 1, dwn -1);
                }
                else if (dwn >= m) {
                    cnt++;
                    cnt += min(m -1, upp -1);
                }
                else{
					cnt += max(dwn + upp - m, 0ll);
				}
                if (rht >= m) {
                    cnt++;
                    cnt += min(m -1, lft -1);
                }
                else if (lft >= m) {
                    cnt++;
                    cnt += min(m -1, rht -1);
                }
                else{
					cnt += max(rht + lft - m, 0ll);
				}

                if (cnt > mx) {
                    mx = cnt;
                    ax = i + 1;
                    ay = j + 1;
                }
            }
        }
    }
    
    //debug2(s[15][6], mx);

    cout << ax << " " << ay << endl;
    return 0;
}
