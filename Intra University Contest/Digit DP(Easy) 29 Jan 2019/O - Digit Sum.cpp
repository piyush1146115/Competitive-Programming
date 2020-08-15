/*
 * FILE: O - Digit Sum.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 30.01.2019 21:23:57 +06
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
ll dp[17][3][150];

ll fun(int pos, int boro,int cnt) {
    if (pos >= sz) {
        return (ll)cnt;
    }
	if(dp[pos][boro][cnt] != -1){
		return dp[pos][boro][cnt];
	}
	
    int hi = 9;
    if (boro == 1) {
        hi = s[pos] - '0';
    }
	//debug3(pos, boro, cnt);
    ll ret = 0;
       
    for (int i = 0; i <= hi; i++) {
        int n_cnt = cnt, n_boro = boro;
           n_cnt += i;
        if (i == hi && boro == 1) {
            n_boro = 1;
        }else{
			n_boro = 0;
		}
		
        ret += fun(pos + 1, n_boro, n_cnt );
    }
    return dp[pos][boro][cnt] = ret;
}

int main() {
    //__FastIO;   //Be aware to use it!
    ll l, r;
    int test;
    scanf("%d", &test);
	
	forr(tc, 1, test){
    scanf("%lld %lld", &l, &r);
        string a, b, temp;
        if (l == -1 && r == -1) {
            break;
        }
        ll k;
        while (l != 0) {
            k = l % 10;
            l /= 10;
            a.pb((char)(k + '0'));
        }

        while (r != 0) {
            k = r % 10;
            r /= 10;
            b.pb((char)(k + '0'));
        }
        reverse(all(a));
        reverse(all(b));

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
        //debug2(hi, lo);
        rep(i, a.size()) {
            ans += (a[i] - '0');
        }
        printf("%lld\n", ans);
    }
    return 0;
}
