/*
 * FILE: B.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 18.09.2019 22:01:42 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 18-09-2019   1.0         File Created
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
typedef vector< vi >        vvi;
typedef vector<long long>   vll;


#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define tr(i,c)         for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define all(ar)         ar.begin(), ar.end()

#define present(c,x) ((c).find(x) != (c).end()) // for map/set
#define cpresent(c,x) (find(all(c),x) != (c).end()) // for vectors


#define fill(ar)        memset(ar, -1, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"

#define pb              push_back
#define MP              make_pair
#define sz(a)           int((a).size())


#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define gama 0.57721566490
#define PI              acos(-1.0)
#define INF             0x7fffffffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             1005

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

ll ara[MAX][MAX], calc[MAX][MAX], ans[MAX];
ll n;


ll solve(ll m) {
    ans[1] = m;

    forr(j, 2, n) {
        if (ara[1][j] % m == 0) {
            ans[j] = ara[1][j] / m;
        } else {
            return 0;
        }
    }


    forr(i, 1, n) {
        forr(j, 1, n) {
            if (i == j) {
                calc[i][j] = 0;
            } else {
                calc[i][j] = ans[i] * ans[j];
            }
        }
    }


    int flag = 1;

    forr(i, 1, n) {
        forr(j, 1, n) {
            if (ara[i][j] != calc[i][j]) {
                flag = 0;
                break;
            }
        }
        if (flag == 0) {
            break;
        }
    }

    if (flag) {
        forr(i, 1, n) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return flag;
}

int main() {
    __FastIO;   //Be aware to use it!

    //cout << __gcd(99990000 ,99970002);

    cin >> n;

    forr(i, 1, n) {
        forr(j, 1, n) {
            cin >> ara[i][j];
        }
    }

    ll mn = 0;

    forr(i, 2, n) {
        mn = __gcd(ara[1][i], mn);
    }

    ll sq  = (ll)sqrt(mn) + 2;
    vll v;

    forr(i, 1LL, sq) {
       
        if (mn % i == 0) {
            v.pb(i);
            v.pb(mn/i);
        }
    }


    unique(all(v));


    rep(i, sz(v)) {
       // debug1(v[i]);
        if (solve(v[i])) {
            break;
        }
    }





    /*
    5
    0 418770 480249 81081 710127
    418770 0 253330 42770 374590
    480249 253330 0 49049 429583
    81081 42770 49049 0 72527
    710127 374590 429583 72527 0
    */

    return 0;
}
