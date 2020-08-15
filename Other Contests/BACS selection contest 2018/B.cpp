#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100005


struct st
{
    ll a, b;
} ara[MAX];
ll n, p;


ll tree[MAX * 4];

void init(int node, int b, int e)
{
    if(b == e){
        tree[node] = ara[b].b;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = min(tree[left], tree[right]);
}

ll query(int node, int b, int e, int i, int j)
{
    ///Here i-j is the range we searching for

    if(i > e || j < b)
        return 100000000000;
    if(b >= i && e <= j)
        return tree[node];

    int left = node*2;
    int right = node*2 + 1;
    int mid = (b + e)/2;
    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid + 1, e, i, j);

    return min(p1, p2);
}


bool comp(st x, st y)
{
    return x.b < y.b;

}

int main()
{
    int test;
    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {
        scanf("%lld %lld",&n, &p);

        for(int i = 1; i <= n; i++)
        {
            scanf("%lld %lld",&ara[i].a, &ara[i].b);
        }

       sort(ara + 1, ara + n + 1, comp);
//
//        init(1, 1, n);
        ll ans = 100000000000;

//        for(int i = 1; i <= n; i++){
//            printf("%lld %lld\n",ara[i].a, ara[i].b);
//
//        }



        if(p == 1)
        {
            printf("Case %d: 0\n",tc);
        }
        else
        {
            for(int i = 1; i <= n; i++)
            {
                if(i + (p -1) <= n)
                {
                   // ll ret = query(1, 1, n, i,i + p - 1 );

                    if(ara[i].b >= ara[i + p -1].a){
                        ans = 0;
                    }
                    else{
                        ll dif = ara[i + p -1].a - ara[i].b;
                        ans = min(ans, dif);
                    }
                }
            }
            printf("Case %d: %lld\n",tc, ans);

        }
    }

}
