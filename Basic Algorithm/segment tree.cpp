#include<bits/stdc++.h>
using namespace std;
#define mx 10000
int arr[mx], tree[mx * 4];

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

void update(int node , int b, int e, int i, int newvalue)
{
    if(i > e || i < b)
        return;
    if(b >= i && e <= i){
        tree[node] = newvalue;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;

    update(left, b, mid, i, newvalue);
    update(right, mid + 1, e, i, newvalue);
}

int main()
{
	
}
