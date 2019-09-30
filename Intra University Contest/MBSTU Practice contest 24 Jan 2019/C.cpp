/*
 * FILE: C.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 24.01.2019 11:39:32 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 24-01-2019	1.0         File Created
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
#define MAX             1000005

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

vll prime;
bool chk[MAX];

void sieve()
{
	chk[1] = 1;
	for(ll i = 2; i <= 1000000; i++){
		if(chk[i] == 0){
			prime.pb(i);
			for(ll j = i + i; j <= 1000000; j += i ){
				chk[j] = 1;
			}
		}
	}
}

struct st{
	ll num, rank, indx;
};

vll v;


bool comp(st a, st b)
{
	return a.rank < b.rank;
}

void process(ll n,ll indx)
{
	ll temp = (ll)sqrt(n);
	ll ans = 1, cnt = 0;
	for(ll i = 0; prime[i]*prime[i] <= temp; i++){
		if(temp % prime[i] == 0){
			cnt = 0;
			while(temp % prime[i] == 0){
				cnt++;
				temp /= prime[i];
			}
			cnt *= 2;
			ans *= (cnt + 1);
		}
		
	}
	if(temp > 1){
		ans *= 3ll;
	}
	
//	st tmp;
	if(chk[ans] == 0){
		v.pb(indx);
	}	
}

int main() {
    __FastIO;   //Be aware to use it!
    
    sieve();
    //debug1(prime.size());
    int test;
    cin >> test;
    vll vt;
    while(test--){
			
		ll n, k;
		cin >> n;
		
		rep(i, n){
		//	cin >> ara[i];
			cin >> k;
			vt.pb(k);
		}
		
		sort(all(vt));
		reverse(all(vt));
		
		ll sq;
		
		rep(i, n){
			 sq = (ll)sqrt(vt[i]);
			if(sq * sq == vt[i]){
				process(vt[i], i + 1);
			}
		}
		
		sort(all(v));
		//ckk;
		if((int)v.size() == 0){
			cout << "No supporter found.\n";
		}
		else{
			cout << v[0];
			forr(i, 1, (int)v.size() -1 ){
				cout << " " << v[i];
			}
			cout << endl;
		}
		v.clear();
		vt.clear();
	}
   
    return 0;
}
