/*
 * FILE: Adding on Segments querying for maximum.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 25.10.2018 11:40:29 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 25-10-2018	1.0         File Created
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
int  ara[MAX], tree[MAX * 4], lazy[MAX * 4];

void push(int v)
{
	tree[v * 2] += lazy[v];
	tree[v * 2 + 1] += lazy[v];
	lazy[v * 2 ] += lazy[v];
	lazy[v * 2 + 1] += lazy[v];
	
	lazy[v] = 0; 
}

/* 
 * Modification query is to add a number to all elements in a range .
 * As a second query we will consier finding the maximum in a range
 */
 
 
void build(int v, int tl, int tr)
{
	if(tl == tr){
		tree[v] = ara[tl];
	}
	else{
		int tm = (tl + tr)/2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		tree[v] = max(tree[v* 2], tree[v  * 2 + 1]);
	}
}
void update(int v, int tl, int tr, int l, int r, int addend){
	if(l > r){
		return;
	}
	if(l == tl && r == tr){
		tree[v] += addend;
		lazy[v] += addend;
	}
	else{
		push(v);
		int tm = (tl + tr)/2;
		update(v * 2, tl, tm, l, min(r, tm), addend);
		update(v*2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
		tree[v] = max(tree[v*2], tree[v * 2 + 1]);
	}
}

int query(int v, int tl, int tr, int l, int r)
{
	if(l > r)
		return -INF;
	if(tl == tr)
		return tree[v];
	push(v);
	int tm = (tl + tr)/2;
	return max(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr,max(l, tm + 1), r));
}

int main() {
    __FastIO;   //Be aware to use it!
    return 0;
}
