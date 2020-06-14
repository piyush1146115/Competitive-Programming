/*
 * FILE: Finding maximum number and its frequency.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 24.10.2018 15:19:53 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 24-10-2018   1.0         File Created
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

pii tree[MAX * 4];
int ara[MAX];

pii combine(pii a, pii b) {
    if (a.first > b.first)
        return a;
    if (b.first > a.first)
        return b;

    return MP(a.first, a.second + b.second); 
}

void build(int v, int l, int r) {
    if (l == r) {
        tree[v] = MP(ara[l], 1);
    } else {
        int m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}

void update(int v, int l, int r, int pos, int new_val) {
	if(l == r){
		tree[v] = MP(new_val, 1);
	}
	else{
		int m = (l + r)/2;
		if(pos <= m)
			update(v * 2, l, m, pos, new_val);
		else{
			update(v*2 + 1, m + 1, r, pos, new_val);
		}
		tree[v] = combine(tree[v*2], tree[v*2 + 1]);
	}
}

pii query(int v, int l, int r, int i, int j)
{
	if(i > j){
		return MP(-INF, 0);
	}
	if(l == i && r == j){
		return tree[v];
	}
	int m = (l + r)/2;
	return combine(query(v*2,l, m, i, min(j, m)), query(v*2 + 1, m + 1, r, max(i, m + 1), j));
	
}
int main() {
    //__FastIO;   //Be aware to use it!
    return 0;
}
