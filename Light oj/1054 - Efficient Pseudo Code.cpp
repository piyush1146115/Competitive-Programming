/*
 * FILE: 1054 - Efficient Pseudo Code.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 04.12.2017 12:24:00 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 04-12-2017	1.0         File Created
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
#define gama 			0.57721566490
#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             100005


ll BM( ll a , ll b , ll m )
{
    if ( b == 0 ) return 1 ;
    ll x = BM(a,b/2,m);
    x = ( x  * x )%m ;
    if( b % 2 ) x = ( x * a) % m ;
    //debug3(a, b, x);
    //getchar();
    return x ;
}

/********************* Code starts here ************************/

vector<ll> prime;
bool chk[MAX];

void sieve()
{
    for(ll i = 2; i <= 100002; i++)
    {
        if(chk[i] == 0)
        {
            //debug1(i);
            for(ll j = i * i; j <= 100002; j += i)
            {
                chk[j] = 1;
            }
            prime.pb(i);
        }
    }
//    debug1(prime.size());
}


ll SOD( ll n, ll m )
{
    ll  k, temp;

    ll sum = 1, inv;

    for(int i = 0; i < (int)prime.size() && (prime[i] * prime[i])<= n; i++)
    {
        ll  factor = 0;
        if(n % prime[i] == 0)
        {
            while(n % prime[i] == 0)
            {
                factor++;
                n = n / prime[i];
            }
            factor = factor * m;
           // debug2(prime[i], n);
            temp = BM(prime[i], factor + 1, MOD);
            inv =  BM(prime[i] - 1, MOD - 2 , MOD);
            k = (temp - 1) *inv;
            sum = ((sum % MOD)*(k % MOD)) % MOD;
        }
    }
    if(n > 1)
    {
        temp = BM(n, m + 1,MOD );
        inv = BM(n - 1, MOD - 2 , MOD);
        k = (temp - 1) *inv;
        sum = ((sum % MOD)*(k % MOD)) % MOD;
    }
        if(sum <= 0)
            sum = 1;
    return sum;
}

int main()
{
    //  __FastIO;   //Be aware to use it!
    //    cout << "Hello World!\n";
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve();

///1000000007 7 these are critical cases
///1000000007 1

    int test;
    scanf("%d" ,&test);
    ll n, m;
    for(int tc = 1; tc <= test; tc++){
        scanf("%lld %lld", &n, &m);
        ll ans = SOD(n, m);
        printf("Case %d: %lld\n",tc, ans);
    }
    return 0;
}
