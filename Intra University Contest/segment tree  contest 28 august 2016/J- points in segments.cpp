#include<bits/stdc++.h>
using namespace std;
#define MX 150005

struct st{
int x, y;
}seg[MX];

int qur[MX], tree[MX*8];
int ans;

void update(int node, int b, int e, int i, int j, int carry)
{
        //printf("ok\n");
        tree[node] += carry;

        if(e < i || b > j){
            return;
        }
        if(i <= b && e<= j){
            tree[node] += 1;
            return;
        }

        int left = node * 2;
        int right = node * 2 + 1;
        int mid = (b + e)/2;

        update(left, b, mid, i, j, tree[node]);
        update(right, mid + 1, e, i, j, tree[node]);
        tree[node] = 0;
}

void query(int node, int b, int e, int x)
{
    if(b == x && e == x){
       ans = tree[node];
       return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/ 2;

    tree[left] += tree[node];
    tree[right] += tree[node];

    tree[node] = 0;

    if(x <= mid)
        query(left, b, mid, x);
    else
        query(right, mid + 1, e, x);
}


int main()
{
    map<int, int> mp;
    set<int> s;
    int x, y, i, j, k, l, cs = 0;
    int n, q, test;

    scanf("%d", &test);

    while(test--){

        scanf("%d %d", &n, &q);

        for(i = 1; i <= n; i++){
            scanf("%d %d", &seg[i].x, &seg[i].y);
            s.insert(seg[i].x);
            s.insert(seg[i].y);
        }

        for(i = 1; i <= q; i++){
            scanf("%d", &qur[i]);
            s.insert(qur[i]);
        }

        set<int> :: iterator it;
        x = 0;

        for(it = s.begin(); it != s.end(); it++){
            mp[*it] = ++x;
        }

        memset(tree, 0, sizeof(tree));

        for(i = 1; i <= n; i++){
            x = mp[seg[i].x];
            y = mp[seg[i].y];
            update(1, 1, s.size(), x, y, 0);
         //   update(1, 1, s.size(), x,y, 0);
        }
        printf("Case %d:\n",++cs);

        for(i = 1; i <= q; i++){
            //scanf("%d", &x);
            query(1, 1, s.size(), mp[qur[i]]);
            printf("%d\n",ans);
        }
        s.clear();
        mp.clear();
    }

    return 0;
}
