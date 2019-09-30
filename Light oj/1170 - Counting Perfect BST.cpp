/*
 * FILE: 1170 - Counting Perfect BST.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 05.09.2019 00:40:14 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 05-09-2019	1.0         File Created
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
#define MOD             100000007
#define EPS             1e-7
#define MAX             100005

int Set(int N,int pos){return N=N | (1<<pos);}
int Reset(int N,int pos){return N= N & ~(1<<pos);}
bool Check(int N,int pos){return (bool)(N & (1<<pos));}


ll BM( ll a , ll b , ll m )
{
    if ( b == 0 ) return 1 ;
    ll x = BM(a,b/2,m);
    x = (( x % m) * (x % m))%m;
    
    if( b % 2 ) x = (( x % m) * (a %m)) % m ;
    return x ;
}

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/
ll numbers[1000006];
int cnt=0;
void generate_num()
{
    for(ll i=2;i<=100000;i++)
    {
        ll num=i*i;
        while(num<=10000000000)
        {
          numbers[cnt++]=num;
          num*=i;
        }
    }
 
    sort(numbers,numbers+cnt);
    cnt=unique(numbers,numbers+cnt)-numbers;
    numbers[cnt++]=1000000000000000;
 
}
 
ll fact[1000006];
 
void gen_fact()
{
    fact[0]=1;
    for(int i=1;i<=1000005;i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
    }
}
 
ll mod_inv(ll n, ll pow)
{
    if(pow==0) return 1;
    if(pow%2==0)
    {
        ll ret=mod_inv(n,pow/2)%MOD;
        return (ret*ret)%MOD;
    }
    return ((n%MOD)*(mod_inv(n,pow-1)%MOD))%MOD;
}
 
 
 
int main()
{
 
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
 
    generate_num();
    gen_fact();
 
    int test;
	scanf("%d", &test);
    forr(tc, 1, test)
    {
        ll a,b;
        scanf("%lld %lld", &a, &b);
 
        ll r=upper_bound(numbers,numbers+cnt,b)-numbers;
        ll l=lower_bound(numbers,numbers+cnt,a)-numbers;
        ll n=(r-l);
        
        printf("Case %d: ",tc);
        
        if(n==0)
            printf("0\n");
        else
        {
			//calculate catalan number
            ll ans=(fact[n+1]*fact[n])%MOD;
            ans=mod_inv(ans,MOD-2);
            ans=(fact[2*n]*ans)%MOD;
            printf("%lld\n",ans);
        }
    }
 
    return 0;
}
