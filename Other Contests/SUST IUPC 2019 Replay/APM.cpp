/*
 * FILE: APM.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 05.05.2019 21:38:31 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 05-05-2019	1.0         File Created
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
#define MAX             105

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

int flag = 1;
map<string, int> ID, VID;
map<int, int> PID, cnts;

vi gr[MAX];
int vis[MAX];

void dfs(int node)
{
	vis[node] = 1;
	cnts[PID[node]]++;
	if(cnts[PID[node]] > 1){
		flag = 0;
	}
	for(int i = 0; i < (int)gr[node].size(); i++){
		if(vis[gr[node][i]] == 0)
		dfs(gr[node][i]);
	}
	
}

pair<string,string> sep(string ss)
{
	string s1, s2;
	
	int i = 0;
	
	for(i = 0; i < (int)ss.size(); i++){
		if(ss[i] == ':'){
			i++;
			break;
		}
		s1.pb(ss[i]);
	}
	
	for(;i<(int)ss.size(); i++){
		s2.pb(ss[i]);
	}
	return {s1,s2};
}

int main() {
    __FastIO;   //Be aware to use it!
    
    
    vector<pair<string, string> > vp;
    pair<string, string> temp;
    
    int n = 0, test, cnt = 0;
    
    string s, st[105];
    cin >> test ;
    
    forr(tc, 1, test){
		cin >> s;
    
    temp = sep(s);
    
    int m;
    flag = 1;
    clr(vis);
    
    cin >> m;
    
    rep(i, m){
		cin >> st[i];
		if(ID.find(st[i]) == ID.end()){
			flag = 0;
			break;
		}
	}
	cnts.clear();
	
	if(flag){
		rep(i, m){
			dfs(ID[st[i]]);
		}
	}
	
	if(flag){
		cout << "Request " << tc << ": OK" << endl;
		ID[s] = ++n;
		if(VID.find(temp.first) == VID.end())
		VID[temp.first] = ++cnt;
		
		PID[n] = VID[temp.first];
		
		vp.pb(temp);
		
		sort(all(vp));
		
		rep(i, m){
			gr[n].pb(ID[st[i]]);
			gr[ID[st[i]]].pb(n);
		}
		
		rep(i,vp.size()){
			cout <<vp[i].first <<  ":" << vp[i].second << endl;
		}
		
	}else{
		
		cout << "Request " << tc << ": ERROR" << endl;
	}
	
}
    
    return 0;
}
