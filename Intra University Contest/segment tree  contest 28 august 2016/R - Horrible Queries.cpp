#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int ara[mx], n;
struct info
{
    long long prop, sum;
}tree[mx * 4];

void update(long long int node,long long  int b,long long  int e,long long  int i,long long  int j, long long x)
{
    if(i > e || j < b)
        return;
    if(b >= i && e <= j){
        tree[node].sum += (e - b + 1)* x;
        tree[node].prop += x;
        return;
    }

    long long int left = node * 2;
    long long int right = node * 2 + 1;
    long long int mid = (b + e)/ 2;
    update(left, b , mid, i, j, x);
    update(right, mid + 1, e, i, j, x);

    tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1)*tree[node].prop;
}

long long int query(long long int node,long long  int b,long long  int e,long long  int i,long long  int j,long long  int carry)
{
    if(i > e || j < b)
        return 0;
    if(b >= i && e <= j){
        return tree[node].sum + carry * (e - b + 1);
    }
    long long int left = node * 2;
    long long int right = node * 2 + 1;
    long long int mid = (b + e)/ 2;

    long long int p1 = query(left, b , mid, i, j, carry + tree[node].prop);
    long long int p2 = query(right, mid + 1, e, i, j, carry + tree[node].prop);
    return p1 + p2;
}

void init()
{
    for(int i = 0; i <= n * 4; i++){
        tree[i].prop = 0;
        tree[i].sum = 0;
    }
}
int main()
{
    long long int test, i, j, k, q, c, cs = 0, low, hi, sq, indx;
    long long v;

    scanf("%lld", &test);

    while(test--){
            scanf("%lld %lld", &n, &q);
            init();
//            printf("Case %lld:\n",++cs);

            while(q--){
        scanf("%lld", &c);

        if(c == 0){
            scanf("%lld %lld %lld", &low, &hi, &v);
            //low++;
            //hi++;
        update(1, 1, n, low , hi, v);
        }
        if(c == 1){
            scanf("%lld %lld",&low, &hi);
            //low++;
            //hi++;
         printf("%lld\n", query(1, 1, n, low, hi, 0));
        }
    }
}
return 0;
}
