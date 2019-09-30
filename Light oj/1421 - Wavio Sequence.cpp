/*
 * FILE: 1421 - Wavio Sequence.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 06.08.2019 14:52:43 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 06-08-2019	1.0         File Created
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



int fr[MAX], bck[MAX];
int I[MAX], LF[MAX], LB[MAX];
int n;

void reset()
{
    I[0] = -INF;

    for(int i = 1; i <= n; i++)
        I[i] = INF;

}

void longest_2()
{
    reset();
    //cout << "ok\n";

    for(int i = 0; i < n; i++){

        int k = bck[i];

        int lo = 0, hi = n - 1,mid, ans = 0;

        while(lo <= hi){
            mid = (lo + hi)/2;
            if( k > I[mid]){
                ans = mid + 1;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

            LB[i] = ans;
            I[ans] = k;
    }
    int mx = 1;
    for(int i = 0; i < n;i++){
        mx = max(mx, LB[i]);
        LB[i] = mx;
    }

    for(int i = 0; i < n/2; i++)
    swap(LB[i], LB[n - i -1]);

}


void longest_1()
{
    reset();
    //cout << "ok\n";

    for(int i = 0; i < n; i++){

        int k = fr[i];

        int lo = 0, hi = n  - 1,mid, ans = 0;

        while(lo <= hi){
            mid = (lo + hi)/2;
            if( k > I[mid]){
                ans = mid + 1;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

            LF[i] = ans;
            I[ans] = k;
    }
    int mx = 1;
    for(int i = 0; i < n;i++){
        mx = max(mx, LF[i]);
        LF[i] = mx;
    }
}


void calc()
{
    int mx = 1;

    for(int i = 0; i < n; i++)
    {
        if((LF[i]) == LB[i] ){//&& LB[i + 1] > 1){
            mx = max(mx, (LF[i]+ LB[i] - 1));
        }
    }
     for(int i = n - 1; i >= 0; i--)
    {
        if((LB[i]) == LF[i] ){//&& LF[i - 1] > 1){
            mx = max(mx, (LF[i]+ LB[i] - 1));
        }
    }
//    for(int i = 0; i < n - 1; i++){
//        printf("LF[%d] = %d LB[%d] = %d\n",i, LF[i], i + 1, LB[i + 1]);
//    }

    printf("%d\n",mx);
}
int main()
{

	int test;
	
	scanf("%d", &test);
    
    forr(tc, 1, test){
		
		scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &fr[i]);


        for(int i = 0; i < n; i++)
           bck[i] = fr[n - i - 1];

//            for(int i = 0; i < n; i++)
//                printf("%d ",bck[i]);

         //   printf("\n");
           longest_1();
           longest_2();
		printf("Case %d: ",tc);
           calc();
    }
}
