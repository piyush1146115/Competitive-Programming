#include<bits/stdc++.h>
using namespace std;
#define MX 150005

int tree[MX*4], ara[MX],n;

void init(int node, int b, int e)
{
    if(b == e){
        if(b <= n){
            tree[b] = 1;
        }
        else{
            tree[b] = 0;
        }
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (left + right) / 2;

    init(left, b, mid);
    init(right, mid + 1,e);

    tree[node] = tree[right] + tree[left];
}

void update(int node, int b, int e, int i)
{
    if(b == i && e == i){
        tree[node] = 1;
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (left + right) / 2;

    if(i <= mid){
        update(left , b, mid, i);
    }
    else{
        update(right, mid + 1, e, i);
    }

    tree[node] = tree[left] + tree[right];
}

int main()
{

}
