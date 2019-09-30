#include<bits/stdc++.h>
using namespace std;
#define mxx 100005
struct info
{
    long long prop,sum;
}tree[mxx * 4];
long long ara[mxx];

void init(long long node, long long b, long long e)
{
    if(b == e){
        tree[node].sum = ara[b];
        tree[node].prop = 0;
        return;
    }

    long long left = node * 2;
    long long right = node * 2 + 1;
    long long mid = (b + e)/2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node].sum = tree[left].sum + tree[right].sum;
    tree[node].prop = 0;

}

void update(long long node, long long b, long long e, long long i , long long j, long long x)
{
    if(i > e || j < b)
        return;

    if(b >= i && e <= j){
        tree[node].prop += x;
        tree[node].sum += x * (e - b + 1);
        return;
    }

    long long left = node * 2;
    long long right = node * 2 + 1;
    long long mid = (b + e)/2;

    update(left, b, mid, i, j, x);
    update(right, mid + 1, e, i, j, x);

    tree[node].sum = tree[left].sum + tree[right].sum + tree[node].prop * (e - b + 1);
}

long long query(long long node, long long b, long long e, long long i , long long j, long long carry)
{
    if(i > e || j < b)
        return 0;
    if(b >= i && e <= j)
        return tree[node].sum + carry*(e - b + 1);

    long long left = node * 2;
    long long right = node * 2 + 1;
    long long mid = (b + e)/2;


    long long p1 = query(left, b, mid, i, j, carry + tree[node].prop);
    long long p2 = query(right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}


int main()
{
    long long n, q, i, j, v, x, test, cs = 0, k;

    scanf("%lld", &test);

    while(test--){
    scanf("%lld %lld", &n, &q);

    /*for(i = 1; i <= n; i++)
        scanf("%d", &ara[i]);*/

    init(1, 1, n);

    printf("Case %lld:\n", ++cs);

    while(q--){
    scanf("%lld", &k);
    if(k == 0){
        scanf("%lld %lld %lld",&i, &j, &v);
        update(1, 1, n, i + 1,j + 1, v);
    }
    else{
        scanf("%lld %lld",&i, &j);
        long long ans = query(1, 1, n, i + 1, j + 1, 0);
        printf("%lld\n",ans);
    }
    }
    }
    return 0;
}
