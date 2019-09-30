/*
 * FILE: K - Beautiful Lyrics .cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 04.07.2019 03:42:38 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 04-07-2019	1.0         File Created
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
typedef vector<pii >         vpii;
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

vector<pair<string, string> >vs[MAX];


int main() {
    __FastIO;   //Be aware to use it!
    
    int n;
    cin >> n;

    string s, t;
    rep(i, n){
		cin >> s;
		t = "";
		int cnt = 0;
		rep(j, s.size()){
			char ch = s[j];
			if(ch == 'a' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'e'){
				t += ch;
				cnt++;
			}
		}
		reverse(all(t));
		vs[cnt].pb({t,s});
		//debug2(cnt, t);
	}
	vector<string> vs1, vs2;
	
	int type1 = 0, type2 = 0;
	
	forr(i, 1, 1000000){
		if((int)vs[i].size() > 0){
			sort(all(vs[i]));
			int chk = 0;
			
			for(int j = 1; j < (int)vs[i].size(); j++){
				//debug2(vs[i][j], vs[i][j -1]);
				if(j == (int)(vs[i].size()-1)){
					chk = 1;
				}
				if(vs[i][j].first[0] == vs[i][ j -1].first[0]){
					vs1.pb(vs[i][j].second);
					vs1.pb(vs[i][j - 1].second);
					j++;
				}else{
					if(j == (int)vs[i].size() -1 ){
						vs2.pb(vs[i][j].second);
					}
					vs2.pb(vs[i][j - 1].second);
				}
			}
			if(!chk){
				vs2.pb(vs[i][(int)vs[i].size() - 1].second);
			}
			
			if((int)vs1.size()%2 != 0){
				vs1.pop_back();
			}
			if((int)vs2.size()%2 != 0){
				vs2.pop_back();
			}
		
		}
	}
	
	type1 = (int)vs1.size();
	type2 = (int)vs2.size();
//	debug2(type1, type2);
	if(type1 > type2){
		int ans = (type2/2) + (type1 - type2)/4;
		cout << ans << endl;
		for(int i = 0;i < type2; i += 2){
			cout << vs2[i] << " " <<  vs1[i] << endl;
			cout << vs2[i + 1] << " " << vs1[i + 1] << endl;
		}
		for(int i = type2; i+ 3 < type1; i+= 4){
			cout <<vs1[i] << " " << vs1[i + 2] << endl;
			cout << vs1[i + 1] << " " << vs1[i + 3] << endl;
		}
	}else{
		cout << type1/2 << endl;
		for(int i = 0;i < type1; i += 2){
			cout << vs2[i] << " " <<  vs1[i] << endl;
			cout << vs2[i + 1] << " " << vs1[i + 1] << endl;
		}
	}
	
    return 0;
}
