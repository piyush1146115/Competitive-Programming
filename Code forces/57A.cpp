/*
 * FILE: 57A.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 02.04.2019 23:25:03 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 02-04-2019	1.0         File Created
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

int main() {
    __FastIO;   //Be aware to use it!
    
    int n, x1, y1, x2, y2;
    
    cin >> n >> x1 >> y1 >> x2 >> y2;
    
    int t1, t2;
    
    if(x1 == 0){
		t1 = 1;
	}else if(y1 == 0){
		t1 = 2;
	}else if(x1 == n){
		t1 = 3;
	}else{
		t1 = 4;
	}
    
    if(x2 == 0){
		t2 = 1;
	}else if(y2 == 0){
		t2 = 2;
	}else if(x2 == n){
		t2 = 3;
	}else{
		t2 = 4;
	}
    
    int ans = 0;
    
    if(t1 == 1){
		if(t2 == 1){
			ans = abs(y1 - y2);
		}else if(t2 == 2){
			ans = y1 + x2;
		}else if(t2 == 3){
			ans = min(y1+n+y2, (n - y1) + n + (n - y2));
		}else{
			ans = (n - y1) + x2;
		}
	}else if(t1 == 2){
		if(t2 == 1){
			ans = x1 + y2;
		}else if(t2 == 2){
			ans = abs(x1 - x2);
		}else if(t2 == 3){
			ans = (n - x1) + y2;
		}else{
			ans = min(x1+n+x2, (n - x1) + n + (n - x2));
		}
	}
	else if(t1 == 3){
		if(t2 == 1){
			ans = min(y1+n+y2, (n - y1) + n + (n - y2));
		}else if(t2 == 2){
			ans = y1 + (n - x2);
		}else if(t2 == 3){
			ans = abs(y1 - y2);
		}else{
			ans = (n - y1) + (n - x2);
		}
	}
	else{
		if(t2 == 1){
			ans = x1 + (n - y2);
		}else if(t2 == 2){
				ans = min(x1+n+x2, (n - x1) + n + (n - x2));
		}else if(t2 == 3){
			ans = (n- x1) + (n - y2);
		}else{
			ans = abs(x1 - x2);
		}
	}
	
	cout << ans << endl;
    return 0;
}
