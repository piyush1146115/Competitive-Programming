/*
 * FILE: E - Array and Segments (Easy version).cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 04.07.2019 02:26:35 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 04-07-2019	1.0         File Created
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
#define MAX             305

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
struct st{
	int l, r;
}ara[MAX];

int main() {
    __FastIO;   //Be aware to use it!
    
    int n, m;
    vi v;
    v.pb(0);
    cin >> n >> m;
    rep(i, n){
		int temp;
		cin >> temp;
		v.pb(temp);
	}
	rep(i, m){
		cin >> ara[i].l >> ara[i].r;
	}
	
	int Ans = -INF;
	vi fin;
	
	forr(i,1, n){
		vi temp, ind;
		temp = v;
		rep(j, m){
			if(ara[j].l <= i && ara[j].r >= i){
				forr(k, ara[j].l, ara[j].r){
					temp[k]--;
				}
				ind.pb(j + 1);
			}
		}
		int mn = INF, mxx = -INF;
		
		forr(j, 1, n){
			mn = min(mn, temp[j]);
			mxx = max(mxx, temp[j]);
		}
		
		int dif = abs(mxx- mn);
		if(dif > Ans){
			Ans = dif;
			fin = ind;
		}
	}
	
	int mn = INF, mxx = -INF;
		
		forr(j, 1, n){
			mn = min(mn, v[j]);
			mxx = max(mxx, v[j]);
		}
	int dif = abs(mxx- mn);
	
	if(dif > Ans){
		cout << dif << endl;
		cout << 0 << endl;
		exit(0);
	}
	
	cout << Ans << endl;
	cout << fin.size() << endl;
	rep(i, fin.size()){
		cout << fin[i] << " ";
	}
	cout << endl;
	
    return 0;
}
