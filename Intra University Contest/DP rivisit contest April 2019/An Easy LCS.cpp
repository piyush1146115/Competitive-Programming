/*
 * FILE: An Easy LCS.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 27.03.2019 07:47:16 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 27-03-2019	1.0         File Created
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


string a, b;
int dp[102][102];
vector<int> anxt[30], bnxt[30];
//int visit[102][102];

int lcs(int i, int j)
{
//    cout << i << " " << j << " " << a[i] << " " << b[j] << endl;
//    getchar();

    if(i == (int)a.size() || j == (int)b.size())
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;

    if(a[i] == b[j])
    {
        ans = 1 + lcs(i + 1, j + 1);
    }
    else
    {
        ans = max(ans, lcs(i + 1, j));
        ans = max(ans, lcs(i, j + 1));
    }
    // visit[i][j] = 1;
    dp[i][j] = ans;

    return ans;
}

void adel(int pos)
{
    for(int i = 0; i < 26; i++){
        while((int)anxt[i].size() > 0 && anxt[i][0] <= pos){
            anxt[i].erase(anxt[i].begin());
        }
    }
}

void bdel(int pos)
{
   // cout << " ok " << endl;
    for(int i = 0; i < 26; i++){
            while((int)bnxt[i].size() > 0 && bnxt[i][0] <= pos ){
                bnxt[i].erase(bnxt[i].begin());
            }
    }

}

int res;
string ss, ans;

void path()
{
    for(int i = 0; i < 26; i++)
    {
        anxt[i].clear();
        bnxt[i].clear();
    }

    for(int i = 0; i < (int)a.size(); i++){
            anxt[a[i] - 'a'].push_back(i);
            //cout << ch << " " << i << endl;
    }



    for(int i = 0; i < (int)b.size(); i++){
            bnxt[b[i] - 'a'].push_back(i);
        //cout << ch << " " << i << endl;

    }


    for(int i = res ; i > 0; i--)
    {
        for(int j = 0; j < 26; j++){
            if(anxt[j].size() > 0 && bnxt[j].size() > 0){
                int p1 = anxt[j][0];
                int p2 = bnxt[j][0];
                if(dp[p1][p2] == i){
                    //cout << dp[p1][p2] << endl;
                    printf("%c", j + 'a');
                    //cout << p1 <<" " <<  p2 << " " << dp[p1][p2]<< endl;
                    adel(p1);
                    bdel(p2);
                    break;
                }
            }
        }
    }

}

int main()
{
    int test;
    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {
        cin >> a >> b;
        memset(dp, -1, sizeof(dp));

        res = lcs(0, 0);

        if(res == 0)
        {
            printf("Case %d: :(\n",tc);
        }
        else
        {
            printf("Case %d: ",tc);
            path();
            printf("\n");
        }
    }
    return 0;
}
