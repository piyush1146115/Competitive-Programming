/*
 * FILE: Waiting in Queue .cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 29.10.2018 10:49:57 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 29-10-2018   1.0         File Created
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
ll ara[MAX];
int main() {
    // __FastIO;   //Be aware to use it!
    int test;
    scanf("%d", &test);

    forr(tc, 1, test) {
        ll n, m, k, l, cnt = 0;
        scanf("%lld %lld %lld %lld", &n, &m, &k, &l);

        rep(i, n) {
            scanf("%lld", &ara[i]);
            if(ara[i] < k)
				cnt++;
        }
        ara[n] = k;
        n++;
        sort(ara, ara + n);
        ll Min = (m * l) +  (l - 1);

        rep(i, n) {
			//debug3(i, Min, ara[i]);
            if (ara[i] > k) {
                break;
            }
            ll div = ara[i] / l;
            ll dif = ara[i] - (l * div);
            ll temp2 = max(0ll, m - div);
            ll calc = (l - dif) + (temp2 * l) + (i * l);
			 Min = min(calc, Min);
			 
			if(ara[i] > m*l){
				dif = ara[i] - m*l;
				div = dif/l;
				temp2  = max(0ll, i - div);
				calc = (l - (ara[i]%l)) + (temp2 * l);
				if(temp2 == 0 && ((m+i)*l) < ara[i]){
					if(ara[i] % l == 0 || (ara[i] + (l - (ara[i]%l))) <= k){
						calc = 0;
						
					}
				}
			}
			if((k - (k % l)) >= (m + cnt + 1)*l){
				calc = 0;
				break;
			}
            Min = min(calc, Min);
            //debug3(div, calc, Min);
            //getchar();
        }
        
        printf("%lld\n", Min);

    }
    return 0;
}
