#include<bits/stdc++.h>
using namespace std;
#define mxx 100005

int ara[mxx], trmx[mxx * 4],trmn[mxx * 4];

void init1(int node, int b, int e)
{
    if(b == e){
        trmn[node] = ara[b];
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;

    init1(left, b, mid);
    init1(right, mid + 1, e);

    trmn[node] = min(trmn[left], trmn[right]);
}

void init2(int node, int b, int e)
{

    if(b == e){
        trmx[node] = ara[b];
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/ 2;

    init2(left, b, mid);
    init2(right, mid + 1, e);

    trmx[node] = max(trmx[left], trmx[right]);
}


int qmx(int node, int b, int e, int i, int j)
{
    if(i > e || j < b)
        return -100544;

   // if(i >= b && j <= e)
        if(b >= i && e <= j)
        return trmx[node];


    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;

    int l = qmx(left, b, mid, i, j);
    int r = qmx(right, mid + 1, e, i, j);

    return max(l, r);
}


int qmn(int node, int b, int e, int i, int j)
{
    if(i > e || j < b)
        return 999999999;

    //if(i >= b && j <= e)
    if(b >= i && e <= j)
        return trmn[node];

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;

    int l = qmn(left, b, mid, i, j);
    int r = qmn(right, mid + 1, e, i, j);

    return min(l, r);
}


int main()
{
    int test, i, j, ts = 0, n, d;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &d);

    for(i = 1; i <= n; i++)
        scanf("%d", &ara[i]);


    init1(1, 1, n);
    init2(1, 1, n);

    int ans = -1;
    for(i = 1; (i + d - 1) <= n; i++){
        int mx = qmx(1, 1, n, i, (i + d - 1));
        int mn = qmn(1, 1, n, i, (i + d - 1));

     //   cout << mx << "  " << mn << endl;

        ans = max(ans, (mx - mn));
    }

    printf("Case %d: %d\n",++ts, ans);
    }
    return 0;
}
