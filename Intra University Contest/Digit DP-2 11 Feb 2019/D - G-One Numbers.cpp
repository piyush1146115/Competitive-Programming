/*
 * FILE: D - G-One Numbers.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 12.02.2019 09:04:12 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 12-02-2019	1.0         File Created
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
#define MAX             100005

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
bool prime[105];
string a, b;
int DP[12][85][3][3];

void sieve()
{
	prime[1] = 1;
	
	for(int i = 2; i <= 100; i++){
		if(prime[i] == 0){
			for(int j = i+i; j <= 100; j+= i){
				prime[j] = 1;
			}
		}
	}
}

int fun(int pos,int sum, int boro, int choto)
{
		if(pos == 10){
			if(prime[sum] == 0){
				return 1;
			}
			else{
				return 0;
			}
		}
		
		int ret = DP[pos][sum][boro][choto]; 
		
		if(ret != -1){
			return ret;
		}
		
		int lo = 0, hi = 9;
		
		if(boro == 0){
			hi = b[pos] - '0';
		}
		if(choto == 0){
			lo = a[pos] - '0';
		}
		
		int sums = 0;
		
		for(int i = lo; i <= hi; i++){
			sums += fun(pos + 1, sum + i,boro|(i < hi),choto|(i > lo));
		}
		ret = DP[pos][sum][boro][choto] =  sums;
		
		return ret;
}

int main() {
 //   __FastIO;   //Be aware to use it!
	
	sieve();
	
	int test;
	scanf("%d", &test);

	//fill(DP);
	
	while(test--){
		fill(DP);
		cin >> a >> b;
		string temp = "";
		int dif = 10 - (int)a.size();
		
		while(dif--){
			temp.pb('0');
		}
		
		a = temp + a;	
		dif = 10 - (int)b.size();
		temp.clear();
		while(dif--){
			temp.pb('0');
		}
		b = temp + b;
		
		int ans = fun(0, 0, 0, 0);
		
		cout << ans << endl;
	}
    return 0;
}
