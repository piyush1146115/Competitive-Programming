/*
 * FILE: K.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 22.01.2019 01:07:14 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 22-01-2019	1.0         File Created
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
string A[105], B[105], res[105];
int n, m, sz;
int dp[105][105];

int fun(int x, int y)
{
	if(x == n || y == m)
	return 0;
	
	if(dp[x][y] != -1){
		return dp[x][y];
	}
	int ret = 0;
	if(A[x] == B[y]){
		ret = 1 + fun(x + 1, y + 1);
	}else{
		ret = max(fun(x, y + 1), fun(x + 1, y));
	}
	dp[x][y] = ret;
	return ret;
}

void print(int x, int y){
	if(x == n || y == m)
	return;
	
	if(A[x] == B[y]){
		res[sz++] = A[x];
		print(x + 1, y + 1);
	}else{
		if(dp[x + 1][y] > dp[x][y + 1]){
			print(x + 1, y);
		}else{
			print(x, y + 1);
		}
	}
}

int main() {
    //__FastIO;   //Be aware to use it!
	n = m = 0;
	string s;
	fill(dp);
	while(cin >> s){
		
			if(s != "#"){
				if((int)s.size() > 0){
				A[n++] = s;
			}
				continue;
			}
			
			while(cin >> s){
				if(s == "#"){
					break;
				}
				if((int)s.size() > 0){
					B[m++] = s;
				}
			}
			//ckk;
			
			int ans = fun(0, 0);
				sz = 0;
				print(0, 0);
			//	debug2(ans, sz);
				cout << res[0];
				forr(j, 1, sz - 1){
					cout << " " << res[j];
				}
				nl
				
				fill(dp);
				m = n = 0;
		//debug1(s);
		
	}
    return 0;
}
