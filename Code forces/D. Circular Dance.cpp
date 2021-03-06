/*
 * FILE: D. Circular Dance.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 26.01.2019 01:04:45 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 26-01-2019   1.0         File Created
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
int n;
vi v[2 * MAX];
int taken[MAX * 2];

int main() {
    __FastIO;   //Be aware to use it!

    cin >> n;
    int p1, p2;

    rep(i, n) {
        cin >> p1 >> p2;
        v[i + 1].pb(p1);
        v[i + 1].pb(p2);
    }

    vi ans;
    int pos = 1;
    while ((int)ans.size() < n) {
        p1 = v[pos][0];
        p2 = v[pos][1];
        if (v[p1][0] == p2 || v[p1][1] == p2) {
            if (taken[p1] == 0) {
                ans.pb(p1);
                taken[p1] = 1;
            }
            if (taken[p2] == 0) {
                ans.pb(p2);
                taken[p2] = 1;
            }
            pos = p1;
        } else {
            if (taken[p2] == 0) {
                ans.pb(p2);
                taken[p2] = 1;
            }
            if (taken[p1] == 0) {
                ans.pb(p1);
                taken[p1] = 1;
            }
            pos = p2;
        }
    }

    /*ans.pb(v[1][0]);
    p1 = v[1][0];
    p2 = v[1][1];
    taken[p1] = 1;

    int cur;
    while ((v[p1][0] == p2 || v[p1][1] == p2) ) {
        cur = p1;
        if (taken[p2] == 0) {
            ans.pb(p2);
            taken[p2] = 1;
        }
        if (v[p1][0] == p2) {
            p1 = p2;
            p2 = v[cur][1];
        } else {
            // p1 = p2;
            p1 = p2;
            p2 = v[p1][0];
        }
        if (taken[v[cur][0]] == 0) {
            ans.pb(v[cur][0]);
            taken[v[cur][0]] = 1;
        }
        if (taken[v[cur][1]] == 0) {
            ans.pb(v[cur][1]);
            taken[v[cur][1]] = 1;
        }
        if ((int)ans.size() == n) {
            break;
        }
    }

    if ((int)ans.size() < n) {
        ans.clear();
        clr(taken);
        ans.pb(v[1][1]);
        p1 = v[1][1];
        p2 = v[1][0];
        taken[p1] = 1;


        while ((v[p1][0] == p2 || v[p1][1] == p2) ) {
            cur = p1;
            if (taken[p2] == 0) {
                ans.pb(p2);
                taken[p2] = 1;
            }
            if (v[p1][0] == p2) {
                p1 = p2;
                p2 = v[cur][1];
            } else {
                p1 = p2;
                p2 = v[p1][0];
            }
            if (taken[v[cur][0]] == 0) {
                ans.pb(v[cur][0]);
                taken[v[cur][0]] = 1;
            }
            if (taken[v[cur][1]] == 0) {
                ans.pb(v[cur][1]);
                taken[v[cur][1]] = 1;
            }
            if ((int)ans.size() == n) {
                break;
            }
        }
    }
    temp.pb(v[1][0]);
    temp.pb(v[1][1]);


    while(temp.size() > 0){
        if(taken[temp[0]] == 0){
            ans.pb(temp[0]);
            taken[temp[0]] = 1;
            p1 = v[temp[0]][0];
            temp.pb(p1);
            p2 = v[temp[0]][1];
            temp.pb(p2);
        }
        temp.erase(temp.begin());
    }*/

    rep(i, ans.size()) {
        cout << ans[i] << " ";
    }
    return 0;
}
