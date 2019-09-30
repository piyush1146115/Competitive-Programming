#include<bits/stdc++.h>
using namespace std;
#define mx 50005
long long int arr[mx], tree[mx * 4];

void init(long long int node, long long int b, long long int e)
{
    if(b == e){
        tree[node] = arr[b];
        return;
    }
    long long int left = node * 2;
    long long int right = node * 2 + 1;
    long long int mid = (b + e)/ 2;
    init(left, b, mid);
    init(right, mid + 1, e);
//    int mx = max(tree[left], tree[right]);
    tree[node] = max(max(tree[left], tree[right]), tree[left] + tree[right]);
}

long long int query(long long int node, long long int b, long long int e, long long int i, long long int j)
{
    if(i > e || j < b)
        return 0;
    if(b >= i && e <= j)
        return tree[node];

    long long int left = node * 2;
    long long int right = node * 2 + 1;
    long long int mid = (b + e)/2;
    long long int p1 = query(left, b, mid, i, j);
    long long int p2 = query(right, mid + 1, b, i, j);

//    long long int mx = max(p1, p2);
return max(max(p1, p2), p1 + p2);
}

int main()
{
    long long int m, n, q, i, j, k, sum, maxi;


    while(scanf("%lld", &n) == 1){
        for(i = 1; i <= n; i++){
            scanf("%lld",&arr[i]);
        }
       // init(1, 1, n);

        scanf("%lld", &m);

        while(m--){
            scanf("%lld %lld",&j, &k);
            /*
            printf("%lld\n", query(1, 1, n, j, k));
            */
        sum = 0;
        maxi = -1234567890;
            for(i = j;i <= k; i++){
                sum += arr[i];
                if(sum < 0){
                    sum = 0;
                }
                maxi = max(maxi, sum);
            }
            printf("%lld\n", sum);;
        }
    }
    return 0;
}
