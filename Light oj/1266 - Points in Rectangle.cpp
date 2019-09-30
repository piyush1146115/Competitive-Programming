/*
 * FILE: 1266 - Points in Rectangle.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 18.09.2019 01:16:16 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 18-09-2019	1.0         File Created
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
typedef vector< vi >        vvi;
typedef vector<long long>   vll;


#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define tr(i,c) 		for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define all(ar)         ar.begin(), ar.end()

#define present(c,x) ((c).find(x) != (c).end()) // for map/set
#define cpresent(c,x) (find(all(c),x) != (c).end()) // for vectors


#define fill(ar)   		memset(ar, -1, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"

#define pb              push_back
#define MP 				make_pair
#define sz(a)           int((a).size())


#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define gama 0.57721566490
#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             1005

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
int ara[MAX][MAX], BIT[MAX][MAX];



int query(int x,int y)
{
    int ret=0;
    if(x<0 || y<0)return 0;
    for(int i=x; i>=0; i=(i&(i+1))-1)
        for(int j=y; j>=0; j=(j&(j+1))-1)
            ret+=BIT[i][j];
    return ret;
}

void update(int x,int y,int val)
{
    for (int i = x; i <=1000; i = i | (i+1))
            for (int j = y; j <=1000 ; j = j | (j+1))
                BIT[i][j] += val;
}

int sum(int x1, int y1, int x2, int y2)
{
	return (query(x2,y2) - query(x1- 1, y2) - query(x2, y1 -1) + query(x1 - 1, y1 - 1));
}

int main() {
    //__FastIO;   //Be aware to use it!
    
    
    int test;
    scanf("%d", &test);
    
    forr(tc, 1, test){
		clr(ara);
		clr(BIT);
		
		int q, type, x1, y1, x2, y2;
		
		scanf("%d", &q);
		printf("Case %d:\n",tc);
		
		while(q--){
			scanf("%d", &type);
			
			if(type == 0){
				scanf("%d %d", &x1, &y1);
				if(ara[x1][y1] == 0){
					ara[x1][y1]  = 1;
					update(x1, y1, 1);
				}
			}
			else{
				scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
				int ans = sum(x1,y1, x2, y2);
				printf("%d\n",ans);
			}
		}
	}
    
    return 0;
}
