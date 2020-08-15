#include<bits/stdc++.h>
using namespace std;
#define mxx 100005

int tree[mxx* 4], ara[mxx], ans;

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

    tree[node] = tree[left] + tree[right];
}

void up1(int node, int b, int e, int i)
{
    if(i > e || i < b)
        return;

    if(b >= i && e <= i){
        ans = tree[node];
        tree[node] = 0;
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;

    up1(left, b, mid, i);
    up1(right, mid + 1, e, i);

    tree[node] = tree[left] + tree[right];
}

void up2(int node, int b, int e, int i, int v)
{
     if(i > e || i < b)
        return;

    if(b >= i && e <= i){
        tree[node] += v;
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;

    up2(left, b, mid, i, v);
    up2(right, mid + 1, e, i, v);

    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i,int j)
{
    if(i > e || j < b)
        return 0;

    if(b >= i && e <= j)
        return tree[node];

    int left = node * 2;
    int right = node*2 + 1;
    int mid = (b + e)/2;

    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid + 1, e, i, j);

    return p1 + p2;
}

int main()
{
    int test, i, j, v, k, t = 0, n, q;

    scanf("%d", &test);

    while(test--){

        scanf("%d %d", &n, &q);

        for(i = 1; i <= n;i++){
            scanf("%d", &ara[i]);
        }

        init(1,1 , n);

        printf("Case %d:\n", ++t);

        while(q--){
            scanf("%d", &k);

            if(k == 1){
                scanf("%d", &j);
                up1(1, 1, n, j + 1);
                printf("%d\n", ans);
            }
            if(k == 2)
            {
                scanf("%d %d", &j, &v);
                up2(1, 1, n, j+1, v);
            }
            if(k == 3){
                scanf("%d %d", &i, &j);
                printf("%d\n", query(1, 1, n, i + 1, j + 1));
            }
        }
    }
    return 0;

}
