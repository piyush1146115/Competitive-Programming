/*
 * FILE: C.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 29.04.2018 16:06:45 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 29-04-2018   1.0         File Created
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
#define INF             10000000000000000
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

ll n, q, m, Cl, Cv, v;
vll star, elev;

int main() {
    __FastIO;   //Be aware to use it!

    cin >> n >> m >> Cl >> Cv >> v;

    rep(i, Cl) {
        ll k;
        cin >> k;
        star.pb(k);
    }

    rep(i, Cv) {
        ll k;
        cin >> k;
        elev.pb(k);
    }
    
    //debug2(elev[0], elev.size());

    cin >> q;

    rep(i, q) {
        ll x1, x2, y1, y2;
        ll ans = INF, res, res2 = 0;
        cin >> x1 >> x2 >> y1 >> y2;
			res = abs(x1 - y1);
        int ind = (int)(lower_bound(star.begin(), star.end(), x2) - star.begin())-1;
        
        if (ind >= 0 && ind  < (int)star.size()) {
            res2 = (abs(star[ind] - x2) + (abs(star[ind] - y2)));
            res2 += res;
            ans = min(ans, res);
        }
        
        debug3(ind, res2, res);
        debug1(star.size());
        
         ind = (int)(lower_bound(star.begin(), star.end(), y2) - star.begin());
        
        if (ind >= 0 && ind  < (int)star.size()) {
            res2 = (abs(star[ind] - x2) + (abs(star[ind] - y2)));
            res2 += res;
            ans = min(ans, res);
        }
        
       debug3(ind, res2, res);
        
        ind = (int)(lower_bound(elev.begin(), elev.end(), y2) - elev.begin());
        ll  temp = abs(x1 - y1);
        res = (temp / v);
        if (temp % v != 0)
            res++;

        if (ind >= 0 && ind  < (int)elev.size()) {
           res2 = (abs(elev[ind] - x2) + (abs(elev[ind] - y2)));
            res2 += res;
            ans = min(ans, res2);
        }
        
        debug3(ind, temp, res);
        
        ind = (int)(lower_bound(elev.begin(), elev.end(), x2) - elev.begin());
       
        if (ind >= 0 && ind  < (int)elev.size()) {
            res2 = (abs(elev[ind] - x2) + (abs(elev[ind] - y2)));
            res2 += res;
            ans = min(ans, res2);
        }
        
        debug3(ind, res2, res);
        
        cout << ans << endl;

    }

    return 0;
}
