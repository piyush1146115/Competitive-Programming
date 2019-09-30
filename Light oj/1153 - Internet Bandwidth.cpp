/*
 * FILE: 1153 - Internet Bandwidth.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 08.08.2019 23:24:42 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 08-08-2019	1.0         File Created
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

//#define fill(ar)   		memset(ar, -1, sizeof(ar))
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
#define MAX             1005

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
int n;
vi adj[MAX];
int cost[MAX][MAX];

int bfs(int s, int t, vector<int>& parent)
{
	fill(all(parent), -1);
	parent[s] = -2;
	
	queue<pii > q;
	q.push({s, INF});
	
	while(!q.empty()){
		int cur = q.front().first;
		int flow = q.front().second;
		q.pop();
		
		rep(i, adj[cur].size()){
			int nxt = adj[cur][i];
			if(parent[nxt] == -1 && cost[cur][nxt] > 0){
				parent[nxt] = cur;
				int new_flow = min(flow, cost[cur][nxt]);
				if(nxt == t){
					return new_flow;
				}
				q.push({nxt, new_flow});
			}
		}
	}
	return 0;
}

int max_flow(int s, int t)
{
	int flow = 0;
	vector<int> parent(n+ 3);
	int new_flow;
	
	while((new_flow = bfs(s, t, parent))){
		flow += new_flow;
		int cur = t;
		
		while(cur != s){
			int prev = parent[cur];
			cost[prev][cur] -= new_flow;
			cost[cur][prev] += new_flow;
			cur = prev;
		}
	}
	return flow;
}

int main() {
    //__FastIO;   //Be aware to use it!
    
    int test,u, v, w, s, t, c;
    scanf("%d", &test);
    
	forr(tc, 1, test){
		scanf("%d", &n);
		clr(cost);
		
		
		scanf("%d %d %d", &s, &t, &c);
		
		while(c--){
			scanf("%d %d %d", &u, &v, &w);
			if(cost[u][v] == 0){
				adj[u].pb(v);
			}
			cost[u][v] += w;
			if(cost[v][u] == 0){
				adj[v].pb(u);
			}
			cost[v][u] += w;
		}
		int ans = max_flow(s, t);
		
		printf("Case %d: %d\n",tc, ans);
		forr(i, 0, n){
			adj[i].clear();
		}
	}
    
    return 0;
}
