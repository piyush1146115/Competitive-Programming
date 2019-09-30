
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

bool fun(int n)
{
    int p , q;
    p = q = 0;
  debug3(n, p, q);
    while(n % 2 == 0){
         n >>= 1;
         p++;
    }
  debug3(n, p, q);
    while(n % 2 == 1){
         n >>= 1;
         q++;
    }
    debug3(n, p, q);
    if(n)
        return false;

    if(p + 1 == q )
        return true;
    else
        return false;

}
int main()
{
    __FastIO;
    int n;

    cin >> n ;
    int ans = 1;

    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            if(i % 2 == 0){
                if(fun(i)){
                    ans = max(ans, i);
                }
            }
            int div = n / i;
            if(div % 2 == 0){
//                    debug1(div);
                if(fun(div)){
                    ans = max(div, ans);
                }
            }
        }
    }

    printf("%d\n",ans);

}
