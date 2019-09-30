#include<bits/stdc++.h>
using namespace std;
#define mxx 100005
#define ll long long

struct info{
 ll prop, sum;
}tree[mxx * 9 + 5];


ll gcd(ll a, ll b)
{
    if( b == 0)
        return a;
    else return gcd(b, a % b);
}

void reset()
{
    ll sx = mxx * 9;
    for(ll i = 0; i < sx; i++){
        tree[i].prop = -1LL;
        tree[i].sum = 0LL;
    }
}

void update(ll node, ll b , ll e, ll i, ll j, ll v)
{
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e)/ 2;

    if(tree[node].prop != -1){
        tree[left].prop = tree[node].prop;
        tree[right].prop = tree[node].prop;
        tree[node].sum = tree[node].prop  * ( e - b + 1);
        tree[node].prop =  -1;
    }

    if(i > e || j < b)
        return;
    if(b >= i && e <= j)
    {
        tree[node].sum = v * (e - b + 1);
        tree[node].prop = v;
        return;
    }

    update(left, b, mid, i, j, v);
    update(right, mid + 1, e, i , j, v);

    tree[node].sum = tree[left].sum + tree[right].sum;
}


ll query(ll node, ll b, ll e, ll i, ll j)
{
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e)/ 2;

    if(tree[node].prop != -1){
        tree[left].prop = tree[node].prop;
        tree[right].prop = tree[node].prop;
        tree[node].sum = tree[node].prop  * ( e - b + 1);
        tree[node].prop =  -1;
    }

    if(i > e || j < b)
        return 0LL;
    if(b >= i && e <= j)
        return tree[node].sum;

    ll p1 = query(left, b, mid , i, j);
    ll p2 = query(right, mid + 1, e,i,  j);

    return p1 + p2;
}

int main()
{
 ll n, i , j, k, q, test, x, cs = 0;


 scanf("%lld", &test);

 while(test--){
    reset();

    scanf("%lld %lld",&n, &q);
   // init(1, 1, n);
    //memset(tree, 0 , sizeof(tree));
     //memset(tree, -1, sizeof(tree));

    printf("Case %lld:\n", ++cs);
    while(q--){
        scanf("%lld", &k);

        if(k == 1){
            scanf("%lld %lld %lld",&i, &j ,&x);
            update(1, 1, n, i + 1, j + 1, x);
        }
        else{
            scanf("%lld %lld",&i, &j);
            ll ans = query(1, 1, n, i + 1, j + 1);
            ll dif = (j - i + 1);
            //ll av = ans / dif;
            if(ans % dif == 0)
            printf("%lld\n",ans/dif);
            else{
                ll av = gcd(ans, dif);
                printf("%lld/%lld\n",ans/av,dif/av);
            }

        }
    }

 }
return 0;
}
