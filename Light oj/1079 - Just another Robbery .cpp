/*
 * FILE: 1079 - Just another Robbery .cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 24.09.2018 09:27:27 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 24-09-2018   1.0         File Created
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
typedef pair<int, float>   piD;
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
#define MAX             105

ll BM( ll a, ll b, ll m ) {
    if ( b == 0 ) return 1 ;
    ll x = BM(a, b / 2, m);
    x = (( x % m) * (x % m)) % m;

    if ( b % 2 ) x = (( x % m) * (a % m)) % m ;
    return x ;
}

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/

int M[MAX];
float prob[MAX];
int n;
float p_max;
map<pair<int, float> , int> mp;

int fun(int ind, float p) {
    if (ind == n) {
        return 0;
    }

    pair<int, float> x = MP(ind, p);
    if (mp.find(x) != mp.end()) {
        return mp[x];
    }

    int p1 = 0, p2 = 0;
    float temp = p + ((1.0 -  p) * prob[ind]);
    //debug3(ind, p, temp);
    //getchar();

    if (temp <= p_max) {
        p1 = M[ind] + fun(ind + 1, temp);
    }

    p2 = fun(ind + 1, p);
    mp[x] = max(p1, p2);

    return max(p1, p2);
}

int main() {
    //__FastIO;   //Be aware to use it!

    int test;

    scanf("%d", &test);

    for (int tc = 1; tc <= test; tc++) {
        scanf("%f %d", &p_max, &n);

        for (int i = 0; i < n; i++) {
            scanf("%d %f", &M[i], &prob[i]);
        }
        mp.clear();

        int ans = fun(0, 0.0);

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
