/*
 * FILE: 1034 - Hit the Light Switches.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 27.02.2019 13:19:18 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 27-02-2019	1.0         File Created
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
#define MAX             10005

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
vi gr[MAX];
stack<int> st;
bool vis[MAX];

void dfs(int u)
{
	vis[u] = 1;
	
	rep(i, gr[u].size()){
		int v = gr[u][i];
		if(vis[v] == 0){
			dfs(v);
		}
	}
	st.push(u);
}

void dfs2(int u)
{
	vis[u] = 1;
	
	rep(i, gr[u].size()){
		int v = gr[u][i];
		if(vis[v] == 0){
		//	debug2(u, v);
			dfs2(v);
		}
	}
}

int main() {
    //__FastIO;   //Be aware to use it!
    
    int test;
    scanf("%d", &test);
    
    forr(tc, 1, test){
		
		
		int n, m;
		scanf("%d %d", &n, &m);
		int u, v;
		
		forr(i, 1, n){
			gr[i].clear();
		}
		
		rep(i, m){
			scanf("%d %d", &u, &v);
			gr[u].pb(v);
			//gr[v].pb(u);
		}
		
		forr(i, 1, n){
			if(vis[i] == 0){
				dfs(i);
			}
		}
		
		clr(vis);
		
		int cnt = 0;
		
		while(!st.empty()){
			n = st.top();
			st.pop();
			//debug2(n, vis[n]);
			if(vis[n] == 0){
				cnt++;
				dfs2(n);
			}
		}
		clr(vis);
		
		printf("Case %d: %d\n",tc, cnt);
		
	}
    return 0;
}
