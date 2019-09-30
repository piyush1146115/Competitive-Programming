/*
 * FILE: 339C.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 07.07.2019 12:03:19 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 07-07-2019	1.0         File Created
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
int m, n;
vi v;
int DP[45][15][1005];

int fun(int bal, int prev, int it)
{
//	debug3(bal, prev, it);
//	getchar();
	if(it == m){
		return 1;
	}
	if(bal > 9 || bal < -9){
		//ckk;
		return 0;
	}
	
	if(DP[bal + 25][prev][it] != -1){
		return DP[bal + 25][prev][it];
	}
	
	int ret = 0;
	if(it % 2 == 0){
		rep(i, n){
			if(v[i] != prev && bal + v[i] > 0){
				ret |= fun(bal + v[i], v[i], it+1);
			}
		}
	}else{
		rep(i, n){
			if(v[i] != prev && (bal - v[i]) < 0){
				ret |= fun(bal - v[i], v[i], it + 1);
			}
		}
	}
	
	 DP[bal + 25][prev][it] = ret;
	 return ret;
}

void path(int bal, int prev, int it)
{
	if(it == m){
		return;
	}
	
	if(it % 2 == 0){
		rep(i, n){
			if(v[i] != prev && bal + v[i] > 0){
				if(fun(bal + v[i], v[i], it+1)){
					cout << v[i] << " ";
					path(bal + v[i], v[i], it + 1);
					break;
				}
			}
		}
	}else{
		rep(i, n){
			if(v[i] != prev && (bal - v[i]) < 0){
				if(fun(bal - v[i], v[i], it + 1)){
					cout << v[i] << " ";
					path(bal -v[i], v[i], it+1);
					break;
				}
			}
		}
	}
	return;
}

int main() {
    __FastIO;   //Be aware to use it!
    /*
    int m, n = 0;
    string s;
    cin >> s >> m;
    priority_queue<int> Q;
    vi v;
    rep(i, 10){
		if(s[i] == '1'){
			Q.push(i + 1);
			v.pb(i + 1);
			n++;
		}
	}
	
    vi ans;
    int sum1 = 0, sum2 = 0, global = 1, local, last = 0;
    forr(it, 1, m){
	//	debug3(it,sum1, sum2);
		local = 0;
		if(it % 2 == 1){
			while(!Q.empty()){
				int t = Q.top();
				Q.pop();
				debug2(it, t);
				if(sum1 + t > sum2 && last != t){
					local = 1;
				//	ckk;
					last = t;
					sum1 += t;
					ans.pb(t);
				//	Q.push(t);
					break;
				}
			}
		}
		else{
			while(!Q.empty()){
				int t = Q.top();
				Q.pop();
				if(sum2 + t > sum1 && last != t){
					last = t;
					sum2 += t;
					ans.pb(t);
				//	Q.push(t);
					local =1;
					break;
				}
				
			}
		}
		if(local == 0){
			global = 0;
			break;
		}
		rep(i, n){
			Q.push(v[i]);
		}
		debug3(it, sum1, sum2);
	}
	
	if(global){
		cout << "YES" << endl;
		rep(i, ans.size()){
			cout << ans[i] << " ";
		}
		cout << endl;
	}else{
		cout << "NO" << endl;
	}
	*/
	
	fill(DP);
	n = 0;
	string s;
	cin >> s >> m;
	
	rep(i, 10){
		if(s[i] == '1'){
			v.pb(i + 1);
			n++;
		}
	}
	
	int yes = fun(0, 0, 0);
	
	if(yes){
		cout << "YES" << endl;
		path(0, 0 , 0);
		cout << endl;
	}else{
		cout << "NO" << endl;
	}
	
    return 0;
}
