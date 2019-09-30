/*
 * FILE: Guddu and his Mother.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 03.08.2019 09:48:23 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 03-08-2019	1.0         File Created
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
#define MAX             2111115

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

ll cum[MAX], fow[MAX], bak[MAX], pos[MAX];
//vi v[MAX];
int main() 
{
    __FastIO;   //Be aware to use it!
	
	
	int test;
	cin >> test;
	
	while(test--){
		int n, k;
		cin >> n;
		clr(fow);
		clr(bak);
		
		cum[0] = 0;
		bak[0] = 1;
		forr(i, 1, n){
			cin >> k;
			cum[i] = cum[i - 1] ^ k;
			bak[cum[i]]++;
		}
		/*
		
		v[0].pb(0);
		ll ans = 0;
		int  mx = 0;
		*/
	
		ll ans = 0, mul;
		
		fow[0] = 1;
		pos[0] = 0;
		for(int i = 1; i <= n; i++){
		/*	if((int)v[cum[i]].size() > 0){
				for(int j = 0; j < (int)v[cum[i]].size(); j++){
	        				ans += (i - (v[cum[i]][j] + 1));
				}
			}
			v[cum[i]].pb(i);
			mx = max(mx, cum[i]);
			
			
			
		}*/
		
		if(fow[cum[i]] > 0){
			//debug3(i, pos[cum[i]], cnt[cum[i]]);
			
			mul = fow[cum[i]] * (bak[cum[i]] - fow[cum[i]]);
			ans += (i - (pos[cum[i]] + 1)) * mul;
			ans += max(0LL, fow[cum[i]] * (bak[cum[i]] - fow[cum[i]] - 1));
			
			/*
			 7
			 1 2 3 4 5 6 7
			*/
			
		}
		pos[cum[i]] = i;
		fow[cum[i]]++;
	}
	
		cout << ans << endl;
		/*
		for(int i = 0; i <= mx; i++){
			v[i].clear();
		}*/
	}
    return 0;
}
