#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int arr[mx], tree[mx * 4], indx;

void init(int node, int b, int e)
{
    if(b == e){
        tree[node] = arr[b];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    ///Here i-j is the range we searching for

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

void query2(int node , int b, int e, int i)
{
    if(i > e || i < b)
        return;

    if(b >= i && e <= i){

        indx = tree[node];
        tree[node] = 0;
        return;
}

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;

    query2(left, b, mid, i);
    query2(right, mid + 1, e, i);
    tree[node] = tree[left] + tree[right];
}


void update(int node , int b, int e, int i, int newvalue)
{
    if(i > e || i < b)
        return;

    if(b == i && e == i){
        tree[node] += newvalue;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;

    update(left, b, mid, i, newvalue);
    update(right, mid + 1, e, i, newvalue);
    tree[node] = tree[left] + tree[right];
}

int main()
{
    int n, q, i, j, k, test, v, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        scanf("%d %d",&n, &q);

        for(i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
        }
        printf("Case %d:\n", ++cs);
        init(1, 1, n);
        while(q--){
            scanf("%d", &k);
            if(k == 1){
                    scanf("%d", &i);
                    indx = 0;
                    query2(1, 1, n, i+ 1);
                printf("%d\n",indx);
                continue;
            }
            else if(k == 2){
                scanf("%d %d", &i, &v);
                update(1, 1, n, i + 1, v);
                 continue;
            }
            else{
                scanf("%d %d", &i, &j);
                printf("%d\n", query(1, 1, n, i + 1, j + 1));
            }
        }
    }
    return 0;
}
