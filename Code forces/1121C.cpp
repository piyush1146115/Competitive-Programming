/*
 * FILE: 1121C.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 18.04.2019 16:23:10 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 18-04-2019   1.0         File Created
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

int ara[MAX], n, k;


struct st {
    int start, val, id;
    st(int _start, int _val, int _id) {
        start = _start;
        val = _val;
        id = _id;
    }
};

int flag[MAX];
int main() {
    __FastIO;   //Be aware to use it!

    cin >> n >> k;

    rep(i, n) {
        cin >> ara[i];
    }
    vector<st> v;
    int t = 0, m = 0, ans = 0, ind = 1;

    v.pb({t, ara[0], 0});
    int per = (int)((((double)m / (double)n) * 100.0) + 0.5);

    while ((int)v.size() >= 1) {
        if((int)v.size() < k && ind < n ){
            
            v.pb({t, ara[ind], ind});
            ind++;
            continue;
        }
        per = (int)((((double)m/(double)n) * 100.0) + 0.5);
        rep(j, v.size()) {
            debug3(j, v[j].start, per);
            debug3(t, m, ans);
            cout << endl;

            if ((t - v[j].start) == v[j].val) {
                v.erase(v.begin() + j);
                m++;
                //debug1(v.size());
                per = (int)(((((double)m*100.0)/(double)n)) + 0.5);
            }
        }
        rep(j, v.size()) {
            if (per > 0) {
                if ((t - v[j].start + 1) == per || (t - v[j].start) == per) {
                    if (flag[v[j].id] == 0) {
                        ans++;
                        flag[v[j].id] = 1;
                    }
                }
            }
        }
    t++;
}


cout << ans << endl;
return 0;
}
