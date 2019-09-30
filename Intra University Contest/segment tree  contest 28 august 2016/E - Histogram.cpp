#include<bits/stdc++.h>
using namespace std;
#define MX 30005

int ara[MX], tree[MX* 4], n;

void init(int node, int b, int e)
{
    if(b == e){
        tree[node] = b;
        return;
    }
    int left = node  * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    if(ara[tree[left]] <= ara[tree[right]]){
        tree[node] = tree[left];
    }
    else
        tree[node] = tree[right];
    //cout << mn[node] << endl;
}



int query(int node, int b, int e, int i, int j)
{
    if(i > e || j < b)
        return -1;
    if(b >= i &&  e <= j){
        return tree[node];
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/ 2;

    int ind = query(left, b, mid, i, j);
    int ind2 = query(right, mid + 1, e, i, j);

    if(ind == -1 && ind2 != -1)
        return ind2;
    if(ind2 == -1 && ind != -1)
        return ind;

    if(ara[ind2] <= ara[ind])
        return ind2;
    else
        return ind;
}

int  ser(int b, int e)
{
    if(b > e)
        return 0;
    if(b == e)
        return ara[b];

    int indx = query(1,1, n, b, e);
    int Area = (e - b + 1) * ara[indx];
    int area = max(ser(b, indx - 1) , ser(indx + 1, e));
    return max(Area, area);
}

int main()
{
        int i, j, k, cs = 0, test, indx, val;

        scanf("%d", &test);

        while(test--){
            scanf("%d", &n);

            for(i = 1; i <= n; i++){
                scanf("%d", &ara[i]);
            }

            init(1, 1, n);
           int ans = ser(1, n);

            printf("Case %d: %d\n",++cs, ans);
        }
        return 0;
}
