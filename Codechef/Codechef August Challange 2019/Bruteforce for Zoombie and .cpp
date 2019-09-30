/*
 * FILE: Bruteforce for Zoombie and .cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 02.08.2019 22:23:10 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 02-08-2019	1.0         File Created
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
ll mark[MAX], ara[MAX], rad[MAX], h[MAX];
int main() {
    __FastIO;   //Be aware to use it!
    
     
	int test;
	cin >> test;
	
	while(test--){
		clr(rad);
		
		ll n;
		cin >> n;
		
		
		forr(i, 1, n){
			cin >> ara[i];
		}
		
		forr(i, 1, n){
			cin >> h[i];
		}
		
		
		
		forr(i, 1, n){
			ll cnt = ara[i] ;
			rad[i]++;
			int j = i - 1;
			while(cnt--){
				if(j == 0){
					break;
				}
				rad[j]++;
				j--;
			}
			
			cnt = ara[i];
			j = i + 1;
			while(cnt--){
				if(j > n){
					break;
				}
				rad[j]++;
				j++;
			}
		}
		
		sort(rad + 1, rad + 1 + n);
		sort(h+ 1, h+n + 1);
		
		int flag = 1;
		forr(i , 1, n){
			if(rad[i]  != h[i]){
				flag = 0;
				break;
			}
		}
		
		if(flag){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
		
		/*
			map<ll, ll> mp;
		
		forr(i, 1, n){
		//	debug2(i, rad[i]);
			mp[rad[i]]++;
		}
		
		
		
		int flag = 1;
		forr(i, 1, n){
			if(mp[h[i]] > 0){
				flag = 1;
			}
			else{
				flag = 0;
				break;
			}
		}
		
		mp.clear();
		
		if(flag){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}*/
	}
    return 0;
}
