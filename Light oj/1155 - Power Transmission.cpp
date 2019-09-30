
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

	#define fill(ar)          memset(ar, -1, sizeof(ar))
	#define clr(a)          memset(a, 0, sizeof(a))

	#define nl              cout << '\n';
	#define sp              cout << ' ';
	#define ckk             cout << "##########\n"

	#define pb              push_back
	#define MP              make_pair

	#define debug1(x)       cerr << #x << ": " << x << endl
	#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
	#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

	#define gama 0.57721566490
	#define PI              acos(-1.0)
	#define INF             1000000
	#define MOD             1000000007
	#define EPS             1e-7
	#define MAX             215

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
	/*int N;
	vi adj[MAX];
	int cost[MAX][MAX], cap[MAX], parent[MAX];

	void bfs(int s, int t)
	{
		fill(parent);
		parent[s] = -2;

		queue<int> q;
		q.push(s);

	    rep(i, adj[s].size()){
			q.push({adj[s][i], cost[s][adj[s][i]]});
		}
		while(!q.empty()){
			int cur = q.front();
			
			q.pop();
					rep(i, adj[cur].size()){
				int nxt = adj[cur][i];

				if(parent[nxt] == -1 && cost[cur][nxt] > 0){
					parent[nxt] = cur;
				
					if(nxt == t){
						return ;
					}
					q.push(nxt);
				}
			}
		}
	
	}

	int max_flow(int s, int t)
	{
		int flow = 0;
		
		int new_flow;

		while(1){
			//flow += new_flow;
			new_flow = INF;
			
			bfs(s,t);
			int cur = t;

			while(parent[cur] > -1){
				int prev = parent[cur];
				new_flow = min(new_flow, cost[prev][cur]);
				cur = prev;
			}
			
			if(new_flow >= INF){
				new_flow = 0;
			}
			if(new_flow == 0){
				break;
			}
			
			flow += new_flow;
			 cur = t;

			while(parent[cur] > -1){
				int prev = parent[cur];
				cost[prev][cur] -= new_flow;
				cost[cur][prev] += new_flow;
				cur = prev;
			}
		}
		return flow;
	}
*/

int source, sink,par[MAX], c[MAX][MAX], N;
bool vis[MAX];

int BFS()
{
    int pathcap, tot, i, cur, now;

    queue<int> q;
    pathcap = INF;
    memset(vis, false, sizeof(vis));
    memset(par, -1, sizeof(par));

    vis[source] = true;
    q.push(source);
    tot = 2*N + 3;
    while(!q.empty())
    {
        cur = q.front(); q.pop();
        if(cur== sink) break;

        for(i = 1; i <tot; i++){
            if(vis[i] || c[cur][i]<= 0) continue;
            par[i] = cur;
            vis[i] = true;
            q.push(i);
        }
    }
    int prv;

    now = sink;
    while(par[now] > -1){
        prv = par[now];
        pathcap = min(pathcap, c[prv][now]);
        now = prv;
    }

    now = sink;
    while(par[now] > -1){
        prv = par[now];
        c[prv][now] -= pathcap;
        c[now][prv] += pathcap;
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
        if(flow == 0) break;
        ans+= flow;
    }

    return ans;
}

	int main() {
		//__FastIO;   //Be aware to use it!

		int test,u, v, w, M, k;
		scanf("%d", &test);

		forr(tc, 1, test){
			scanf("%d", &N);
			clr(c);

			forr(i, 1, N){
				scanf("%d", &k);
				//adj[i].pb(i + N);
				c[i][i + N] = k;
			}


			scanf("%d", &M);

			forr(i , 1, M){
					scanf("%d %d %d", &u, &v, &w);
						//adj[u + N].pb(v);
						c[u + N][v] = w;
				   }
				   

			int B, D;

			scanf("%d %d", &B, &D);


			forr(i, 1, B){
				scanf("%d", &k);
				//adj[2*N + 1].pb(k);
				c[2*N + 1][k] = INF;
			}


			forr(i, 1, D){
				scanf("%d", &k);
				//adj[k + N].pb(N*2 + 2);
				c[k + N][N*2 + 2] = INF;
			}
			
			source = 2*N + 1;
			sink = 2*N + 2;
			int ans = max_flow();

			printf("Case %d: %d\n",tc, ans);

/*			forr(i, 0, 2*N + 5){
				adj[i].clear();
			}*/
		}

		return 0;
	}
/*
 13
1 45 74 35 19 66 13 82 57 69 2 92 54
37
11 8 43
2 3 47
2 11 47
4 12 80
6 9 51
4 11 72
8 7 46
3 9 13
9 12 22
12 1 66
8 5 54
10 8 39
7 9 7
5 13 30
3 5 50
2 13 93
11 9 92
1 6 57
9 4 31
4 3 3
5 12 94
13 12 33
2 4 16
1 12 8
1 4 65
11 7 96
8 13 45
10 7 49
10 11 92
3 10 94
4 6 95
9 1 50
1 3 38
8 6 96
7 2 87
8 9 63
8 12 19
5 8
4 13 8 10 1 6 5 12 2 9 7 3 11

output : 166
*/
