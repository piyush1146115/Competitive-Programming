/*
 * FILE: ABC 120 D - Decayed Bridges.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 14.08.2019 23:26:32 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 14-08-2019	1.0         File Created
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

int Set(int N,int pos){return N=N | (1<<pos);}
int Reset(int N,int pos){return N= N & ~(1<<pos);}
bool Check(int N,int pos){return (bool)(N & (1<<pos));}


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


struct UnionFind {
    vector < int > par;
    
    UnionFind ( ll n): par (n, -1 ) {}
     void init ( int n) {par.assign (n, -1 );}
    
    int root ( int x) {
         if (par [x] < 0 ) return x;
         else  return par [x] = root (par [x]);
    }
    
    bool issame ( int x, int y) {
         return root (x) == root (y);
    }
    
    bool merge ( int x, int y) {
        x = root (x); y = root (y);
        if (x == y) return  false ;
         if (par [x]> par [y]) swap (x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return  true ;
    }
    
    int size ( int x) {
         return -par [root (x)];
    }
};

int main () {
     long  long N, M; cin >> N >> M;
    vector < int > A (M), B (M);
     for ( int i = 0 ; i <M; ++ i) {
        cin >> A [i] >> B [i], --A [i], --B [i];
    }
        
    UnionFind uf (N);
    long  long cur = N * (N- 1 ) / 2 ;
    vector < long  long > res;
     for ( int i = 0 ; i <M; ++ i){
        res.push_back (cur);
            
        int a = A [M- 1 -i], b = B [M- 1 -i];
         if (uf.issame (a, b)) continue ;
        
        long  long sa = uf.size (a), sb = uf.size (b);
        cur-= sa * sb;
        uf.merge (a, b);
    }
        
    reverse (res.begin (), res.end ());
    for ( int i = 0 ; i <(int)res.size (); ++ i) cout << res [i] << endl;
}
