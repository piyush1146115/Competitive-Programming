/*
 * FILE: A.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 16.10.2019 20:45:16 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 16-10-2019	1.0         File Created
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
int ara[MAX], ans[MAX], flag[MAX];
int main() {
    //__FastIO;   //Be aware to use it!
    
    int n;
    cin >> n;
    
    rep(i, n){
		cin >> ara[i];
	}
	int pos = 0, neg = 0;
	
	rep(i, n){
		ans[i] = ara[i]/2;
		flag[i] = abs(ara[i])%2;
		
		if(ara[i] >= 0){
			pos += ans[i];
		}
		else{
			neg += (-1 * ans[i]);
		}
		//debug3(i, pos, neg);
	}
	
	if(pos == neg){
		rep(i, n){
			cout << ans[i] << endl;
		}
	}
	else if(pos > neg){
		rep(i, n){
		//	debug3(i, ara[i], flag[i]);
			if(ara[i] < 0 && flag[i] != 0){
				ans[i]--;
				neg++;
				if(pos == neg){
					break;
				}
				debug1(i);
			}
		}
		rep(i, n){
			cout << ans[i] << endl;
		}
	}
	else{
		rep(i, n){
			if(ara[i] > 0 && flag[i] != 0){
				ans[i]++;
				pos++;
				if(pos == neg){
					break;
				}
			}
		}
		rep(i, n){
			cout << ans[i] << endl;
		}
	}
    return 0;
}
