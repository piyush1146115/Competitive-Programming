#include<bits/stdc++.h>
using namespace std;
#define MX 100005
#define ll long long

ll ara[MX];

struct habijabi
{
    ll mx1, mx2;
}tree[MX * 4], ans;

void init(ll node, ll b, ll e)
{
//             cout << "ok" << endl;

    if(b == e){
        tree[node].mx1 = ara[b];
        tree[node].mx2 = 0;
        return;
    }

    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e)/ 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    if(tree[left].mx1 >= tree[right].mx1){
        tree[node].mx1 = tree[left].mx1;
        tree[node].mx2 = max(tree[left].mx2, tree[right].mx1);
    }
    else{
        tree[node].mx1 = tree[right].mx1;
        tree[node].mx2 = max(tree[left].mx1, tree[right].mx2);
    }
}

void update(ll node , ll b, ll e, ll i, ll newvalue)
{
    if(i > e || i < b)
        return;
    if(b == i && e == i){
        tree[node].mx1 = newvalue;
        tree[node].mx2 = 0;
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e)/2;

    update(left, b, mid, i, newvalue);
    update(right, mid + 1, e, i, newvalue);

    if(tree[left].mx1 >= tree[right].mx1){
        tree[node].mx1 = tree[left].mx1;
        tree[node].mx2 = max(tree[left].mx2, tree[right].mx1);
    }
    else{
        tree[node].mx1 = tree[right].mx1;
        tree[node].mx2 = max(tree[left].mx1, tree[right].mx2);
    }
}

void query(ll node , ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
        return;

    if(b >= i && e <= j){
          //  cout << tree[node].mx1 << " " << tree[node].mx2 << endl;
        if(tree[node].mx1 >= ans.mx1){
            swap(ans.mx1, ans.mx2);
            ans.mx1 = tree[node].mx1;
            ans.mx2 = max(ans.mx2, tree[node].mx2);
        }
        else{
            ans.mx2 = max(ans.mx2, tree[node].mx1);
        }
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e)/2;

    query(left, b, mid, i, j);
    query(right, mid + 1, e, i, j);
}


int main()
{
    ll n, i, j, k, l, q;

    scanf("%lld", &n);

    for(i = 1; i <= n; i++){
        scanf("%lld", &ara[i]);
    }

    init(1, 1, n);

    scanf("%lld", &q);

    while(q--){
    getchar();
    char ch;
    scanf("%c %lld %lld",&ch, &i, &j);

    if(ch == 'U'){
        update(1, 1, n, i, j);
    }
    else{
        ans.mx1 = 0;
        ans.mx2 = 0;
        query(1, 1, n, i, j);
        printf("%lld\n", ans.mx1 + ans.mx2);
    }
    }
}
