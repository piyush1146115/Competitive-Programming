	/*
	 * FILE: 1060 nth permutation .cpp
	 *
	 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
	 *
	 * LINK:
	 *
	 * DATE CREATED: 28.03.2019 11:10:01 +06
	 *
	 * DESCRIPTION:
	 *
	 * DEVELOPMENT HISTORY:
	 * Date         Version     Description
	 * --------------------------------------------------------------
	 * 28-03-2019   1.0         File Created
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

	#define fill(ar)        memset(ar, -1, sizeof(ar))
	#define clr(a)          memset(a, 0, sizeof(a))

	#define nl              cout << '\n';
	#define sp              cout << ' ';
	#define ckk             cout << "##########\n"

	#define pb              push_back
	#define MP              make_pair

	#define debug1(x)       cerr << #x << ": " << x << endl
	#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
	#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

	#define gama 0.57721566490
	#define PI              acos(-1.0)
	#define INF             0x7fffffff
	#define MOD             1000000007
	#define EPS             1e-7
	#define MAX             100005

	ll BM( ll a, ll b, ll m ) {
		if ( b == 0 ) return 1 ;
		ll x = BM(a, b / 2, m);
		x = (( x % m) * (x % m)) % m;

		if ( b % 2 ) x = (( x % m) * (a % m)) % m ;
		return x ;
	}

	//Auto-format --> ctrl+shift+a
	/********************* Code starts here ************************/

	string s, ans;
	int taken[30];
	ll fact[25];

	ll  calc() {
		ll lob = 0, hor = 1;

		for (int i = 0; i < 26; i++) {
			lob += taken[i];
			hor *= fact[taken[i]];
		}
		ll ret = fact[lob] / hor;
		return ret;

	}
	void print(int pos, ll k) {
		if (pos == (int)s.size()) {
			cout << ans << endl;
			return;
		}
		for (int i = 0; i < 26; i++) {
			if (taken[i] > 0) {
				taken[i]--;
				ll temp = calc();
				if(k > temp){
					taken[i]++;
					k -=temp;
					continue;
				}
				ans.pb((char)(i + 'a'));
				
				print(pos + 1, k);
				ans.pop_back();
				taken[i]++;
				break;
			}
		}
	}

	int main() {
		// __FastIO;   //Be aware to use it!
		int test;
		ll k;

		//scanf("%d", &test);
		cin >> test;
		fact[0] = 1;

		forr(i, 1LL, 20LL) {
			fact[i] = i * fact[ i - 1];
		}

		forr(tc, 1, test) {
			clr(taken);
			ans.clear();
			cin >> s >> k;
			//scanf("%lld", &k);
			rep(i, s.size()) {
				taken[s[i] - 'a']++;
			}
			//printf("Case %d: ", tc);
		   // debug1(calc());
			cout << "Case " << tc << ": ";
			if (calc() < k) {
				cout << "Impossible\n";
				//printf("Impossible\n");
			} else {
				print(0, k);
			}
		}

		return 0;
	}
