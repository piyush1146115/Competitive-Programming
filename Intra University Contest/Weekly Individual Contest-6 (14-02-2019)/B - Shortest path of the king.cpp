/*
 * FILE: B - Shortest path of the king.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 14.02.2019 21:28:19 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 14-02-2019	1.0         File Created
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
#define ff 	 			first
#define ss 	 			second

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
pii S, T;

int dis[10][10], fin[10][10];

int dx[] = {+0, +1, -1, +1, -1, +0, -1, +1};
int dy[] = {+1, + 1, +1, +0, +0, -1, -1, -1};



bool isValid(int x, int y)
{
	if(x >= 0 && y >= 0 && x <= 8 && y <= 8 && dis[x][y] == -1){
		return true;
	}
	return false;
}

void BFS(pii p)
{
	queue<pii> q;
	dis[p.ff][p.ss] = 0;
	q.push(p);
	
	while(!q.empty())
	{
		pii temp = q.front();
		q.pop();
		
		for(int i = 0; i < 8; i++){
			int xx = temp.ff + dx[i];
			int yy = temp.ss + dy[i];
			
			if(isValid(xx, yy)){
				dis[xx][yy] = dis[temp.ff][temp.ss] + 1;
				q.push(MP(xx, yy));
			}
		}
		
	}
	
	fin[p.ff][p.ss] = dis[T.ff][T.ss];
}



int main() {
   // __FastIO;   //Be aware to use it!
	
	
vector<string> dir;
dir.pb("R");
dir.pb("RU");
dir.pb("RD");
dir.pb("U");
dir.pb("D");
dir.pb("L");
dir.pb("LD");
dir.pb("LU");

	string s;
	cin >> s;
	
	S = MP((int)(s[1] - '0'), (int)(s[0] - 'a' + 1));
	
	cin >> s;
	T = MP((int)(s[1] - '0'), (int)(s[0] - 'a' + 1));
    
    for(int i = 0; i <= 8; i++){
		for(int j = 0; j <= 8; j++){
			BFS(MP(i,j));
			fill(dis);
		}
	}
	
	cout << fin[S.ff][S.ss] << endl;
	
	pii temp = S;
	int req = fin[S.ff][S.ss];
	
	vector<string> ans;
	while(req){
	for(int i = 0; i < 8; i++){
			int xx = temp.ff + dx[i];
			int yy = temp.ss + dy[i];
			
			if(isValid(xx, yy)){
				if(fin[xx][yy] == req - 1){
					ans.pb(dir[i]);
					temp= MP(xx, yy);
					req--;
					break;
				}
			}
		}
	}
	
	rep(i, ans.size()){
		cout << ans[i] << endl;
	}
	
    return 0;
}
