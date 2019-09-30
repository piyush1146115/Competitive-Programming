/*
 * FILE: E.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 30.08.2019 20:25:29 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 30-08-2019	1.0         File Created
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

int main() {
    __FastIO;   //Be aware to use it!
		
		string s, t;
		int n;
		cin >> n >> s >> t;
		
		string st = "abc";
		string res[200], temp;
		int cnt = 0;
		do{
			
			temp = "";
			for(int i = 0; i < n; i++){
				temp += st;
			}
			res[cnt++] = temp;
			temp = "";
			for(int i = 0; i < n; i++){
				
				temp.pb(st[0]);
				//temp.pb(st[1]);
				//temp.pb(st[2]);
			}
			for(int i = 0; i < n; i++){
				
			//	temp.pb(st[0]);
				temp.pb(st[1]);
				//temp.pb(st[2]);
			}
			for(int i = 0; i < n; i++){
				
				//temp.pb(st[0]);
				//temp.pb(st[1]);
				temp.pb(st[2]);
			}
			res[cnt++] = temp;
			
		}while(next_permutation(st.begin(), st.end()));
	
		
		for(int i = 0 ; i < cnt; i++){
			int flag = 1;
			for(int j = 0; j < (int)res[i].size() - 1; j++){
				if(res[i][j] == s[0] && res[i][j + 1] == s[1]){
					flag = 0;
					break;
				}
				if(res[i][j] == t[0] && res[i][j + 1] == t[1]){
					flag = 0;
					break;
				}
			}
			if(flag){
				cout << "YES" << endl;
				cout << res[i] << endl;
				exit(0);
			}	
		}
		
		cout << "NO" << endl;
    return 0;
}
