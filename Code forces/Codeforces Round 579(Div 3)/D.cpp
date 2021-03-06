/*
 * FILE: D.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 13.08.2019 20:25:32 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 13-08-2019	1.0         File Created
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
 string s, p;
 int n, m;
 
 bool isSub(string test){
	 int cnt = 0;
	 
	 rep(i, test.size()){
		 if(test[i] == p[cnt]){
			 cnt++;
		 }
		 if(cnt == m){
			 return true;
		 }
	 }
	 return false;
 }
 
int main() {
    __FastIO;   //Be aware to use it!
    
   
    
    cin >> s >> p;
     n = (int)s.size(), m = (int)p.size();
    /*
    int ans = 0;
    rep(i, n){
		if(s[i] == p[0]){
			int l = i, itr = i, cnt = 0, prev = i, prevmx = 0;
			
			while(itr < n){
				if(s[itr] == p[cnt]){
					cnt++;
					prevmx = max(prevmx, itr- prev - 1);
					prev = itr;
				}
				if(cnt == m){
					break;
				}
				itr++;
			}
			if(cnt == m){
				ans = max(ans, max(l, max(prevmx, n - itr - 1)));
			}
			//debug3(l, prevmx, n - itr - 1);
			
		}
	}
	
	
	for(int i = n - 1; i >= 0; i--){
		if(s[i] == p[m - 1]){
			int l = n - i - 1, itr = i, cnt = m - 1, prev = i, prevmx = 0;
			
			while(itr >= 0){
				if(s[itr] == p[cnt]){
					cnt--;
					prevmx = max(prevmx, abs(itr- prev) - 1);
					prev = itr;
				}
				if(cnt == -1){
					break;
				}
				itr--;
			}
			if(cnt == -1){
				ans = max(ans, max(l, max(prevmx, itr)));
			}
			//debug3(l, prevmx, n - itr - 1);
			
		}
	}
	*/
	
	string temp;
	int ans = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = i ; j < n; j++){
			temp.clear();
			for(int k = 0; k < n; k++){
				if(k < i || k > j){
					temp.pb(s[k]);
				}
			}
			if(isSub(temp)){
				//debug3(temp, i, j);
					ans = max(ans, (j - i + 1));
				}
		}
	}
	
	cout << ans << endl;
    return 0;
}
