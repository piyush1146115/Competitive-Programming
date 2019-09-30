/*
 * FILE: P - Test.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 19.08.2019 22:34:11 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 19-08-2019	1.0         File Created
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


int failure[3* MAX];


int calc(string a, string b)
{
	string test;
	int m = (int)b.length(), temp = 0;
	test = b + "$" + a;
	int len = (int)test.length();
	
	failure[0] = failure[1] = 0;
	
	for(int i = 2; i <= len; i++){
		int j = failure[i - 1];
		
		while(true){
			if(test[j] == test[i - 1]){
				failure[i] = j + 1;
				break; 
			}
			if(j == 0){
				failure[i] = 0;
				break;
			}
			j = failure[j];
		}
		if(i >=m ){
			temp = max(temp, failure[i]);
		}
	
	}
	if(temp >= m){
		return m;
	}
	
	return failure[len];
	
}

bool isSub(string a, string b)
{
	string test;
	int m = (int)b.length();
	test = b + "$" + a;
	int len = (int)test.length();
	
	failure[0] = failure[1] = 0;
	
	for(int i = 2; i <= len; i++){
		int j = failure[i - 1];
		
		while(true){
			if(test[j] == test[i - 1]){
				failure[i] = j + 1;
				break; 
			}
			if(j == 0){
				failure[i] = 0;
				break;
			}
			j = failure[j];
		}
		if(failure[i] >= m){
			return true;
		}
	}
	return false;
}

int kmp(string a, string b, string c)
{
	
	string test;
	int m = (int)a.length();
	int n = (int)b.length();
	int p = (int)c.length();
	
	
	
	test = c + "$" + b;
	int len = (int)test.length();
	int dec = 0, temp = 0;
	failure[0] = failure[1] = 0;
	
	for(int i = 2; i <= len; i++){
		int j = failure[i - 1];
		
		while(true){
			if(test[j] == test[i - 1]){
				failure[i] = j + 1;
				break; 
			}
			if(j == 0){
				failure[i] = 0;
				break;
			}
			j = failure[j];
		}
		if(i > p)
		temp = max(temp, failure[i]);
	}
	
	
	if(temp >= p){
		dec = p;
		dec += max(calc(b, a), calc(a, b));
		return (m+n+p - dec);
	}
	else{
		dec = failure[len];
	}
	
	test = b + "$" + a;
	len = (int)test.length();
	 temp = 0;
	
	failure[0] = failure[1] = 0;
	
	for(int i = 2; i <= len; i++){
		int j = failure[i - 1];
		
		while(true){
			if(test[j] == test[i - 1]){
				failure[i] = j + 1;
				break; 
			}
			if(j == 0){
				failure[i] = 0;
				break;
			}
			j = failure[j];
		}
		if(i > n)
		temp = max(temp, failure[i]);
	}
	
	if(temp >= n){
		dec = temp;
		dec += max(calc(c, a), calc(a, c));
		return (m+n+p - dec);
	}
	else{
		dec += failure[len];
	}
	//dec += temp;
	//debug3(a, b, c);
	//debug2(m+n+p, dec);
	//getchar();
	return (m+n+p - dec);
}

int main() {
    __FastIO;   //Be aware to use it!
    
    string a, b, c;
    
    while(cin >> a >> b >> c){
		int ans = INF;
		
		
		if(isSub(a, b) && isSub(a, c)){
		ans = min(ans, (int)a.length());
	}
	
	if(isSub(b, a) && isSub(b, c)){
		ans = min(ans, (int)b.length());
	}
	
	if(isSub(c, b) && isSub(c, a)){
		ans = min(ans, (int)c.length());
	}
		ans = min(ans, kmp(a, b, c));
		ans = min(ans, kmp(a, c, b));
		ans = min(ans, kmp(b, a, c));
		ans = min(ans, kmp(b, c, a));
		ans = min(ans, kmp(c, a, b));
		ans = min(ans, kmp(c, b, a));
		
		cout << ans << endl;
	}
    return 0;
}

/*
abacdb
ac
db
* 
abacdtx
ac
db
*
abacdtd
ac
db
*/
