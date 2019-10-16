/*
 * FILE: D.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 13.10.2019 14:53:46 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 13-10-2019   1.0         File Created
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
typedef vector< vi >        vvi;
typedef vector<long long>   vll;


#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define tr(i,c)         for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define all(ar)         ar.begin(), ar.end()

#define present(c,x) ((c).find(x) != (c).end()) // for map/set
#define cpresent(c,x) (find(all(c),x) != (c).end()) // for vectors


#define fill(ar)        memset(ar, -1, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"

#define pb              push_back
#define MP              make_pair
#define sz(a)           int((a).size())


#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define gama 0.57721566490
#define PI              acos(-1.0)
#define INF             0x7ffffffffffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             100005

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
ll col[5][MAX];
vi gr[MAX];
int deg[MAX];
ll DP[MAX][5][5], ans[MAX];


ll fun(int pos, int par, int f1, int f2) {
    ll ret1, ret2, ret3;
    ret1 = ret2 = ret3 = INF;


    if (DP[pos][f1][f2] != -1) {
        return DP[pos][f1][f2];
    }

    int flag = 1;
    rep(i, gr[pos].size()) {
        int v = gr[pos][i];
        if (v != par) {
            flag = 0;
            if (f1 != 1 && f2 != 1) {
                ret1 = col[1][pos] + fun(v, pos, 1, f1);
            }
            if (f1 != 2 && f2 != 2) {
                ret2 = col[2][pos] + fun(v, pos, 2, f1);
            }
            if (f1 != 3 && f2 != 3) {
                ret3 = col[3][pos] + fun(v, pos, 3, f1);
            }
        }
    }

    if (flag) {
        if (f1 != 1 && f2 != 1) {
            ret1 = col[1][pos];
        }
        if (f1 != 2 && f2 != 2) {
            ret2 = col[2][pos];
        }
        if (f1 != 3 && f2 != 3) {
            ret3 = col[3][pos];
        }
    }

    ll mn = min(ret1, min(ret2, ret3));
    //debug3(pos, par, f1);
    //debug3(f2, ret1, ret2);
    //debug2(ret3, mn);
    //getchar();

    return DP[pos][f1][f2] = mn;
}


void path(int pos, int par, int f1, int f2) {
    ll ret1, ret2, ret3;
    ret1 = ret2 = ret3 = INF;




    int flag = 1;
    rep(i, gr[pos].size()) {
        int v = gr[pos][i];
        if (v != par) {
            flag = 0;
            if (f1 != 1 && f2 != 1) {
                ret1 = col[1][pos] + fun(v, pos, 1, f1);
            }
            if (f1 != 2 && f2 != 2) {
                ret2 = col[2][pos] + fun(v, pos, 2, f1);
            }
            if (f1 != 3 && f2 != 3) {
                ret3 = col[3][pos] + fun(v, pos, 3, f1);
            }
            
            if (ret1 == DP[pos][f1][f2]) {
                ans[pos] = 1;
                path(v, pos, 1, f1);
            } else if (ret2 == DP[pos][f1][f2]) {
                ans[pos] = 2;
                path(v, pos, 2, f1);
            } else if (ret3 == DP[pos][f1][f2]) {
                ans[pos] = 3;
                path(v, pos, 3, f1);
            }
        }
    }

    if (flag) {
        if (f1 != 1 && f2 != 1) {
            ret1 = col[1][pos];
        }
        if (f1 != 2 && f2 != 2) {
            ret2 = col[2][pos];
        }
        if (f1 != 3 && f2 != 3) {
            ret3 = col[3][pos];
        }


        ll mn = min(ret1, min(ret2, ret3));
        if (ret1 == mn) {
            ans[pos] = 1;
        } else if (ret2 == mn) {
            ans[pos] = 2;
        } else {
            ans[pos] = 3;
        }

    }
    return;
}
//debug3(pos, par, f1);
//debug3(f2, ret1, ret2);
//debug2(ret3, mn);
//getchar();


int main() {
    __FastIO;   //Be aware to use it!
    fill(DP);
    int n;

    cin >> n;

    forr(i, 1, n) {
        cin >> col[1][i];
    }

    forr(i, 1, n) {
        cin >> col[2][i];
    }
    forr(i, 1, n) {
        cin >> col[3][i];
    }
    int u, v;

    forr(i, 1, n - 1) {
        cin >> u >> v;
        gr[u].pb(v);
        gr[v].pb(u);
        deg[u]++;
        deg[v]++;
    }


    int root;
    forr(i, 1, n) {
        if (deg[i] >= 3) {
            cout << -1 << endl;
            exit(0);
        }
        if (deg[i] == 1) {
            root = i;
        }

    }

    ll ret = fun(root, 0, 0, 0);
    path(root, 0,0,0);
    
    cout << ret << endl;
	forr(i, 1, n){
		cout << ans[i] << " ";
	}
	cout << endl;
    return 0;
}
