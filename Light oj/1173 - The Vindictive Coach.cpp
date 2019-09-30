/*
 * FILE: 1173 - The Vindictive Coach.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 29.05.2019 17:32:25 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 29-05-2019	1.0         File Created
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
#define MAX             55

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


ull gun(int a, int b);
bool vis[MAX][MAX], vis2[MAX][MAX];

ull DP[MAX][MAX], DP2[MAX][MAX];

ull fun(int a, int b)
{
	if(a == 0){
		return 0;
	}
	if(a == 1 && b == 0){
		return 1;
	}
	
	ull ret = 0LL;
	
	if(vis[a][b] == 1){
		return DP[a][b];
	}
	
	forr(i, 1, a){
		ret += gun(a - i, b + i - 1);
	}
	vis[a][b] = 1;
	return DP[a][b] = ret;
}

ull gun(int a, int b)
{
	if(b == 0){
		return 0LL;
	}
	if(b == 1 && a == 0){
		return 1LL;
	}
	
	ull ret = 0LL;
	
	if(vis2[a][b] == 1){
		return DP2[a][b];
	}
	
	forr(i, 1, b){
		ret += fun(a+i-1, b-i);
	}
	vis2[a][b] = 1;
	return DP2[a][b] = ret;
}

int main() {
//    __FastIO;   //Be aware to use it!
	
	
	int test, n, m;
	scanf("%d", &test);
	
	clr(vis);
	clr(vis2);
	
	forr(tc, 1 , test){
		scanf("%d %d" , &n, &m);
		
		if(n <= 3){
			printf("Case %d: 1\n",tc);
		}else{
			ull ans;
			if(m == 1){
				ans = gun(n-3, 1);
			}
			else{
				ans = gun(n-m, m-1);
			}
			printf("Case %d: %llu\n",tc, ans);
		}
	}
    return 0;
}
