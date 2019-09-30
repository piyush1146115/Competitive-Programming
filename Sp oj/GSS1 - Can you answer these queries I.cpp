#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 50005

struct data{
 ll pref, suff, sum, ans;
};

ll ara[MAX];
data tree[MAX * 4];

data make_data(int val)
{

    data ret;
    ret.sum = val;
    ret.pref = ret.suff = ret.ans = val;
    return ret;
}

data combine(data left, data right)
{

    data ret;
    ret.sum = left.sum + right.sum;
    ret.pref = max(left.pref, left.sum +right.pref);
    ret.suff = max(right.suff, right.sum +left.suff);
    ret.ans = max(max(left.ans,right.ans),left.suff+right.pref );

    return ret;
}

void build(int node, int l, int r)
{
    if(l == r){
        tree[node] = make_data(ara[l]);
    }
    else{
        int m = (l + r)/2;
        build(node*2, l, m);
        build(node*2 + 1, m+1, r);
        tree[node] = combine(tree[node*2], tree[node * 2 + 1]);
    }
}


data query(int node, int tl, int tr, int l, int r)
{

//	cout << node << " " << tl << " " << tr << " " << l << " " << r << endl;

    if(l > tr || r < tl){
        return make_data(-1000000000);
    }
    if(tl >= l && tr <= r){
        return tree[node];
    }

    int tm = (tl + tr)/2;
    return combine(query(node*2, tl, tm, l, r), query(node*2+1,tm+1, tr,l,r));
}

int main()
{
   // cout << "HEllo\n";
   int n, l, r;
   scanf("%d", &n);


   for(int i = 1; i <= n; i++){
    scanf("%lld", &ara[i]);
   }

   build(1,1,n);

   int m;
   scanf("%d", &m);

   while(m--){
    scanf("%d %d", &l, &r);

    data res = query(1, 1, n, l, r);
    printf("%lld\n",res.ans);
   }
}
