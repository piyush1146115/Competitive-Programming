/*
 * FILE: ABC 129 D - Lamp.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 20.08.2019 14:34:43 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 20-08-2019	1.0         File Created
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
#define MAX             2005

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

string s[MAX];

int L[MAX][MAX], R[MAX][MAX], U[MAX][MAX], D[MAX][MAX];

int main() {
    __FastIO;   //Be aware to use it!
    
	int r, c;
	cin >> r >> c;
	
	rep(i, r){
		cin >> s[i];
	}
	
	int cnt = 0;
	for(int i = 0; i < r; i++){
		cnt = 0;
		for(int j = 0; j < c; j++){
			if(s[i][j] == '#'){
				cnt = 0;
			}else{
				L[i][j] = cnt++;
			}
		}
	}
	
	for(int i = 0; i < c; i++){
		cnt = 0;
		for(int j = 0; j < r; j++){
			if(s[j][i] == '#'){
				cnt = 0;
			}
			else{
				U[j][i] = cnt++;
			}
		}
	}
	
	
	for(int i = 0; i < r; i++){
		cnt = 0;
		for(int j = c - 1; j >= 0; j--){
			
			if(s[i][j] == '#'){
				cnt = 0;
			}
			else{
				R[i][j] = cnt++;
			}
		}
	}
	
	for(int i = 0; i < c; i++){
		cnt = 0;
		for(int j = r - 1; j >= 0; j--){
			if(s[j][i] == '#'){
				cnt = 0;
			}
			else{
				D[j][i] = cnt++;
			}
		}
	}
	
	int ans = 0;
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(s[i][j] != '#'){
				ans = max(ans,1 + L[i][j] + R[i][j] + D[i][j] + U[i][j]);
			}
		}
	}
	
	cout << ans << endl;
	
    return 0;
}
