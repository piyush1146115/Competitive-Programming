/*
 * FILE: C. Yuhao and a Parenthesis.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 04.01.2019 21:30:20 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 04-01-2019   1.0         File Created
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
vll ara;
map<ll, ll>mp;

int main() {
    __FastIO;   //Be aware to use it!
    ll n;
    cin >> n;
    string s;
    ll cnt, right;
    ll mn = (ll)INF;
    
    rep(i, n) {
        right = 0ll;
        cnt = 0;
        mn = (ll)INF;
        cin >> s;
        int sz = (int)s.size();

        rep(j, sz) {
            if (s[j] == '(') {
                cnt++;
                right++;
            } else {
                right--;
                cnt--;
            }
            right = max(0ll, right);
            mn = min(cnt, mn);
        }
       // debug3(i, right, mn);

        if (right > 0 && mn < 0) {
            continue;
        }

        ara.pb(cnt);
        mp[cnt]++;
        // debug2(i, cnt);
    }

    // sort(ara, ara + n);
    cnt = 0;
    n = ara.size();
    //debug1(n);
    rep(i, n) {
		//debug2(i, ara[i]);
        if (ara[i] > 0) {
            //int ret = bin(ara[i] * (-1), 0ll, n - 1);
            //cnt += ret;
            //debug3(ara[i], cnt, ret);
            if (mp[-ara[i]] > 0) {
                mp[-ara[i]]--;
                cnt++;
            }
        } else if (ara[i] == 0) {
            if (mp[0] > 1) {
                cnt++;
                mp[0] -= 2;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
