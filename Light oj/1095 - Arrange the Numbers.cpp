/*
 * FILE: 1095 - Arrange the Numbers.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 30.05.2019 13:40:04 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 30-05-2019	1.0         File Created
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
#define MOD             1000000007
#define EPS             1e-7
#define MAX             1005

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

ll DP[MAX][MAX], fact[MAX], der[MAX], nCr[MAX][MAX];

ll fun(int x, int y)
{
	if(y == 0){
		return der[x];
	}
	if(x == 0){
		return fact[y];
	}
	if(x == 1){
		return (y*fun(x-1,y))%MOD;
	}

	ll &ret = DP[x][y];

	if(ret != -1){
		return ret;
	}
	
	ll a = (y * fun(x - 1,y))%MOD;
	ll b = ((x - 1)*fun(x - 2, y + 1)) % MOD;
	ret = (a + b)%MOD;
	
	return ret;
}

int main() {
    //__FastIO;   //Be aware to use it!
    
    int test;
    
    scanf("%d", &test);
    
    //Calculate Factorial
    fact[0] = 1;
    
    forr(i, 1LL, 1003LL){
		fact[i] = (i*fact[i - 1])%MOD;
	}
	
	//Derrangement
	der[1] = 0;
	der[2] = der[0]= 1;
	
	forr(i, 3LL, 1003LL){
		der[i] = ((i - 1)*(der[i - 1]+der[i - 2]))%MOD;
	}
	
	
	//Calculate Combination
	
	nCr[0][0]=1;
 
    forr(i, 1LL, 1003LL)
    {
        nCr[i][0]=1;
        forr(j, 1, i)
        {
            nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%MOD;
        }
    }
    
    fill(DP);
    int n, m , k;
	
	forr(tc, 1, test){
		scanf("%d %d %d",&n, &m, &k);
		
		ll ans = (fun(m - k, n - m) *nCr[m][k]) %MOD;
		
		printf("Case %d: %lld\n",tc, ans);
	}
    return 0;
}
