/*
 * FILE: 1118C.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 23.02.2019 22:14:34 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 23-02-2019	1.0         File Created
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

int n;

priority_queue<pii > q;
vector<vi > a;

int rev(int i)
{
	return n - i - 1;
}

int no(){
	cout << "NO" << endl;
	exit(0);
}

void put(vector<pii > pos){
	auto t(q.top());
	q.pop();
	if(t.first < (int)pos.size()){
			no();
	}
	
	for(auto [i,j]: pos){
		a[i][j] = t.second;
	}
	t.first -= (int)pos.size();
	q.push(t);
}

int main() {
    __FastIO;   //Be aware to use it!
    
    cin >> n;
    
    map<int, int> cnts;
    
    rep(i, n*n){
		int val;
		cin >> val;
		cnts[val]++;
	}
	
	for(auto[key, value]:cnts){
		q.push({value,key});
	}
	a = vector<vi >(n, vi(n));
	int m = n/2;
	
	rep(i, m){
		rep(j,m){
			put({{i,j}, {i, rev(j)} ,{rev(i),j}, {rev(i),rev(j)}});
		}
	}
	
	if(n%2 != 0){
		rep(i, m){
			put({{i,m}, {rev(i),m}});
			put({{m,i}, {m,rev(i)}});
		}
		put({{m,m}});
	}
	
	cout << "YES" << endl;
	
	rep(i, n){
		rep(j, n){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}
