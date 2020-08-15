/*
 * FILE: D.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 06.05.2018 20:59:50 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 06-05-2018   1.0         File Created
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
ull ara[MAX];
map<ull, ll> mp;
vector<ull> ans;


bool fun(ull num, ull n) {
    ans.clear();
    //debug2(num, num % 3);
    ull cnt = 1;
    ans.pb(num);
    mp[num]--;

    rep(i, 2 * n) {

        if (num % 3 == 0) {
            num /= 3;

            if (mp[num] <= 0) {
                num *= 3;
                //    break;
            } else {
          //      debug2(num, cnt);
                mp[num]--;
                cnt++;
                ans.pb(num);
            }
        } 
        
            num *= 2;

            if (mp[num] <= 0) {
                num /= 2;
            } else {
		//		debug2(num, cnt);
                mp[num]--;
                ans.pb(num);
                cnt++;
            }
        
        if (cnt == n)
            break;
    }

    if (cnt == n) {
        return true;
    } else
        return false;
}


bool fun2(ull num, ull n) {
    ans.clear();
    //debug2(num, num % 3);
    ull cnt = 1;
    ans.pb(num);
    mp[num]--;
    rep(i, 2 * n) {


        num *= 2;

        if (mp[num] <= 0) {
            num /= 2;
        } else {
            mp[num]--;
            ans.pb(num);
            cnt++;
        }

        if (num % 3 == 0) {
            num /= 3;

            if (mp[num] <= 0) {
                num *= 3;
                //    break;
            } else {
                mp[num]--;
                cnt++;
                ans.pb(num);
            }
        }

        if (cnt == n)
            break;
    }

    if (cnt == n) {
        return true;
    } else
        return false;
}

int main() {
    __FastIO;   //Be aware to use it!
    ll n;

    cin >> n;

    rep(i, n) {
        cin >> ara[i];
        mp[ara[i] ]++;
    }

    rep(i, n) {

        if (fun(ara[i], n)) {
            //debug2(1, ara[i]);
            rep(j, ans.size()) {
                cout << ans[j] << " ";
            }
            nl;
            break;
        }

        if (fun2(ara[i], n)) {

            rep(j, ans.size()) {
                cout << ans[j] << " ";
            }
            nl;
            break;
        }
        mp.clear();
        rep(k, n) {
            mp[ara[k] ]++;
        }
    }

    return 0;
}
