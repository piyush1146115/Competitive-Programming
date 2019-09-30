/*
 * FILE: B  Weakened Common Divisor.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 27.09.2018 21:23:09 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 27-09-2018   1.0         File Created
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
typedef pair<long long, long long >      pii;
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
#define MAX             150005

ll BM( ll a, ll b, ll m ) {
    if ( b == 0 ) return 1 ;
    ll x = BM(a, b / 2, m);
    x = (( x % m) * (x % m)) % m;

    if ( b % 2 ) x = (( x % m) * (a % m)) % m ;
    return x ;
}

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/

pii ara[MAX];
vll prime;
bool chk[MAX];
int main() {
    __FastIO;   //Be aware to use it!
    int n;
    cin >> n;

    rep(i, n) {
        cin >> ara[i].first >> ara[i].second;
    }

    for (ll i = 2; i <= 100000; i++) {
        if (chk[i] == 0) {
            prime.pb(i);
            for (ll j = i * i ; j <= 100000; j += i) {
                chk[j] = 1;
            }
        }
    }

    set<ll> s;
    for (int i = 0; prime[i]*prime[i] <= ara[0].first; i++) {
        if (ara[0].first % prime[i] == 0) {
            while (ara[0].first % prime[i] == 0) {
                s.insert(prime[i]);
                ara[0].first /= prime[i];
            }
        }
    }
    if (ara[0].first > 1) {
        s.insert(ara[0].first);
    }

    for (int i = 0; prime[i]*prime[i] <= ara[0].second; i++) {
        if (ara[0].second % prime[i] == 0) {
            while (ara[0].second % prime[i] == 0) {
                s.insert(prime[i]);
                ara[0].second /= prime[i];
            }
        }
    }

    if (ara[0].second > 1) {
        s.insert(ara[0].second);
    }
    /*
        forit(it, s) {
            cout << *it << endl;
        }
    */
    set<ll> temp;
    ll ans = ara[0].first;

    for (ll j = 1; j < n; j++) {
        temp.clear();
        ans = -1;
        forit(i, s) {
            if (ara[j].first % (*i) == 0) {
                temp.insert(*i);
                ans = *i;
                //    debug2(j, ara[j].first);
                //      cout << *i << endl;
            }
            if (ara[j].second % (*i) == 0) {
                temp.insert(*i);
                ans = *i;
                //        debug2(j, ara[j].second);
                //          cout << *i << endl;
            }
        }


        //    debug1(ans);
        s.clear();
        s = temp;
    }

    cout << ans << endl;

    return 0;
}
