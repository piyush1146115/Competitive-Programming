#include<bits/stdc++.h>
using namespace std;

#define mxx 100005

int ara[mxx], tree[mxx*4];

void init(int node, int b, int e)
{
    if(b == e){
        tree[node] = ara[b];
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = min(tree[left], tree[right]);
}

int query(int node, int b, int e, int i, int j)
{
    if(b > j || e < i)
        return 999999999;

    if(b >= i && e <= j)
        return tree[node];

    int left = node * 2;
    int  right = node * 2 + 1;
    int mid = (b + e)/ 2;

    int l = query(left, b, mid, i, j);
    int r = query(right, mid + 1, e, i, j);

    return min(l, r);
}

int main()
{
    int test, i, j, n, q, t= 0;

    scanf("%d", &test);

    while(test--){
    scanf("%d %d",&n, &q);

    for(i = 1; i <= n; i++){
        scanf("%d",&ara[i]);
    }

    init(1, 1, n);

    printf("Case %d:\n",++t);

    while(q--){
        scanf("%d %d",&i, &j);
        printf("%d\n",query(1, 1, n, i, j));
    }

}

}
