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
#define MAX             1000005

ll bigmod ( ll b, ll p, ll m ) {
    ll res = 1 % m, x = b % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}

ll fact[MAX];
int freq[30];

int main()
{
    __FastIO;
    string a, b;

    cin >> a >> b;

    int  sz = a.size();
    fact[0] = 1;

    forr(i, 1, sz){
    fact[i] = ((fact[i - 1] %MOD) *(i % MOD)) % MOD;

    }

    rep(i, sz){
    freq[a[i]]++;
    }
    ll res = 1; ;
    rep(i, sz){
    if(a[i] < b[i]){

        for(int j = 0 ; j < 26 ;j++){
            res = ((res % MOD) * (fact[freq[j]]) % MOD) % MOD;
        }

        forr(j, 0, 25){
            if(freq[i] > 1){
                res = res * (bigmod(fact[freq[j]], MOD - 2, MOD));
            }
        }
        break;
    }
    freq[a[i]]--;
    }
 res--;

 cout << res << endl;
}
