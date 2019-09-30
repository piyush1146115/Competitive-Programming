
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
/*
int bigmod ( int b, int p, int m ) {
    int res = 1 % m, x = b % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}
*/
vi g[MAX];
ll cost[MAX];
bool vis[MAX];
ll res;

void dfs(int u)
{

    vis[u] = 1;
    res = min(res, cost[u]);

    rep(i, (int)g[u].size()){
    int v = g[u][i];
    if(vis[v] == 0)
        dfs(v);
    }
}

int main()
{
    __FastIO;
    ll n, m;

    cin >> n >> m;

    forr(i, 1, n){
        ll k;
        cin >> k;
        cost[i] = k;
    }

    forr(i, 1, m){
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
    }
    ll ans = 0;

    forr(i, 1, n){
     res = INF;
     if(vis[i] == 0){
        dfs(i);
        ans += res;
     }
    }

    cout << ans << endl;
}
