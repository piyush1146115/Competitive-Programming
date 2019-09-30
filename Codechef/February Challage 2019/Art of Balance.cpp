/*
 * FILE: Art of Balance.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 06.02.2019 02:04:46 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 06-02-2019	1.0         File Created
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
int freq[30];
int main() {
    __FastIO;   //Be aware to use it!
    int test;
    cin >> test;
    string s;
    
    while(test--){
		clr(freq);
		
		cin >> s;
		rep(i, s.size()){
			freq[s[i] - 'A']++;
		//	debug2(s[i], s[i]-'a');
		}
		
		vi v;
		
		rep(i, 26){
			if(freq[i] > 0){
				v.pb(freq[i]);
				//debug2(i, freq[i]);
			}
		}
		
		int sz =(int)s.size();
		sort(all(v));
		int ch = (int)v.size();
		int ans = INF, cnt;
		//debug2(ch, sz);
		
		forr(i, 1, 26){
			cnt = 0;
				if(sz % i == 0){
					int k = sz/i;
					if(i < ch){
						int bad = ch - i;
						rep(j, bad){
							cnt += v[j];
						}
						rep(j, ch){
							if(v[j] > k){
								cnt += (v[j] - k);
							}
						}
					}else if(i == ch){
						rep(j, ch){
							if(v[j] > k){
								cnt += (v[j] - k);
							}
						}
					}else{
						int sum1 = 0, sum2 = 0;
						rep(j, ch){
							if(v[j] < k){
								sum1 += (k - v[j]);
								//sum += k;
							}
							if(v[j] > k){
								sum2 += (v[j] - k);
							}
							//sum += k;
						}
						cnt += sum1;
						cnt += max(sum2 - sum1, 0);
					}
					//debug2(i, cnt);
					ans = min(ans, cnt);
				}
		}
		cout << ans << endl;
	}
    return 0;
}
