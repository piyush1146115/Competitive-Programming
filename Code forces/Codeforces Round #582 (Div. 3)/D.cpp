
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

ll n, k;
ll ara[MAX], temp[MAX], inp[MAX];
 
ll fun(ll val)
{
	forr(i, 1, n){
		temp[i] = inp[i];
	}
	map<ll, ll> mp;
	ll ret = 0;
	
	forr(i, 1, n){
		mp[temp[i]]++;
		if(mp[val] >= k){
			return 0LL;
		}
	}
	//mp.clear();
	int flag = 0;
	forr(i, 1, n){
		
		int cnt  = 0;
		while(temp[i] > val){
			temp[i]/= 2LL;
			cnt++;
	
		}
		if(temp[i] == val){
			flag++;
			ret += cnt;
		}
		
		if(flag == k){
			return ret;
			break;
		}
		
	}
	
	return -1;
}
 
int main() {
    __FastIO;   //Be aware to use it!
    
    cin >> n >> k;
    
    forr(i, 1, n){
		cin >> inp[i];
		//ara[i] = inp[i];
	}
	
	sort(inp + 1, inp + n + 1);
 
	
	forr(i, 1, n){
		ara[i] = inp[i];
	}
	
	map<ll, ll> mp;
vll v;
	forr(i, 1, n){
		while(ara[i] >= 0LL){
				v.pb(ara[i]);
				mp[ara[i]]++;
				if(ara[i] == 0){
					break;
				}
				ara[i] /= 2;
		}
	}
	ll ans = INF;
	
	rep(i, v.size()){
		if(mp[v[i]] >= k){
			ans = min(ans, fun(v[i]));
			
		}
	}
	
	cout << ans << endl;
	
    return 0;
}
