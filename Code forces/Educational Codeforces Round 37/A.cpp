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
#define MAX             205

ll BM( ll a , ll b , ll m )
{
    if ( b == 0 ) return 1 ;
    ll x = BM(a,b/2,m);
    x = (( x % m) * (x % m))%m;

    if( b % 2 ) x = (( x % m) * (a %m)) % m ;
    return x ;
}


/********************* Code starts here ************************/
bool ara[MAX];
int n, k;

int fun(int i)
{
    int cnt = 1;
    int flag = 0;

    while(i <= n){
        if(ara[i] == 1){
            flag = 1;
            break;
        }
        cnt++;
        i++;
    }
    if(flag)
        return cnt;
    return INF;
}


int fun2(int i)
{
    int cnt = 1;
    int flag = 0;

    while(i >= 1){
        if(ara[i] == 1){
            flag = 1;
            break;
        }
        cnt++;
        i--;
    }
    if(flag)
        return cnt;
    return INF;
}
int main() {
    __FastIO;   //Be aware to use it!
    int test;
    cin >> test;
    while(test--){
    cin >> n >> k;
    clr(ara);
    forr(i, 1, k){
    int m;
    cin >> m;
    ara[m] = 1;
    }
    int ans = 0;
    forr(i, 1, n){
    int mn = INF;
    mn = min(mn, fun(i));
    mn = min(mn, fun2(i));;
    ans = max(mn, ans);
    debug3(i, mn, ans);
    }

    cout << ans << endl;
    }


    return 0;
}

