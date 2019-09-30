/*
 * FILE: 1090 - Trailing Zeroes (II).cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 01.12.2017 10:18:55 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 01-12-2017	1.0         File Created
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

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"
#define pb              push_back
#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             100005


/********************* Code starts here ************************/
/**
critical case:
4
702306 679024 477085 336328
661314 197106 616125 353896
819583 498443 898815 233368
509211 296199 127307 186754
*/
int main() {
	int test;
    //debug1(fun(10));
    scanf("%d", &test);

    forr(tc, 1, test){
		ll n, r, p, q;
		scanf("%lld %lld %lld %lld", &n,&r, &p, &q);
		ll ans = 0;
		ll cnt2 , cnt5;
		cnt2  = cnt5 = 0;
		while(p % 2 == 0){
            cnt2++;
            p /= 2;
		}
		while(p % 5 == 0){
            cnt5++;
            p /= 5;
		}
		cnt2 *= q;
		cnt5 *= q;
		ll div = 2;

	while(n >= div){
		cnt2 += (n /div);
		div *= 2;
	}
	div = 5;
	while(n >= div){
		cnt5 += (n /div);
		div *= 5;
	}
		//ans = min(cnt2, cnt5);
		div = 2;

	while(r >= div){
		cnt2 -= (r /div);
		div *= 2;
	}
	div = 5;
	while(r >= div){
		cnt5 -= (r /div);
		div *= 5;
	}
	n = n - r;
     div = 2;

	while(n >= div){
		cnt2 -= (n /div);
		div *= 2;
	}
	div = 5;
	while(n >= div){
		cnt5 -= (n /div);
		div *= 5;
	}

	ans = min(cnt2, cnt5);
	if(ans < 0)
        ans = 0;

//
//		debug3(fun(n), fun(r), fun(n- r));
//		debug1(fun(p));
//
		printf("Case %d: %lld\n",tc, ans);
	}
    return 0;
}
