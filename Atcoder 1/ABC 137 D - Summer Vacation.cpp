	/*
	 * FILE: ABC 137 D - Summer Vacation.cpp
	 *
	 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
	 *
	 * LINK:
	 *
	 * DATE CREATED: 11.08.2019 11:34:19 +06
	 *
	 * DESCRIPTION:
	 *
	 * DEVELOPMENT HISTORY:
	 * Date         Version     Description
	 * --------------------------------------------------------------
	 * 11-08-2019	1.0         File Created
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

	struct st{
		int a, b;
	}ara[MAX];

	bool comp(st A , st B){
		if(A.b == B.b){
			return A.a < B.a;
		}
		return A.b > B.b;
	}

	int nxt[MAX], mp[MAX];

	int findpos(int n)
	{
		if(mp[n] == 0){
			return n;
		}
		else{
			return nxt[n] = findpos(nxt[n]);
		}
	}

	int main() {
		__FastIO;   //Be aware to use it!
		
		int  n, m;
		cin >> n >> m;
		
		forr(i, 1, m){
			nxt[i] = i - 1;
		}
		
		rep(i, n){
			cin >> ara[i].a >> ara[i].b;
		}
		
		sort(ara,ara+n, comp);
		
		ll ans = 0;
		int taken = 0;
		rep(i ,n){
			if(ara[i].a > m){
				continue;
			}
			if(m - ara[i].a + 1 >= 1){
			//	debug3(ara[i].a , nxt[m - ara[i].a + 1], mp[m - ara[i].a + 1]);
				if(mp[m - ara[i].a + 1] == 0){
					taken++;
					ans += ara[i].b;
					mp[m - ara[i].a + 1] = 1;
					nxt[m - ara[i].a + 2] = nxt[m - ara[i].a + 1];
				}else{
					int pos = findpos(m - ara[i].a + 1);
					if( pos > 0){
						mp[pos] = 1;
						ans += ara[i].b;
						taken++;
						nxt[pos + 1] = nxt[pos];
						
					}
				}
				
				
			}
			/*forr(j , 1, m){
					debug2(j, nxt[j]);
				}*/
			if(taken == m){
				break;
			}
		}	
		
		cout << ans << endl;
		return 0;
	}
	/*
	8 6
	4 10
	4 10
	3 10 
	3 10 
	2 9 
	2 9
	2 8
	1 5
	*/
