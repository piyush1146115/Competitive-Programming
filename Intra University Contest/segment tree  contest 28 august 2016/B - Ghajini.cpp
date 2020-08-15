#include<bits/stdc++.h>
using namespace std;
#define MX 100005
int ara[MX], mn[MX * 4], mx[MX * 4];

void init(int node, int b, int e)
{
    if(b == e){
        mn[node] = ara[b];
        return;
    }
    int left = node  * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    mn[node] = min(mn[left], mn[right]);
    //cout << mn[node] << endl;
}


void init2(int node, int b, int e)
{
    if(b == e){
        mx[node] = ara[b];
        return;
    }
    int left = node  * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    init2(left, b, mid);
    init2(right, mid + 1, e);

    mx[node] = max(mx[left], mx[right]);
    //cout << mx[node] << endl;
}

int query2(int node, int b, int e, int i, int j)
{
int query(int node, int b, int e, int i, int j)
{
    if(i > e || j < b)
        return 1000000000;
    if(b >= i && e <= j){
        return mn[node];
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/ 2;

    int p1 = query(left , b , mid , i, j);
    int p2 = query(right, mid + 1, e, i, j);
    //cout << p1 << " " << p2 << endl;
    return min(p1, p2);
}

    if(i > e || j < b)
        return -100;

    if(b >= i &&  e <= j){
        return mx[node];
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/ 2;

    int p1 = query2(left , b , mid , i, j);
    int p2 = query2(right, mid + 1, e, i, j);

    return max(p1, p2);
}

int main()
{
    int n, i, j, k, l, cs = 0, d, test, res, ans;

    scanf("%d", &test);

    while(test--){

        scanf("%d %d", &n, &d);

        for(i = 1; i <= n; i++)
            scanf("%d", &ara[i]);

            //memset(mn, 0, sizeof(mn));
            //memset(mx, 0, sizeof(mx));

        init(1, 1, n);
        init2(1, 1, n);
        ans = -1;

        for(i = 1; i <= n; i++){
            j = i + (d - 1);
            if(j > n)
                break;

            k = query(1, 1, n, i, j);
            l = query2(1, 1, n, i, j);

            //cout << l << " " << k << endl;
            res = (l - k);
            ans = max(res, ans);
        }
        printf("Case %d: %d\n",++cs, ans);
    }
    return 0;
}
