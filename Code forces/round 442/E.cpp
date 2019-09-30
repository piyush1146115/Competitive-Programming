#include<bits/stdc++.h>
using namespace std;
#define mxx 200005
struct st
{
    int str, en , val;
} node[mxx];

struct info{
long long prop, sum;
}tree[mxx * 4];

int ara[mxx];

int tme = 0;

bool vis[mxx];
vector<int> g[mxx];


void dfs(int u)
{
    vis[u] = 1;
    node[u].str = ++tme;
    ara[node[u].str] = node[u].val;

    for(int i = 0; i < (int)g[u].size(); i++)
    {
        int v = g[u][i];
        if(vis[v] == 0)
        {
            dfs(v);
        }
    }

    node[u].en = tme;
}

void init(int nd, int b, int e)
{
    if(b == e){
        tree[nd].sum = ara[b];
        tree[nd].prop = 0;
        // cout << nd << " " << b << " " << e << " " << tree[nd].sum << endl;
        return;
    }
    int left = nd * 2;
    int right = nd *2 + 1;

    int mid = (b + e)/2;
    init(left, b, mid);
    init(right, mid + 1, e);
    tree[nd].sum = tree[right].sum + tree[left].sum;
    tree[nd].prop = 0;
   // cout << nd << " " << b << " " << e << " " << tree[nd].sum << endl;
}

void update(int nd , int b, int e, int i, int j)
{
    if(i > e || j < b)
        return;
    if(b >= i && e <= j)
    {
        tree[nd].prop ^= 1;
        if(tree[nd].prop == 1){
            tree[nd].sum = (e - b + 1) - tree[nd].sum;
            tree[nd].prop ^= 1;
            if(b != e){
            tree[nd * 2].prop ^= 1;
            tree[nd * 2 + 1].prop ^= 1;
            }
        }

      //cout << b << " " << e << " " << tree[nd].prop << " " << tree[nd].sum  << endl;
        return;
    }

    int left = nd *2;
    int right = nd * 2 + 1;
    int mid = (b + e)/2;

    if(tree[nd].prop){
        tree[nd].prop ^= 1;
        tree[left].prop ^= 1;
        tree[right].prop ^= 1;
    }

    update(left, b , mid, i, j);
    update(right, mid + 1, e, i, j);
    long long sum;
    if(tree[left].prop)
        sum = (mid - b + 1) - (tree[left].sum);
    else
        sum = tree[left].sum;

        if(tree[right].prop)
        sum += (e - mid) - (tree[right].sum);
    else
        sum += tree[right].sum;

        tree[nd].sum = sum;
         //cout << b << " " << e << " " << tree[nd].prop << " " << tree[nd].sum  << endl;
//tree[nd].sum = tree[left].sum + tree[right].sum;

}

int query(int nd, int b, int e, int i, int j, int carry)
{
 if(i > e || b  > j)
        return 0;
 if(b >= i && e <= j){
  carry ^= tree[nd].prop;
    //cout << b << " " << e << " " << carry << " " << tree[nd].sum <<  endl;
    if(carry == 0){
        return tree[nd].sum;
    }
    else{
//        if(b != e){
//            tree[nd].prop = 0;
//            tree[nd *2].prop ^= 1;
//            tree[nd *2 + 1].prop ^= 1;
//
//        }
        return ((e - b + 1) - tree[nd].sum);
    }
 }
 int left = nd * 2;
 int right = nd * 2 + 1;
 int mid = (b + e)/2;
 int p1 = query(left, b, mid , i, j, carry ^ tree[nd].prop);
 int p2 = query(right, mid + 1, e , i, j, carry ^ tree[nd].prop);
 return p1 + p2;


}

int main()
{
    int n;
    memset(tree, 0, sizeof(tree));
    scanf("%d", &n);

    for(int i = 2 ; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        g[k].push_back(i);
        g[i].push_back(k);
    }

    for(int i = 1 ; i <= n; i++)
        scanf("%d", &node[i].val);

    tme = 0;
    dfs(1);
    init(1 ,1, n);

   int q;

   scanf("%d", &q);

   while(q--){
    string s;
    int k;
    cin >> s;
    scanf("%d", &k);

    if(s == "get"){
    int ans = query(1, 1, n, node[k].str, node[k].en, 0);
    printf("%d\n", ans);
    }
    else{
        update(1, 1, n, node[k].str, node[k].en);
    }
   }
}
/*
10
1 2 3 3 5 5 7 7 8
0 0 0 0 1 1 1 1 0 0
10
pow 3
get 1
pow 9
get 1
get 1
get 8
pow 8
pow 4
get 10
pow 2

10
1 2 3 4 2 4 1 7 8
1 1 0 1 1 0 0 0 1 1
10
pow 1
get 2
pow 2
pow 8
get 6
pow 6
pow 10
get 6
pow 8
pow 3
*/
