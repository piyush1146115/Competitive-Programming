#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int arr[mx], tree[mx * 4];

void init(int node, int b, int e)
{

    if(b == e){
        tree[node] = arr[b];
        //cout << tree[node] <<" " <<  node << endl;
        return;
    }
    /*else{
        tree[node] = 0;
    }*/

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node] = 0;
 //   tree[node] = tree[left] + tree[right];
}

void update(int node, int b, int e, int i, int j)
{
    if(j < b || i > e)
        return;

    if(i <= b && j >= e){
        tree[node] ^= 1;
    //    cout << node << endl;
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/ 2;

    update( left, b, mid, i, j) ;
    update(right, mid + 1, e, i, j);
    //tree[node] = tree[left] ^ tree[right];
}


int query(int node, int b, int e, int i)
{
    ///Here i-j is the range we searching for

    if(i < b || i > e)
        return 0;

    if(b ==i && i== e)
        return tree[node];

    int left = node * 2;
    int right = node*2 + 1;
    int mid = (b + e)/2;

    if(i<=mid)
    return query(left, b, mid, i) ^ tree[node];
    else
    return query(right, mid + 1, e, i) ^ tree[node];
}

int main()
{
    string s;
    int i, j, k, l, test, q, n, cs = 0;

    scanf("%d", &test);
        char st;
    while(test--){
        cin >> s;
    //memset(tree, 0, sizeof(tree));
        for(i = 0; i < s.size(); i++){
            arr[i + 1] = s[i] - '0';
        }

       init(1, 1, s.size());

        scanf("%d", &q);
        printf("Case %d:\n",++cs);

        while(q--){
//        cin >> st;
            getchar();
            scanf("%c", &st);

            if(st == 'I'){
                scanf("%d %d", &j, &k);

                update(1, 1, s.size(), j, k);
            }
            else{
                scanf("%d", &k);
                printf("%d\n",query(1, 1, s.size(), k));
            }
        }
    }
    return 0;
}

