/*
 * FILE: Suffix Array[nlogn^2].cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 03.10.2018 18:28:55 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 03-10-2018	1.0         File Created
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

#define fill(ar)   		memset(ar, -1, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"

#define pb              push_back
#define MP 				make_pair

#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define gama 0.57721566490
#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             100005

ll BM( ll a , ll b , ll m )
{
    if ( b == 0 ) return 1 ;
    ll x = BM(a,b/2,m);
    x = (( x % m) * (x % m))%m;
    
    if( b % 2 ) x = (( x % m) * (a %m)) % m ;
    return x ;
}

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/
/*
Generates suffix array in O(n (lg n)^2). Finds LCP in O(lg n)
A[] is the target string with N length. base is the lowest character in A[].
S[i] holds the index of ith suffix when sorted lexicographically.
Change base as necessary and MAXLOG = log2(MAXLEN).
*/
 
int N, stp, P[MAXLOG][MAXLEN], S[MAXLEN];
char A[MAXLEN], base = 'a';
struct entry { int nr[2], p; } L[MAXLEN];
 
inline bool cmp(const entry &a, const entry &b) {
    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}
 
void generateSuffix() {
    register int i, cnt;
    for(i=0; i<N; i++) P[0][i] = A[i]-base;
    for(stp = cnt = 1; cnt>>1 < N; stp++, cnt<<=1) {
        for(i=0; i<N; i++) {
            L[i].nr[0] = P[stp-1][i];
            L[i].nr[1] = i+cnt<N ? P[stp-1][i+cnt] : -1;
            L[i].p = i;
        }
        sort(L, L+N, cmp);
        for(i=0; i<N; i++) {
            if(i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1]) P[stp][L[i].p] = P[stp][L[i - 1].p];
            else P[stp][L[i].p] = i;
        }
    }
    for(i=0; i<N; i++) S[P[stp-1][i]] = i;
}
 
int lcp(int x, int y) {
    int k, ret = 0;
    if(x == y) return N - x;
    for(k = stp - 1; k >= 0 && x < N && y < N; k --)
        if(P[k][x] == P[k][y])
            x += 1 << k, y += 1 << k, ret += 1 << k;
    return ret;
}

int main() {
    __FastIO;   //Be aware to use it!
    return 0;
}
