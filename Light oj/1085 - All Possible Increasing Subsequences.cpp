/**
we can make any increasing sub sequence only if we have any value lower than
it previously and we will get the sum of subsequence till the previous index
of the lower bound + 1...
for example 1 2 3

    [1] =1..
    we will get just 1 subsequence with this
    [2] = 2
    we got 1 subsequence with the previous index
    so we will get 1 + 1 = 2 subsequence with this index
    [3] = 3
    we got 2 subsequence with the previous one
    so we get 2 + 1 = 3 subsequence with this

    the summation is 3 + 2 + 1 = 6

    the result is 6.

    so, we will get 6 increasing sub sequence with this array

otherwise we will get only one subsequence with the value if it is the lowest value till then



*/


#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define mxx 100005
#define ll long long
#define sc(x) scanf("%lld", &x)
#define pf(x) printf("%d", &x)

ll a[mxx + 5], b[mxx + 5];//, pos[mxx];
ll tree[mxx * 4 + 5];


void update(ll node, ll b, ll e, ll x, ll v)
{
    if(b > x || e < x)
        return;

    if(b == x && e == x){
        tree[node] += v;
        tree[node] %= mod;
        return;
    }

    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e)/2;

    update(left, b , mid , x, v);
    update(right, mid + 1, e, x, v);

    tree[node] = (tree[left] + tree[right]) % mod;
}

ll query(ll node, ll b, ll e, ll i, ll j)
{
    if(b > j || e < i)
        return 0;

    if(b >= i && e <= j){
        return tree[node] % mod;
    }

    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e)/2;

    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid + 1, e, i, j);

    return (p1 + p2) % mod;
}


int main()
{
    ll test, n, i, j, tc = 0;

    sc(test);

    while(test--){
        sc(n);
        memset(tree, 0, sizeof(tree));

        for(i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
            b[i] = a[i];
        }

        sort(b + 1, b + n + 1);

        for(i = 1; i <= n; i++){
            ll pos = lower_bound(b + 1, b + n + 1, a[i]) - b;


            if(pos == 1){
            update(1, 1, n, 1, 1);
            }
            else{
                ll v = query(1, 1, n, 1, pos - 1) + 1;
                v %= mod;
                //cout << a[i] <<" " <<  pos << " " << v << endl;
                update(1, 1, n, pos, v);
            }
        }
        printf("Case %lld: %lld\n", ++tc , tree[1]);
    }
    return 0;
}
