#include<bits/stdc++.h>
using namespace std;
#define MX 200005
#define LL long long int

LL ara[MX], n;
struct info{
long long prop, sum;
}tree[MX * 4];

void init(LL node, LL b, LL e)
{
    if(b == e){
        tree[node].sum = ara[b];
        return;
    }

    LL left = node * 2;
    LL right = node * 2 + 1;
    LL mid = (b + e)/2;

    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node].sum = min(tree[left].sum ,  tree[right].sum) ;
 }

 void update(LL node, LL b, LL e, LL i, LL j, LL x)
 {
     if(i > e || j < b)
        return;

     if(b >= i && e <= j){
        tree[node].sum += x;
        tree[node].prop += x;
        return;
     }

     LL left = node * 2;
     LL right = node * 2 + 1;
     LL mid = (b + e)/ 2;

     update(left, b , mid, i, j, x);

     update(right, mid + 1, e, i, j, x);

     tree[node].sum = min(tree[left].sum, tree[right].sum) + tree[node].prop;
 }


LL query(LL node, LL b, LL e, LL i, LL j, LL carry)
{
    if(i > e || j < b)
        return 100000000000;
    if(b >= i && e <= j){
        return tree[node].sum + carry ;
    }
    LL left = node * 2;
    LL right = node * 2 + 1;
    LL mid = (b + e)/ 2;

    LL p1 = query(left, b, mid , i, j, carry + tree[node].prop);
    LL p2  = query(right, mid + 1, e, i, j, carry + tree[node].prop);

    return  min(p1 , p2);
}

int main()
{
    LL i, j, k, q, inp[10];
    string st;

    scanf("%lld", &n);

    for(i = 1; i <= n ;i++){
        scanf("%I64d", &ara[i]);
    }
//    reset();
    init(1, 1, n);

    scanf("%I64d", &q);

    getchar();

    while(q--){
        char ch;
            scanf("%I64d %I64d%c",&inp[0], &inp[1], &ch);
            j = 0;

            if(ch != '\n'){
                    scanf("%I64d",&inp[2]);

                    if(inp[0] <= inp[1]){
                update(1, 1, n, inp[0] + 1, inp[1] + 1, inp[2]);
                    }
                    else{
                        update(1, 1, n, inp[0] + 1, n, inp[2]);
                        update(1, 1, n, 1, inp[1] + 1, inp[2]);
                    }
            }
            else{
                LL ans = 0;
                if(inp[0] <= inp[1]){
                    ans = query(1, 1, n, inp[0] + 1, inp[1] + 1, 0);
                }
                else{
                    ans = query(1,1, n, inp[0] + 1, n, 0);
                    ans = min(ans, query(1, 1, n, 1, inp[1] + 1, 0));
                }
                printf("%I64d\n",ans);
            }
    }
    return 0;
}
