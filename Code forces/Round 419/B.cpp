#include<bits/stdc++.h>
using namespace std;
#define mxx 200005

struct info {
    int   prop, sum;
} tree[mxx * 3]; //sum ছাড়াও নিচে অতিরিক্ত কত যোগ হচ্ছে সেটা রাখবো prop এ

int sum[mxx];

void update(int node, int b, int e, int i, int j, int x)
{
    if (i > e || j < b)
        return;
        
    if (b >= i && e <= j) //নোডের রেঞ্জ আপডেটের রেঞ্জের ভিতরে
    {
        tree[node].sum += ((e - b + 1) * x); //নিচে নোড আছে e-b+1 টি, তাই e-b+1 বার x যোগ হবে এই রেঞ্জে
        tree[node].prop += x; //নিচের নোডগুলোর সাথে x যোগ হবে
        return;
    }
    
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;

}

int query(int node, int b, int e, int i, int j, int carry)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1); //সাম এর সাথে যোগ হবে সেই রেঞ্জের সাথে অতিরিক্ত যত যোগ করতে বলেছে সেটা

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    int p1 = query(Left, b, mid, i, j, carry + tree[node].prop); //প্রপাগেট ভ্যালু বয়ে নিয়ে যাচ্ছে carry ভ্যারিয়েবল
    int p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

int main()
{
	memset(tree, 0, sizeof(tree));
	
	int n, k, q;
	
	scanf("%d %d %d",&n, &k,&q);
	
	for(int i = 1; i <= n; i++){
		int l, r;
		scanf("%d %d",&l, &r);
		
		update(1, 1, 200000, l, r, 1);
	}
	
	
	for(int i = 1; i <= 200000; i++){
		if(query(1, 1, 200000, i, i, 0) >= k){
			sum[i] = 1;
		}
	}
	
	for(int i = 1; i <= 200000; i++)
	 sum[i] = sum[i] + sum[i - 1];
	 
	for(int i = 1; i <= q; i++){
		int l, r;
		scanf("%d %d",&l, &r);
		
			printf("%d\n",sum[r] - sum[l - 1]);
	}
}
