/*
 * FILE: 1018 - Brush (IV).cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 28.05.2019 10:35:13 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 28-05-2019	1.0         File Created
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

int N;

struct point{
	int x, y;
}ara[20];

int DP[1 << 18];

bool Linear(point A, point B, point C)
{
	int Area = (A.x*B.y + B.x*C.y + C.x*A.y - A.x*C.y - C.x*B.y - B.x*A.y);
	if(Area == 0){
		return true;
	}
	return false;
}

int fun(int mask)
{
	if(mask == ((1 << N) - 1)){
		return 0;
	}
	if(__builtin_popcount(mask) == N-1){
		return 1;
	}
//	debug3(mask, ((1 << N) - 1), __builtin_popcount(mask));
	
	int &ret = DP[mask];
	
	if(ret != -1){
		return ret;
	}
	ret = INF;
	
	rep(i, N){
		if(Check(mask, i) == false){
			
			rep(j, N){
				if(i != j && Check(mask,j) == false){
					int temp = mask;
					rep(k, N){
						if(Linear(ara[i], ara[j], ara[k])){
							temp = Set(temp, k);
						}
					}
					
					ret = min(ret, 1+ fun(temp));
		//			debug3(ret, temp, mask);
				}
			}
			break;
		}
	}
	return ret;
}


int main(){
   // __FastIO;   //Be aware to use it!
    
    int test;
    
    scanf("%d", &test);
    
    forr(tc, 1, test){
		scanf("%d", &N);
		
		rep(i, N){
			scanf("%d %d",&ara[i].x, &ara[i].y);
		}
		fill(DP);
		int ans = fun(0);
		
		printf("Case %d: %d\n",tc, ans);
	}
    return 0;
}
