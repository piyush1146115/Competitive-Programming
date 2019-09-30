/*
 * FILE: 1150 - Ghosts!.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 10.09.2019 10:48:33 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 10-09-2019	1.0         File Created
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
string s[30];
int n, grid[30][30],dis[30][30], vis[30][30], D[MAX][MAX];
int total, cost[MAX][MAX], source, sink;


bool valid(int x, int y)
{
	if(x < n && y < n && y >= 0 && x >= 0 && grid[x][y] != -1 && vis[x][y] == 0){
		return true;
	}
	
		return false;
	
}


void bfs(int num, int sx, int sy)
{
	queue<pii> q;
	q.push({sx, sy});
	vis[sx][sy] = 1;
	dis[sx][sy] = 0;
	
	int x, y, xx, yy;
	
	while(!q.empty()){
		pii p = q.front();
		q.pop();
		 x = p.first;
		  y = p. second;
		
		xx = x + 1;
		yy = y;
		if(valid(xx, yy)){
			q.push({xx, yy});
			dis[xx][yy] = dis[x][y] + 1;
			vis[xx][yy] = 1;
			if(grid[xx][yy] > 0){
				D[num][grid[xx][yy]] = dis[xx][yy]*2 + 2; 
			}
		}
		
		xx = x - 1;
		yy = y;
		
		if(valid(xx, yy)){
			q.push({xx, yy});
			dis[xx][yy] = dis[x][y] + 1;
			vis[xx][yy] = 1;
			if(grid[xx][yy] > 0){
				D[num][grid[xx][yy]] = dis[xx][yy]*2 + 2; 
			}
		}
		
		xx = x;
		yy = y - 1;
		
		if(valid(xx, yy)){
			q.push({xx, yy});
			dis[xx][yy] = dis[x][y] + 1;
			vis[xx][yy] = 1;
			if(grid[xx][yy] > 0){
				D[num][grid[xx][yy]] = dis[xx][yy]*2 + 2; 
			}
		}
		
		xx = x;
		yy = y + 1;
		
		if(valid(xx, yy)){
			q.push({xx, yy});
			dis[xx][yy] = dis[x][y] + 1;
			vis[xx][yy] = 1;
			if(grid[xx][yy] > 0){
				D[num][grid[xx][yy]] = dis[xx][yy]*2 + 2; 
			}
		} 
	}
}

int visit[MAX], par[MAX];

int BFS()
{
    int pathcap, i, cur, now;
 
    queue<int> q;
    pathcap = INF;
    memset(visit, false, sizeof(visit));
    memset(par, -1, sizeof(par));
 
 
    q.push(source);
 //   tot = 6*N + M +  3;
 //   debug3(N, M, tot);
    while(!q.empty())
    {
 
        cur = q.front(); q.pop();
        //debug2(source, cur);
        if(cur== sink) break;
 
        for(i = 1; i < total ; i++){
           //debug3(cur, i, cost[cur][i]);
            if(cost[cur][i]<= 0 || visit[i]) continue;
            par[i] = cur;
            visit[i] = true;
       //     debug3(cur, i, par[i]);
            q.push(i);
        }
    }
 
    int prv;
 
    now = sink;
    while(par[now] > -1){
        prv = par[now];
      //  debug2(now, prv);
      //  getchar();
        if(now == source){
            break;
        }
        pathcap = min(pathcap, cost[prv][now]);
        now = prv;
    }
 
    now = sink;
    while(par[now] > -1){
        prv = par[now];
        if(now == source){
            break;
        }
        cost[prv][now] -= pathcap;
        cost[now][prv] += pathcap;
        now = prv;
    }
 
    if(pathcap== INF) pathcap = 0;
 
    return pathcap;
}


int max_flow()
{
    int ans,flow;
    ans = 0;
 
    while(1){
        flow = BFS();
       // debug1(flow);
        if(flow == 0) break;
        ans+= flow;
    }
    return ans;
}


int main()
{
	int test;
	scanf("%d", &test);
	
	forr(tc, 1, test){
		scanf("%d", &n);
		clr(grid);
		clr(D);
		
		rep(i, n){
			cin >> s[i];
		}
		
		int h = 0, g = 0;
		
		rep(i, n){
			rep(j, n){
				if(s[i][j] == 'H'){
					h++;
					grid[i][j] = h;
				}
				if(s[i][j] == '#'){
					grid[i][j] = -1;
				}
			}
		}
		
		
		rep(i, n){
			rep(j, n){
				if(s[i][j] == 'G'){
					g++;
					clr(vis);
					bfs(g+h, i, j);
				}
			}
		}
		
		
		int lo = 0, hi = n*n*n, mid;
		
		int ans = -1;
		
		source = 0;
		sink = g + h + 1;
		total = g +h + 2;
		
		
		while(lo <= hi){
			mid = (lo + hi)/2;
			clr(cost);
		
			forr(i, 1, g){
				cost[0][i + h] = 1;
				forr(j, 1, h){
					if(D[i + h][j] <= mid && D[i+h][j] > 0){
						cost[i + h][j] = 1;
						//debug2(i+h, j);
					}
					cost[j][g+h+1] = 1;
				}
			}
			
			int flow = max_flow();
			if(flow == h){
				hi = mid - 1;
				ans = mid;
			}
			else{
				lo = mid + 1;
			}
			
		//	debug2(mid, flow);
			
		}
		
		
		if(ans == - 1){
			printf("Case %d: Vuter Dol Kupokat\n",tc);
		}
		else{
			printf("Case %d: %d\n",tc, ans);
		}
		
	}
	
	return 0;
}
