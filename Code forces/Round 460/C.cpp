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


/********************* Code starts here ************************/
string s[2005];
int  n, m , k;
//
//bool fun1(int r, int c)
//{
//
//    int cnt = 0;
//    forr(i, c, m -1 ){
//    if(s[r][i] == '*')
//        break;
//
//    cnt++;
//    }
//    if(cnt >= k)
//        return 1;
//    else
//        return 0;
//}
//
//bool fun2(int r, int c)
//{
//    int cnt = 0;
//    forr(i, r, n -1 ){
//    if(s[i][c] == '*')
//        break;
//
//    cnt++;
//    }
//    if(cnt >= k)
//        return 1;
//    else
//        return 0;
//}
int main() {
    __FastIO;   //Be aware to use it!
    cin >> n >> m >> k;

    forr(i, 0, n - 1){
    cin >> s[i];
    }

    int ans = 0, sm = 0;
    forr(i, 0, n -1){
    int sum = 0;
    forr(j, 0, m -1){
        if(s[i][j] == '.'){
            sum++;
            sm++;
        }
        else{
            sum = 0;
        }
        if(sum >= k)
            ans++;
    }
    }

    forr(i, 0, m -1){
    int sum = 0;
    forr(j, 0, n -1){
        if(s[j][i] == '.'){
            sum++;
    //        sm++;
        }
        else{
            sum = 0;
        }
        if(sum >= k)
            ans++;
    }
    }

    if(k == 1)
        ans = sm;

    cout << ans << endl;
    return 0;
}
