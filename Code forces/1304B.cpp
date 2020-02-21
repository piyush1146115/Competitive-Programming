/*
 * FILE: 1304B.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 16.02.2020 12:22:45 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 16-02-2020	1.0         File Created
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
int mp[105];

int main() {
    __FastIO;   //Be aware to use it!
    
    int n, m;
    cin >> n >> m;
    string s[n +5];
    
    rep(i, n){
		cin >> s[i];
	}
	vi v1, v2;
	
	
	rep(i, n){
		if(mp[i] == 0){
			for(int j = i + 1; j < n; j++){
				if(mp[j] == 0){
					int flag = 1;
					for(int k = 0; k < m; k++){
						if(s[i][k] != s[j][m - k - 1]){
							flag = 0;
							break;
						}
					}
					if(flag){
						v1.pb(i);
						v2.pb(j);
						mp[i] = mp[j] = -1;
					}
				}
			}
		}
	}
	
	string temp = "";
	rep(i, n){
		if(mp[i] == 0){
			int flag = 1;
			for(int j = 0; j < m; j++){
				if(s[i][j] != s[i][m -1 - j]){
					flag = 0;
				}
			}
			if(flag){
				temp = s[i];
			}
		}
	}
	
	string ans = "";
	
	
	rep(i, sz(v1)){
		ans += s[v1[i]];
	}
	ans += temp;
	reverse(all(v2));
	rep(i, sz(v2)){
		ans += s[v2[i]];
	}
	
	cout << sz(ans) << endl;
	cout << ans << endl;
	
	
    return 0;
}
