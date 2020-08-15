/*
 * FILE: B.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 01.02.2019 01:25:46 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 01-02-2019	1.0         File Created
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

struct data{
	ll indx, a, c;
	
	bool operator<(const data&b)const{
		if(c == b.c){
			return indx < b.indx;
		}else{
			return c < b.c;
		}
	}
};

vector<data> v;
ll ind[MAX];
ll c[MAX], r[MAX];
int main() {
    __FastIO;   //Be aware to use it!
    
    ll n, m;
    cin >> n >> m;
    
    rep(i, n){
		cin >> r[i];
	}
	
	rep(i, n){
		cin >> c[i];
	}
	
	data temp;
	
	rep(i, n){
		temp.a = r[i];
		temp.c = c[i];
		temp.indx = i;
		v.pb(temp);
	}
    
    sort(all(v));
    
    rep(i, n){
		ind[v[i].indx] = i;
		//debug3(v[i].a, v[i].c, v[i].indx);
	}
	
	
    ll d, t, cost, avail = 0;
    vll ans;
    
    while(m--){
		cin >> t >> d;
		t--;
		//debug2(t, d);
		cost = 0;
		if(ind[t] >= 0){
			if(d >= v[ind[t]].a){
				d -= v[ind[t]].a;
				
				cost += (v[ind[t]].a *v[ind[t]].c);
				v[ind[t]].a = 0;
				ind[t] = -1;
			}else{
				v[ind[t]].a -= d;
				cost += (d * v[ind[t]].c);
				d = 0;
			}
		}
		
		while(d > 0){
			if(avail == n){
				break;
			}
			if(d >= v[avail].a){
				ind[v[avail].indx] = -1;
				d -= v[avail].a;
				cost += (v[avail].a * v[avail].c);
				avail++;
			}else{
				v[avail].a -= d;
				cost += (d * v[avail].c);
				d = 0;
			}	
		}
		
		if(d > 0){
			cost = 0;
		}
		ans.pb(cost);
	}
	
	rep(i, ans.size()){
		cout << ans[i] << endl;
	}
/*
8 5
8 6 2 1 4 5 7 5
6 3 3 2 6 2 3 2
2 8
1 4
4 7
3 4
6 10
*/

    return 0;
}
