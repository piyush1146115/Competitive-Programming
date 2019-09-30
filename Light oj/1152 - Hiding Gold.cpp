/*
 * FILE: 1152 - Hiding Gold.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 04.09.2019 01:39:28 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 04-09-2019   1.0         File Created
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
#define MAX             405

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

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/

int source, sink, par[MAX], vis[MAX], cap[MAX][MAX], tot;


int BFS() {
    int pathcap, i, cur, now;

    queue<int> q;
    pathcap = INF;
    memset(vis, false, sizeof(vis));
    memset(par, -1, sizeof(par));


    q.push(source);

    while (!q.empty()) {

        cur = q.front(); q.pop();
        //    debug2(cur, tot);
        if (cur == sink) break;

        for (i = 1; i < tot; i++) {
            // debug3(cur, i, c[cur][i]);
            if (cap[cur][i] <= 0 || vis[i]) continue;
            par[i] = cur;
            vis[i] = true;
            //     debug3(cur, i, par[i]);
            q.push(i);
        }
    }

    int prv;

    now = sink;
    while (par[now] > -1) {
        prv = par[now];
        //  debug2(now, prv);
        //  getchar();
        if (now == source) {
            break;
        }
        pathcap = min(pathcap, cap[prv][now]);
        now = prv;
    }

    now = sink;
    while (par[now] > -1) {
        prv = par[now];
        if (now == source) {
            break;
        }
        cap[prv][now] -= pathcap;
        cap[now][prv] += pathcap;
        now = prv;
    }

    if (pathcap == INF) pathcap = 0;

    return pathcap;
}


int max_flow() {
    int ans, flow;

    ans = 0;

    while (1) {
        flow = BFS();
        // debug1(flow);
        if (flow == 0) break;
        ans += flow;
    }

    return ans;
}


int mp[25][25], flag[25][25], flag2[25][25];
char str[25][25];

int main() {
    //__FastIO;   //Be aware to use it!

    int test, r, c;
    scanf("%d", &test);


    int cnt = 0;

    rep(i, 20) {
        rep(j, 20) {
            mp[i][j] = ++cnt;
        }
    }


    forr(tc, 1, test) {

        scanf("%d %d", &r, &c);
        clr(cap);
        clr(flag);
        clr(flag2);

        int n = 0;
        char ch;
        //getchar();

        rep(i, r) {
            scanf("%s", str[i]);
        }


        rep(i, r) {
            //getchar();
            rep(j, c) {


                ch = str[i][j];
                //    debug3(i, j, ch);
                if (ch == '*') {
                    n++;
                    if (i % 2 == 0 && j % 2 == 1) {
                        continue;
                    }

                    if (i % 2 == 1 && j % 2 == 0) {
                        continue;
                    }
                    if (i - 1 >= 0 && str[i - 1][j] == '*') {
                        flag[i][j] = 1;
                        flag2[i - 1][j] = 1;
                        cap[mp[i][j]][mp[i - 1][j]] = INF;
                        // cap[mp[i - 1][j]][mp[i][j]] = INF;

                    } else if (i - 1 >= 0) {
                        cap[mp[i][j]][mp[i - 1][j]] = 0;
                    }

                    if (i + 1 < r && str[i + 1][j] == '*') {
                        flag[i][j] = 1;
                        flag2[i + 1][j] = 1;

                        cap[mp[i][j]][mp[i + 1][j]] = INF;
                        //cap[mp[i + 1][j]][mp[i][j]] = INF;
                    } else if (i + 1 < r) {
                        cap[mp[i][j]][mp[i + 1][j]] = 0;
                    }

                    if (j - 1 >= 0 && str[i][ j - 1] == '*') {
                        flag[i][j] = 1;
                        flag2[i][j - 1] = 1;

                        cap[mp[i][j]][mp[i][j - 1]] = INF;
                        //cap[mp[i][j - 1]][mp[i][j]] = INF;
                    } else if (j - 1 >= 0) {
                        cap[mp[i][j]][mp[i][j - 1]] = 0;
                    }

                    if (j + 1 < c && str[i][j + 1] == '*') {
                        flag[i][j] = 1;
                        flag2[i][j + 1] = 1;

                        cap[mp[i][j]][mp[i][j + 1]] = INF;
                        //cap[mp[i][j + 1]][mp[i][j]] = INF;
                    } else if (j + 1 < c) {
                        cap[mp[i][j]][mp[i][j + 1]] = 0;
                    }
                }

                // getchar();
            }
        }


        

        rep(i, r) {
            rep(j, c) {
               if(flag2[i][j]){
				   cap[mp[i][j]][402] = 1;
			   }
			   if(flag[i][j]){
				   cap[401][mp[i][j]] = 1;
			   }
            }
        }

        source = 401;
        sink = 402;

        tot = 404;


        int ans = max_flow();
        //debug2(n, ans);

        printf("Case %d: %d\n", tc, n - ans);
    }

    return 0;
}

/*
5
15 2
o*
**
oo
o*
**
o*
o*
o*
*o
**
*o
*o
**
**
o*

*/
