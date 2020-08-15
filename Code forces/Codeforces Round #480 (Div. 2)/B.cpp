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
#define ff              first
#define ss              second

#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define gama 0.57721566490
#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             105

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
int n, k;
string s[10];
int dis[10][MAX];
int dis2[10][MAX];
int vis[10][MAX];

int fx[] = {0, -1, 0, +1};
int fy[] = {+1, 0, -1, 0};

bool valid(int x, int y)
{
    if(x >= 0 && x < 4 && y >= 0 && y < n && vis[x][y] == 0)
    {
        return true;
    }
    return false;
}

int fun(int x, int y)
{
        if(x == 3 && y == (n-1))
            return 1;

        vis[x][y] = 1;
        int sum = 0;

        for(int i = 0; i < 4; i++)
        {
            int xn = x + fx[i];
            int yn = y + fy[i];
            if(valid(xn, yn))
            {
        //        dis[xn][yn] = dis[xx][yy] + 1;
                sum +=  fun(xn, yn);
            }
        }

    dis[x][y] = sum;
    return sum ;
}

int fun2(int x, int y)
{
        if(x == 0 && y == (n-1))
            return 1;

        vis[x][y] = 1;
        int sum = 0;

        for(int i = 0; i < 4; i++)
        {
            int xn = x + fx[i];
            int yn = y + fy[i];
            if(valid(xn, yn))
            {
        //        dis[xn][yn] = dis[xx][yy] + 1;
                sum +=  fun2(xn, yn);
            }
        }

    dis2[x][y] = sum;
    return sum ;
}

int main()
{
    __FastIO;   //Be aware to use it!

    cin >> n >> k;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++){
            s[i].push_back('.');
        }
    }

    clr(dis);
    clr(dis2);
    clr(vis);

    fun(0,0);
    clr(vis);
    fun2(3,0);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++){
          //  s[i].push_back('.');
          cout << i << " " << j << " " ;
          debug2(dis[i][j], dis2[i][j]);
        }
    }
//
//    for(int i = 1; i < 3; i++){
//            if(k == 0)
//            break;
//        for(int j = 1; j < n -1; j++){
//            //debug3(i, j, dis[i][j]);
//            if(k == 0)
//                break;
//            //if(dis[i][j] == dis2[i][j]){
//                s[i][j] = '#';
//                k--;
//            //}
//
//        }
//    }
//
//    if(k == 0){
//        cout << "YES\n";
//
//        for(int i = 0; i < 4; i++){
//            for(int j = 0; j < n; j++){
//                cout << s[i][j];
//            }
//            cout << endl;
//        }
//    }
//    else{
//        cout << "NO\n";
//    }

    return 0;
}

