/*
 * FILE: D.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 19.06.2019 22:12:43 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 19-06-2019   1.0         File Created
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
#define MAX             200005

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

struct st {
    ll num, indx;
} ara[MAX];

bool comp(st a, st b) {
    return a.num < b.num;
}

int main() {
    __FastIO;   //Be aware to use it!

    ll n;

    cin >> n;

    rep(i, n) {
        cin >> ara[i].num;
        ara[i].indx = i + 1;
    }

    sort(ara, ara + n, comp);



    set<ll> S;
    map<ll, ll> mp;
	
    rep(i, n) {

        if (i > 0 && i < (n - 1)) {
            mp[ara[i + 1].num - ara[i].num]++;
           // debug3(i, mp[ara[i + 1].num - ara[i].num], ara[i + 1].num - ara[i].num);
            S.insert(ara[i + 1].num - ara[i].num);
            S.insert(ara[i].num - ara[i - 1].num);
            mp[ara[i].num - ara[i - 1].num]++;
           // debug2(mp[ara[i].num - ara[i-1].num], ara[i].num - ara[i- 1].num);
              // debug3(ara[i].num, ara[i + 1].num, ara[i -1].num);
        }
        else if ( i == 0) {
            S.insert(ara[i + 1].num - ara[i].num);
            mp[ara[i + 1].num - ara[i].num]++;
        }
        else if (i == n - 1) {
            S.insert(ara[i].num - ara[i - 1].num);
            mp[ara[i].num - ara[i - 1].num]++;
        }
    }


    if (S.size() == 1) {
        cout << 1 << endl;
        exit(0);
    } else if (S.size() > 3) {
        cout << -1 << endl;
		exit(0);
    } else {
        rep(i, n) {
            if (i > 0 && i < (n - 1)) {
                if (mp[ara[i + 1].num - ara[i].num] < n) {
                    cout << ara[i].indx;
                    exit(0);
                }
                if (mp[ara[i].num - ara[i - 1].num] < n) {
                    cout << ara[i].indx;
                    exit(0);
                }
                //debug3(i, mp[ara[i + 1].num - ara[i].num], mp[ara[i].num - ara[i - 1].num]);
                //debug3(ara[i].num, ara[i + 1].num, ara[i -1].num);
            }
            if ( i == 0) {
                if (mp[ara[i + 1].num - ara[i].num] == 1) {
                    cout << ara[i].indx;
                    exit(0);
                }
            }
            if (i == n - 1) {
                if (mp[ara[i].num - ara[i - 1].num] == 1) {
                    cout << ara[i].indx;
                    exit(0);
                }
            }
        }
    }

cout << -1 << endl;

    return 0;
}
