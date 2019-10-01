/*
 * FILE: D.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 01.10.2019 20:33:50 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 01-10-2019	1.0         File Created
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
typedef vector< vi >        vvi;
typedef vector<long long>   vll;


#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define tr(i,c) 		for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define all(ar)         ar.begin(), ar.end()

#define present(c,x) ((c).find(x) != (c).end()) // for map/set
#define cpresent(c,x) (find(all(c),x) != (c).end()) // for vectors


#define fill(ar)   		memset(ar, -1, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"

#define pb              push_back
#define MP 				make_pair
#define sz(a)           int((a).size())


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
ll  BIT[30][MAX * 2], n;

ll query(ll ch, ll idx)
{
	ll sum = 0;
	
	while(idx > 0){
		sum += BIT[ch][idx];
		idx -= idx & (-idx);
	}
	return sum;
}

void update(ll ch, ll idx, ll x)
{
	while(idx <= n){
	BIT[ch][idx] += x;
	idx += idx & (-idx);
}
	
}


int main() {
    __FastIO;   //Be aware to use it!
    clr(BIT);
    ll q;
    
    	string s;
		cin >> s;
		cin >> q;
		n = (ll)sz(s);
		forr(i, 1, sz(s)){
			ll ch = (ll)(s[i - 1] - 'a');
			update(ch, i, 1);
		}
		
		
		
		ll tp, l , r;
		char cc;
    while(q--){
		cin >> tp;
		
		if(tp == 1){
			cin >> l >> cc;
			ll ch = (ll)(cc - 'a');
			update((ll)(s[l - 1] - 'a'), l, -1);
			update(ch, l, 1);
			s[l - 1] = cc;
		}
		else{
			cin >> l >> r;
			ll cnt = 0, sum;
			forr(i, 0, 25){
				sum = query(i, r) - query(i, l - 1);
				if(sum > 0){
					cnt++;
				}
			}
			
			cout << cnt << endl;
		}
	}
    
    return 0;
}
