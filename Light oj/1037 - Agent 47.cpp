
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

#define fill(ar)        memset(ar, -1, sizeof(ar))
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
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             1005

ll BM( ll a, ll b, ll m )
{
    if ( b == 0 )
        return 1 ;
    ll x = BM(a,b/2,m);
    x = (( x % m) * (x % m))%m;

    if( b % 2 )
        x = (( x % m) * (a %m)) % m ;
    return x ;
}


/********************* Code starts here ************************/
int n;
ll dam[18][18];
ll life[18];
ll dp[18][33000];

int Set(int N, int pos)
{
    return N = N | (1 << pos);
}

bool check(int N, int pos)
{
    return (bool) (N & (1 << pos));
}

ll fun(int pos, int mask)
{

//cout << pos << " " << mask << endl;

    if(mask == (1 << n)-1 || pos >= n)
    {
        return 0;
    }

    if(dp[pos][mask] != -1)
    {
        return dp[pos][mask];
    }

    ll ans = 100000000000, ret,calc;



    for(int i = 0; i < n; i++)
    {
        if(!check(mask,i))
        {
            ret = life[i] + fun(pos + 1, Set(mask,i));
            ans = min(ans, ret);
            for(int j = 0; j < n; j++){
                if(check(mask,j)){
                    if(dam[j][i] > 0){
                        calc = life[i]/dam[j][i];
                        if(life[i] % dam[j][i] != 0){
                            calc++;
                        }
                        ret = calc + fun(pos + 1, Set(mask,i));
                        ans = min(ans, ret);
                    }
                }
            }
        }
    }
    dp[pos][mask] = ans;
    return ans;
}

int main()
{
    int test;
    string s;

    scanf("%d", &test);

    forr(tc, 1, test)
    {
        memset(dp,-1,sizeof(dp));

        scanf("%d", &n);

        rep(i, n)
        {
            scanf("%lld", &life[i]);
        }

        rep(i,n)
        {
            cin >> s;
            rep(j, s.size())
            {
                dam[i][j] = (ll)(s[j] - '0');
            }
        }



        ll ans = fun(0, 0);
        printf("Case %d: %lld\n",tc, ans);
    }

    return 0;
}
