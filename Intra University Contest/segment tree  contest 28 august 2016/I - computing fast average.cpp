#include<bits/stdc++.h>
using namespace std;
#define MX 100005

int tree[MX * 4];

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else return gcd(b, a % b);
}
void update(int node, int b, int e, int i, int j, int v)
{
    if(i > e || j < b)
        return;
    if(i <= b && j >= e){
        tree[node] = v * (e - b + 1);
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;

    update(left, b, mid, i, j, v);
    update(right, mid + 1, e, i, j, v);

    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j, int v)
{
    if(i > e || j < b)
        return 0;
    if(i <= b && j >= e){
        //tree[node] = v * (e - b + 1);
        return (tree[node] * (e - b + 1)) + v;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;

    if(i <= mid)
    query(left, b, mid, i, j, v + tree[node]);
    else
    query(right, mid + 1, e, i, j, v + tree[node]);

//    tree[node] = tree[left] + tree[right];
}
int main()
{
        int n, q, i, j, k, test, v;

        scanf("%d",&test);

        while(test--){
                scanf("%d %d",&n , &q);
        while(q--){

            scanf("%d", &k);

            if(k == 1){
                scanf("%d %d %d",&i, &j, &v);
                update(1,1, n, i+1, j+1,v);
            }
            if(k == 2){
                int ans = query(1, 1, n, i+1, j+1, 0);
                //cout << ans << endl;
            int temp = gcd(ans , (j - i + 1));
                int a = ans / temp;
                int b = (j - i + 1)/ temp;

                if(b == 1)
                printf("%d\n",a);
                else
                    printf("%d %d\n",a, b);
            }
        }
            memset(tree, 0, sizeof(tree));
        }
        return 0;
}
