/*
 * FILE: 1364 - Expected Cards.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 07.09.2019 03:03:35 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 07-09-2019	1.0         File Created
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

double min(double a,double b)
{
    if(a-b>EPS) return b;
    else return a;
}

double dp[15][15][15][15][5][5];
int cnt[5];//对应4种花色的牌的数量
int A,B,C,D;

double dfs(int a,int b,int c,int d,int e,int f){
    if(a>13||b>13||c>13||d>13) return 0;
    cnt[1]=a;
    cnt[2]=b;
    cnt[3]=c;
    cnt[4]=d;
    if(e) cnt[e]++;
    if(f) cnt[f]++;
    if(cnt[1]>=A&&cnt[2]>=B&&cnt[3]>=C&&cnt[4]>=D) return dp[a][b][c][d][e][f]=0;
    if(dp[a][b][c][d][e][f]>-1) return dp[a][b][c][d][e][f];

    double ans=0;
    int num=54-cnt[1]-cnt[2]-cnt[3]-cnt[4];
    if(num==0) return 0;

    if(e==0)
    {
        double tmp=60;
        for(int i=1;i<=4;i++)
        tmp=min(tmp,dfs(a,b,c,d,i,f));
        ans+=tmp/num;
    }
    if(f==0)
    {
        double tmp=60;
        for(int i=1;i<=4;i++)
        tmp=min(tmp,dfs(a,b,c,d,e,i));
        ans+=tmp/num;
    }
    ans+=dfs(a+1,b,c,d,e,f)*(13-a)/num; 
    ans+=dfs(a,b+1,c,d,e,f)*(13-b)/num; 
    ans+=dfs(a,b,c+1,d,e,f)*(13-c)/num; 
    ans+=dfs(a,b,c,d+1,e,f)*(13-d)/num;

    return dp[a][b][c][d][e][f]=ans+1;
} 

void init()
{
    for(int a=0;a<=13;a++)
    for(int b=0;b<=13;b++)
    for(int c=0;c<=13;c++)
    for(int d=0;d<=13;d++)
    for(int e=0;e<=4;e++)
    for(int f=0;f<=4;f++)
    dp[a][b][c][d][e][f]=-1;
}

int main() 
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        init();
        scanf("%d%d%d%d",&A,&B,&C,&D);
        int f=0;
        if(A-13>0) f+=A-13;
        if(B-13>0) f+=B-13;
        if(C-13>0) f+=C-13;
        if(D-13>0) f+=D-13;
        if(f>2)
        {
            printf("Case %d: -1\n",cas);
            continue;
        }
        
        dfs(0,0,0,0,0,0);
        printf("Case %d: %.7lf\n",cas,dp[0][0][0][0][0][0]);
    }
    return 0;
}
