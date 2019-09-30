/*
 * FILE: 1270 - Tiles (II) Original.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 28.05.2019 16:31:11 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 28-05-2019   1.0         File Created
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
#define MOD             1 << 64
#define EPS             1e-7
#define MAX             105

int Set(int N, int pos) {
    return N = N | (1 << pos);
}
int Reset(int N, int pos) {
    return N = N & ~(1 << pos);
}
bool Check(int N, int pos) {
    return (bool)(N & (1 << pos));
}


ll BM( ll a, ll b, ll m ) {
    if ( b == 0 ) return 1 ;
    ll x = BM(a, b / 2, m);
    x = (( x % m) * (x % m)) % m;

    if ( b % 2 ) x = (( x % m) * (a % m)) % m ;
    return x ;
}

//Auto-format --> ctrl+shift+A

/********************* Code starts here ************************/
int n, m;

int grid[MAX][MAX], mask[MAX];
ull  DP2[105][260];
bool vis[105][260];

ull fun(int row_now, int mask1, int mask2);

ull solve(int row_now, int next)
{
	if(row_now == n){
		if(next == 0){
			return 1;
		}else{
			return 0;
		}
	}else{
		ull &ret = DP2[row_now][next];
		if(vis[row_now][next] == 1){
			return ret;
		}
		ret = fun(row_now, next, mask[row_now + 1]);
		vis[row_now][next] = 1;
		return ret;
	}
}


ull fun(int row_now, int mask1, int mask2) {

   // debug3(row_now, mask1, mask2);
   // getchar();
    if (mask1 == (1 << m)-1){
            return solve(row_now + 1, mask2);
    }

    //debug3(row_now, mask1, mask2);

    ull ret = 0LL;
   /*  ll &ret = DP1[mask1][mask2];
     if(ret != -1){
     return ret;
    }
	ret = 0LL;
   */

    rep(j, m) {
        if (Check(mask1, j) == 0) {

            if (Check(mask2, j) == false) {
                ret += fun(row_now, Set(mask1, j), Set(mask2, j));
            }
            if ((j + 1) < m && Check(mask1, j + 1) == false) {
                ret += fun(row_now, Set(mask1, j)|Set(mask1, j+1), mask2);
            }
            if ((j + 1) < m  && Check(mask2, j) == false && Check(mask2, j + 1) == false) {
                ret += fun(row_now, Set(mask1, j), Set(mask2, j+1) | Set(mask2, j));
            }
            if ((j + 1) < m && Check(mask1, j + 1) == false && Check(mask2, j) == false) {
                ret += fun(row_now, Set(mask1, j+1) | Set(mask1, j), Set(mask2, j));
            }
            if ((j + 1) < m  && Check(mask1, j+1) == false
                    && Check(mask2, j + 1) == false) {
                ret += fun(row_now, Set(mask1, j) | Set(mask1, j+1), Set(mask2, j+1));
            }
            if ((j - 1) >= 0  && Check(mask2, j) == false
                    && Check(mask2, j - 1) == false) {
                ret += fun(row_now, Set(mask1, j), Set(mask2, j)|Set(mask2, j-1));
            }
            break;
        }
    }
    return ret;
}

/*
int solve(int row, int mask) {
    if -> last + 1 row te gelam &mask 0 -- - return 1

            if -> memorized state return koro


                                             res += fun(row, mask, 0);

    return res;

}
*/




int main() {
    //    __FastIO;   //Be aware to use it!

    int test;
    scanf("%d", &test);
	char s[MAX][MAX];

    forr(tc, 1, test) {
        scanf("%d %d", &n, &m);

        clr(vis);
        clr(DP2);
        clr(grid);
        clr(mask);
        
        
        rep(i, n) {
           scanf("%s", s[i]);
        }

        if (m > n) {
            rep(i, n) {
                rep(j, m) {
                    if (s[i][j] == '#') {
                        grid[j][i] = 2;
                    }
                }
            }
            swap(n, m);
        } else {
            rep(i, n) {
                rep(j, m) {
                    if (s[i][j] == '#') {
                        grid[i][j] = 2;
                    }
                }
            }
        }

        rep(i, n) {
            rep(j, m) {
                if (grid[i][j] == 2) {
                    mask[i] = Set(mask[i], j);
                }
            }
            // debug2(i, mask[i]);
        }



        ull ans = solve(0, mask[0]);

        printf("Case %d: %llu\n", tc, ans);

    }

    return 0;
}

/* Input
--------------------------------------------

2
8 8
#........#
..........
..........
..........
..........
..........
..........
#........#

4 24
....#.........................
..............................
..............................
................#.............

* 

Case 2: 1927781900934
Case 1: 
*/
