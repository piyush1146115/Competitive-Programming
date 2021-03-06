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
#define MAX             200005

ll BM( ll a , ll b , ll m )
{
    if ( b == 0 ) return 1 ;
    ll x = BM(a,b/2,m);
    x = (( x % m) * (x % m))%m;

    if( b % 2 ) x = (( x % m) * (a %m)) % m ;
    return x ;
}

ll ara[MAX];

/********************* Code starts here ************************/

int main()
{
    __FastIO;

    ll n;
    cin >> n;

    rep(i, n){
    cin >> ara[i];
    }
    map<ll , ll >mp;
    ll cnt = 0, mx = 0, flag = 0;
    for(int i = 1; i < n; i++){
        ll dif = abs(ara[i] - ara[i - 1]);
        if(mp.find(dif) == mp.end()){
            mx = max(dif, mx);
            if(dif > 1)
            cnt++;
            if(dif == 0){
                cnt += 100;
    //            mx = 10000000;
            }

            //debug1(dif);
            mp[dif] = 1;
        }
    }

    if(cnt > 1){
        flag = 1;
    }


    if(mx == 0){
        mx = ara[0];
    }

    for(int i = 1; i < n; i++){
        int r1, r2, c1, c2;
        r1 = (ara[i -1] - 1)/mx;
        r2 = (ara[i] - 1)/mx;
        c1 = ara[i -1] % mx;
        c2 = ara[i] % mx;

        if(r1 != r2 && c1 != c2)
            flag = 1;
    }



    if(flag){
        cout << "NO\n";
    }
    else{
            cout << "YES\n";

        cout << 1000000000 << " " << mx << endl;
    }
}

//#include<stdio.h>
//int main()
//{
//
//    int i = 1;
//    int j = ++i + ++i; //+ ++i;
//    printf("%d\n",j);
//}
