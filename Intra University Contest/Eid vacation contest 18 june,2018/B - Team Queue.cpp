/*
 * FILE: B - Team Queue.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 18.06.2018 19:14:10 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 18-06-2018   1.0         File Created
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
#define MAX             1000005

ll BM( ll a, ll b, ll m ) {
    if ( b == 0 ) return 1 ;
    ll x = BM(a, b / 2, m);
    x = (( x % m) * (x % m)) % m;

    if ( b % 2 ) x = (( x % m) * (a % m)) % m ;
    return x ;
}

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/

int team[MAX], indx[1005], tmloc[1005], pos[1005];
vi v[1005];
int main() {
    // __FastIO;   //Be aware to use it!

    int tc = 0;
    int teams;

    while (scanf("%d", &teams) == 1 && teams != 0) {

        forr(i, 1, teams) {
            int n;
            scanf("%d", &n);

            forr(j, 1,  n) {
                int k;
                scanf("%d", &k);
                team[k] = i;
            }
        }

        fill(tmloc);

        clr(indx);


        string s;
        printf("Scenario #%d\n", ++tc);
        int ind = 0, curr = 1, cnt = 0;

        while (cin >> s) {
            if (s == "STOP")
                break;

            if (s == "ENQUEUE") {
                int k;
                scanf("%d", &k);
                int tm = team[k];
                if (tmloc[tm] == -1) {
                    ++ind;
                    int md = ind % 1003;
                    tmloc[tm] = md ;
                    pos[md] = tm;
                }
                indx[tmloc[tm]]++;
                v[tmloc[tm]].pb(k);
            } else {
                if (indx[curr % 1003] <= 0) {
                    tmloc[pos[curr % 1003 ]] = -1;
                    curr++;
                    cnt = 0;
                }
                printf("%d\n", v[curr % 1003][cnt]);
                cnt++;
                indx[curr % 1003]--;
            }
        }
        printf("\n");

        for (int i = 0; i <= 1003; i++) {
            v[i].clear();
        }
    }

    return 0;
}
