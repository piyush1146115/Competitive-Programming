/*
 * FILE: D.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 09.01.2019 22:17:41 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 09-01-2019   1.0         File Created
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
#define MAX             300005

ll BM( ll a, ll b, ll m ) {
    if ( b == 0 ) return 1 ;
    ll x = BM(a, b / 2, m);
    x = (( x % m) * (x % m)) % m;

    if ( b % 2 ) x = (( x % m) * (a % m)) % m ;
    return x ;
}

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/
ll cnt[5], ara[MAX];
int main() {
    __FastIO;   //Be aware to use it!
    ll n;
    string s;
    cin >> n >>  s;

    rep(i, s.size()) {
        ara[i] = s[i] - '0';
        cnt[ara[i]]++;
    }

    ll req = n / 3;
    ll baki;


    baki = req - cnt[0];
    if (baki > 0) {
        rep(i, n) {
            if (ara[i] == 2 && cnt[2] > req) {
                ara[i] = 0;
                baki--;
                cnt[2]--;
            } else if (ara[i] == 1 && cnt[1] > req) {
                ara[i] = 0;
                baki--;
                cnt[1]--;
            }
            if (baki == 0) {
                break;
            }
        }
    }
    baki = req - cnt[2];

    if (baki > 0) {
        for (ll  i = n - 1; i >= 0; i--) {
            if (ara[i] == 1 && cnt[1] > req) {
                ara[i] = 2;
                baki--;
                cnt[1]--;
            } else if (ara[i] == 0 && cnt[0] > req) {
                ara[i] = 2;
                baki--;
                cnt[0]--;
            }
            if (baki == 0) {
                break;
            }
        }
    }

    baki = req - cnt[1];
    if (baki > 0) {
        rep(i, n) {
            if (ara[i] == 2 && cnt[2] > req) {
                ara[i] = 1;
                baki--;
                cnt[2]--;
            }
            if (baki == 0) {
                break;
            }
        }
    }


    if (baki > 0) {
        for (ll  i = n - 1; i >= 0; i--) {
            if (ara[i] == 0 && cnt[0] > req) {
                ara[i] = 1;
                baki--;
                cnt[0]--;
            }
            if (baki == 0) {
                break;
            }
        }
    }



    rep(i, n) {
        cout << ara[i];
    }
    cout << endl;
    return 0;
}
