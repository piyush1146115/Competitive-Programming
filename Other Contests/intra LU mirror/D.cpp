#include<bits/stdc++.h>
using namespace std;
#define mxx 100005

bool flag[5000];
int ara[mxx], tree[mxx * 4];

vector<int> prime;

void sieve()
{

    for(int i = 3; i*i <= 4500; i += 2 )
    {
        if(flag[i] == 0)
        {
            for(int j = i * i; j <= 4500; j += (i * 2))
                flag[j] = 1;
        }
    }

    prime.push_back(2);

    for(int j = 3; j <= 4500; j += 2)
        if(flag[j] == 0)
            prime.push_back(j);
}

bool isprime(int n)
{
    if(n == 1)
        return false;

    for(int i = 0; prime[i] * prime[i] <= n; i++)
    {
        if(n % prime[i] == 0)
            return 0;
    }
    return 1;
}

void init(int node, int b, int e)
{
    if(b == e)
    {
        if(isprime(ara[b]))
        {
            tree[node] = 1;
        }
        else
        {
            tree[node] = 0;
        }
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

    if(b == i && e == i)
    {
        if(isprime(newvalue))
        {
            tree[node] = 1;
        }
        else
        {
            tree[node] = 0;
        }
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
    sieve();

    int n;
    scanf("%d", &n);



    for(int i = 1; i <= n; i++)
        scanf("%d", &ara[i]);

    init(1, 1, n);

    int q;
    scanf("%d", &q);

    while(q--)
    {
        int type, b, e , newvalue;
        scanf("%d", &type);

        if(type == 1)
        {
            scanf("%d %d",&b, &e);
            int ans = query(1, 1, n,b, e );
            printf("%d\n",ans);
        }
        else
        {
            scanf("%d %d",&b, &newvalue);
            update(1,1,n, b,newvalue);
        }
    }


}
