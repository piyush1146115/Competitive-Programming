/*
 * FILE: E - Baker Vai .cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 16.04.2019 22:54:44 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 16-04-2019	1.0         File Created
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
#define MAX             105

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


int n, m, ara[MAX][MAX];
int DP[MAX][MAX][MAX][5];

int fun(int row, int c1, int c2, int move)
{
	if(row == n -1 && c1 == m - 2 && c2 == m - 1 && move == 1){
		return 0;
	}
	
	if(DP[row][c1][c2][move] != -1){
		return DP[row][c1][c2][move];
	}
	int ret = 0;
	if(move == 0){
		if(c2 + 1 < m)
		ret = max( ret, ara[row][c2 + 1] + fun(row, c1, c2 + 1, 0));
		
		ret = max(ret, fun(row, c1, c2, 2));
		
	}
	else if(move == 1){
		if(c1 + 1 < c2){
			ret = max( ret, ara[row][c1 + 1] + fun(row, c1 + 1, c2, 1));
		}
		ret = max( ret,fun(row, c1, c2, 0));
	}
	else if(move == 2){
		if(row + 1 < n)
		ret = max(ret, ara[row + 1][c1] + ara[row+1][c2] + fun(row+1,c1,c2,1));
	}
	return DP[row][c1][c2][move] = ret;
}

int main() {
    //__FastIO;   //Be aware to use it!
    
    int test;
    scanf("%d", &test);
    
    forr(tc, 1, test){
		scanf("%d %d", &n, &m);
		fill(DP);
		rep(i, n){
			rep(j, m){
				scanf("%d", &ara[i][j]);
			}
		}
		int ans = ara[0][0] + ara[0][1] + fun(0, 0, 1, 1);
		
		printf("Case %d: %d\n",tc, ans);
	}
    
    return 0;
}
