/*
 * FILE: H - Classy Numbers .cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 30.01.2019 21:41:44 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 30-01-2019	1.0         File Created
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

int sz;
string s;
ll dp[20][3][20];


ll fun(int pos, int boro, ll cnt)
{
	if(pos >= sz){
		if(cnt > 3 || cnt == 0){
			return 0;
		}
		else{
			return 1;
		}
	}
	
	if(dp[pos][boro][cnt] != -1){
		return dp[pos][boro][cnt];
	}
	
	int hi = 9;
	if(boro == 1){
		hi = s[pos] - '0';
	}
	ll n_cnt, ret = 0;
	 int n_boro;
	for(int i = 0; i <= hi; i++){
		n_cnt = cnt, n_boro = boro;
		if(i < hi){
			n_boro = 0;
		}
		if(i > 0){
			n_cnt = cnt + 1;
		}
		ret += fun(pos + 1, n_boro, n_cnt);
	}
	
	return dp[pos][boro][cnt] = ret;
}

int main() {
    //__FastIO;   //Be aware to use it!
	int test;
	scanf("%d", &test);
	
	forr(tc, 1, test){
        string a, b, temp;
        cin >> a >> b;

        int dif = abs((int)a.size() - (int)b.size());
        while (dif--) {
            temp.pb('0');
        }
       
        if ((int)a.size() < (int)b.size()) {
            a = temp + a;
        } else {
            b = temp + b;
        }
        
        fill(dp);
        s = a;
        sz = (int)s.size();   
		//debug3(a, b, sz);
        ll lo = fun(0, 1, 0);
		fill(dp);
        s = b;        
        sz = (int)b.size();
        ll hi = fun(0, 1,0);
        ll ans = hi - lo;
        int cnt = 0;
        
		//debug2(hi, lo);
        rep(i, a.size()) {
            if(a[i] != '0'){
				cnt++;
			}
        }
        if(cnt <= 3){
			ans++;
		}
        printf("%lld\n", ans);
	}
    
    return 0;
}

