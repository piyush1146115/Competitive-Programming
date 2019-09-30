/*
 * FILE: C.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 24.02.2019 22:23:21 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 24-02-2019	1.0         File Created
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

ll n, r1, c1, r2, c2;
string s[55];
bool vis[55][55];

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, -1, +1};

bool valid(ll x, ll y)
{
	if(x < n && y < n && x >= 0 && y >= 0 && vis[x][y] == 0 && s[x][y] == '0'){
		return true;
	}	
	return false;
}

ll sq(ll a){
	return abs(a*a);
}

vector<pair<ll,ll> > v1, v2;
void fun(ll x, ll y)
{
	v1.pb({x, y});
	vis[x][y] = 1;
	
	//ll ans = ((x - r2)*(x - r2)) + ((y - c2)*(y - c2));
	
	for(int i = 0; i < 4; i ++){
		ll xx = x + dx[i];
		ll yy = y + dy[i];
		
		if(valid(xx,yy)){
			//ans = min(fun(xx,yy), ans);
			fun(xx, yy);
		}
	}
}

void fun2(ll x, ll y)
{
	v2.pb({x, y});
	vis[x][y] = 1;
	
	//ll ans = ((x - r2)*(x - r2)) + ((y - c2)*(y - c2));
	
	for(int i = 0; i < 4; i ++){
		ll xx = x + dx[i];
		ll yy = y + dy[i];
		
		if(valid(xx,yy)){
			//ans = min(fun(xx,yy), ans);
			fun2(xx, yy);
		}
	}
}


int main() {
    __FastIO;   //Be aware to use it!
	
	cin >> n >> r1 >> c1 >> r2 >> c2;

		rep(i, n){
			cin >> s[i];
		}
		
		r1--;
		c1--;
		r2--;
		c2--;
		
		
    fun(r1, c1);
    clr(vis);
    fun2(r2, c2);
    /*
    cout << ans << endl;
    rep(i, v.size()){
		debug2(v[i].first, v[i].second);
	}*/
	
	ll ans = 100000000000000;
	rep(i, v1.size()){
		rep(j, v2.size()){
			
			ans = min(ans, (sq(v1[i].first - v2[j].first)+  sq(v1[i].second - v2[j].second)));
			//debug3(ans, v1[i].first, v1[i].second);
			//debug2( v2[].first, v1[i].second);
		}
	}
	
	cout << ans << endl;
    return 0;
}
