/*
 * FILE: 1184 - Marriage Media.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 03.09.2019 15:31:21 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 03-09-2019	1.0         File Created
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
#define MAX             205

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
 
int source, sink,par[MAX],vis[MAX], c[MAX][MAX], tot;
 
 
int BFS()
{
    int pathcap, i, cur, now;
 
    queue<int> q;
    pathcap = INF;
    memset(vis, false, sizeof(vis));
    memset(par, -1, sizeof(par));
 
 
    q.push(source);
 
    while(!q.empty())
    {
 
        cur = q.front(); q.pop();
    //    debug2(cur, tot);
        if(cur== sink) break;
 
        for(i = 1; i < tot; i++){
          // debug3(cur, i, c[cur][i]);
            if(c[cur][i]<= 0 || vis[i]) continue;
            par[i] = cur;
            vis[i] = true;
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
        pathcap = min(pathcap, c[prv][now]);
        now = prv;
    }
 
    now = sink;
    while(par[now] > -1){
        prv = par[now];
        if(now == source){
            break;
        }
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
       // debug1(flow);
        if(flow == 0) break;
        ans+= flow;
    }
 
    return ans;
}
 
struct st{
	int age, hgt, div;
};

st man[55], woman[55];

    int main() {
        //__FastIO;   //Be aware to use it!
 
        int test, m , w;
        scanf("%d", &test);
        
 
        forr(tc, 1, test){
            clr(c);
            scanf("%d %d", &m, &w);
            
 
            forr(i, 1, m){
				scanf("%d %d %d", &man[i].hgt, &man[i].age, &man[i].div);
			}
			
			
			
			forr(i, 1, w){
				scanf("%d %d %d", &woman[i].hgt, &woman[i].age, &woman[i].div);
			}
			
			forr(i, 1, m){
				
				forr(j, 1, w){
					if(man[i].div == woman[j].div){
						if(abs(woman[j].age - man[i].age) <= 5 && abs(man[i].hgt - woman[j].hgt) <= 12){
							c[i][m+j] = INF;
						}
					}
						
				}
			}
			
            for(int i = 1; i <= m; i++){
                c[m + w + 1][i] = 1;
       //         debug2(N*6+M + 1, i);
            }
 
            for(int i = 1; i <= w; i++){
                c[i + m][m + w + 2] = 1;
              //  debug2(i, N*6+M + 2);
            }
 
            source = m +w + 1;
            sink = m + w + 2;
            //debug2(N,M);
            tot = m + w + 3;
 
            int ans = max_flow();
        //  debug1(ans);
 
            printf("Case %d: %d\n",tc, ans);
        }
 
        return 0;
    }
