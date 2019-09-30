/*
 * FILE: C.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 24.07.2019 00:40:12 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 24-07-2019	1.0         File Created
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
vi a[MAX], b[MAX * 2], dis[MAX * 2];

int root, mx;

void dfsa(int u, int dep, int prev){
	
	rep(i, a[u].size()){
		int v = a[u][i];
		
		if(v != prev){
			dfsa(v, dep + 1, u);
		} 
	}
	if(dep + 1 > mx){
		root = u;
		mx = dep + 1;
	}
}

vi vec;
int cnt = 0;

void dfsb(int u, int dep, int prev)
{
	//debug3(u, dep, prev);
	
	rep(i, b[u].size()){
		int v = b[u][i];
		
		if(v != prev){
			cnt = 0;
			dfsb(v, dep + 1, u);
			if(u == 1){
				vec.pb(cnt);
			}
		}
	}
	
	cnt = max(cnt, dep +1);
	
}

int main() {
    __FastIO;   //Be aware to use it!
    
   
   int n, m;
   cin >> n;
   
   int u, v;
   
   forr(i, 1, n - 1){
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
   } 
   
   cin >> m;
   
   forr(i, 1, m -1){
		cin >> u >> v;
		b[u].pb(v);
		b[v].pb(u);
   }
  
	mx = -1; 
   dfsa(1, 0 , -1);

	mx = -1;
	
	dfsa(root, 0, -1);
	
	dfsb(1, 0, -1);
	
	sort(all(vec));
	
	int sz = (int)vec.size();
	int mn;
	
//	debug1(sz);
	if(sz == 1){
		mn = (vec[0]/2) + 1;
	}else{
		mn = min((vec[sz - 1] + vec[sz - 2])/2 + (vec[sz - 1] + vec[sz - 2])%2, vec[sz - 1]);
	}
	
	if(mx > mn){
		cout << "GGEZ" << endl;
	}else{
		cout << "FF" << endl;
	}
	//cout << mx + 1<< endl;
   
    return 0;
}
