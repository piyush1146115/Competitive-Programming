/*
 * FILE: Finding the index of kth zero.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 24.10.2018 16:19:19 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 24-10-2018	1.0         File Created
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

int tree[MAX*4], ara[MAX];

void build(int v, int l, int r)
{
	if(l == r){
		if(ara[l] == 0){
			tree[v] = 1;
		}
		else{
			tree[v] = 0;
		}
	}
	else{
	int m = (l + r)/2;
	
	build(v * 2, l, m);
	build(v * 2 + 1, m + 1, r);
	
	tree[v] = tree[v * 2] + tree[v * 2 + 1];
}
}

void update(int v, int l, int r, int pos, int new_val){
	if(l == r){
		if(new_val == 0){
			tree[v] = 1;
		}
		else{
			tree[v] = 0;
		}
	}
	else{
		int m = (l + r)/2;
		if(pos <= m)
			update(v, l , m, pos, new_val);
		else
			update(v, m + 1, r, pos, new_val);
	}
	tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

int find_kth(int v, int l, int r, int k){
	if(k > tree[v])
		return -1;//imposssible to find k zeroes
	
	if(l == r)
		return l;
	int m = (l + r)/2;
	
	if(tree[v * 2] >= k)
		return find_kth(v *2, l, m, k);
	else
		return find_kth(v*2 + 1, m + 1, r, k-tree[v*2]);	
}

int main() {
    __FastIO;   //Be aware to use it!
    return 0;
}
