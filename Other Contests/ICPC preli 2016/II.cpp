#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ULL unsigned long long
#define D double
#define pb push_back
#define mp make_pair
#define sf scanf
#define pf printf
#define ff first
#define ss second
#define SZ 100005
#define eps 1e-8
#define PI (2*acos(0.0))
#define mem(a, b) memset(a, b, sizeof a)
#define FastIO ios_base::sync_with_stdio(0)

const int inf = 0x7f7f7f7f;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};
int mnth[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
ll bigmod(ll b, ll p, ll m)
{
    ll res=1;
    if(p==1){
        return b;
    }
    if(p%2==0)
    {
        //res = ((bigmod(b,p/2,m)%m)*(bigmod(b,p/2,m)%m)%m);
        res = (bigmod(b,p/2,m)%m);
        res = ((res%m)*(res%m))%m;
    }
    else{
        res = ((bigmod(b,p-1,m)%m)*(b%m)%m);
    }

    return res%m;
}


ll a[100002];
void fun()
{
    a[0] = 1;
    a[1] = 2;

    for(ll i=2; i<SZ; i++) {
        a[i] = a[i-1]%m+a[i-2];
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //FastIO;
    fun();
    ll n, k, m, ks = 0, t;
    cin>>t;
    while(t--) {
        cin>>n>>k>>m;
        ll p = a[n];
        cout<<p<<endl;
        ll ans = bigmod(k, p, m);
        pf("Case %lld: %lld\n", ++ks, ans);
    }

    //main();
}


