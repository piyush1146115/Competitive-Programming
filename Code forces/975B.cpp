		/*
		 * FILE: 975B.cpp
		 *
		 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
		 *
		 * LINK:
		 *
		 * DATE CREATED: 03.05.2018 15:52:17 +06
		 *
		 * DESCRIPTION:
		 *
		 * DEVELOPMENT HISTORY:
		 * Date         Version     Description
		 * --------------------------------------------------------------
		 * 03-05-2018	1.0         File Created
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

		ll fun(vll v, int pos)
		{
			ll n = v[pos];
			ll div = n/14;
			v[pos] = 0;
			
			rep(i, v.size()){
				v[i] += div;
			}
			
			n = n % 14;
			
			while(n--){
				v[(pos + n + 1) % 14]++;
				debug3(pos, n, (pos+n + 1)%14);
			}
			ll ans = 0;
			rep(i, v.size()){
				debug1(v[i]);
				
				if(v[i] % 2 == 0){
					ans += v[i];
				}
			}
		//	getchar();
			return ans;
		}

		int main() {
			__FastIO;   //Be aware to use it!
			vll vec;
			
			forr(i, 1, 14){
				ll k;
				cin >> k;
				vec.pb(k);
			}
			
			ll ans = 0;
			forr(i, 0, 13){
				ans = max(ans, fun(vec, i));
			}
			
			cout << ans << endl;
			return 0;
		}
