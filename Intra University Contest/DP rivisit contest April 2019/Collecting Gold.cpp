/*
 * FILE: Collecting Gold.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 16.04.2019 00:37:29 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 16-04-2019	1.0         File Created
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

int m, n, cnt;
string grid[25];
bool vis[25][25];
map< pii, int> mp;
int dis[20][20];
struct st{
	int u, v, cost;
	st(int _u, int _v, int _cost){
		u = _u;
		v = _v;
		cost = _cost;
	}
};

int DP[18][33000];

int dx[] = {-1, -1, -1, 0, 0, +1, +1, +1};
int dy[] = {-1, 0, +1, -1, +1, -1, 0, +1};


int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

bool valid(int x, int y) {
    if (x >= 0 && y >= 0 && x < m && y < n && vis[x][y] == 0) {
        return true;
    }
    return false;
}


void BFS(int from, int sx, int sy)
{
	//debug3(from, sx, sy);
	queue< st > Q;
	Q.push({sx, sy,0});
	vis[sx][sy] = 1;
	st t({0,0,0});
	int x, y, xx, yy, d, dd;
	while(!Q.empty()){
		t = Q.front();
		Q.pop();
		x = t.u;
		y = t.v;
		d = t.cost;
		
		rep(i, 8){
			xx = x + dx[i];
			yy = y + dy[i];
			if(valid(xx, yy)){
				dd = d + 1;
				if(grid[xx][yy] == 'g' || grid[xx][yy] == 'x'){
					dis[from][mp[{xx,yy}]] = dd;
				}
				vis[xx][yy] = 1;
					//debug3(from, xx, yy);
					//debug1(dd);
					
					Q.push({xx,yy,dd});
			} 
		}
	}
}


int fun(int from, int mask)
{
	if(mask == ((1 << cnt)-1)){
		return dis[from][0];
	}
	if(DP[from][mask] != -1){
		return DP[from][mask];
	}
	int ret = INF;
	rep(i, cnt){
		if(check(mask, i) == 0){
			ret = min(ret, dis[from][i+1] + fun(i+1, Set(mask,i)));
		}
	}
	return DP[from][mask] = ret;
}

int main() {
    // __FastIO;   //Be aware to use it!

    int test;
    scanf("%d", &test);

    forr(tc, 1, test) {
        scanf("%d %d", &m, &n);
        mp.clear();
        fill(DP);
        rep(i, m) {
            cin >> grid[i];
        }
         cnt = 0;
        rep(i, m) {
            rep(j, n) {
                if (grid[i][j] == 'x') {
                    mp[ {i, j}] = 0;
                }
                if (grid[i][j] == 'g') {
                    mp[ {i, j}] = ++cnt;
                }
            }
        }
        
       rep(i, m){
		   rep(j, n){
			   if(grid[i][j] == 'g' || grid[i][j] == 'x'){
				   clr(vis);
				   BFS(mp[{i,j}], i, j);
			   }
		   }
	   }
	   
	   int ans = fun(0, 0);
	   //debug1(cnt);
	   
	   /*rep(i, cnt+1){
		   rep(j, cnt+1){
			   debug3(i, j, dis[i][j]);
		   }
	   }*/
	   printf("Case %d: %d\n",tc, ans);
    }
    return 0;
}
