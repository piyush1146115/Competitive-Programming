#include<bits/stdc++.h>
using namespace std;
#define mxx 100005

int ara[mxx], ans[mxx], last[mxx];
int tree[mxx * 4];

struct st{
int fir, las, indx;	
}inp[mxx];

bool comp(st a, st b)
{
	if(b.las > a.las)
	return true;
	else 
	return false;
}



void update(int node, int b, int e, int i, int val)
{
	if(i > e || i < b)
	return;
	if(b >= i && e <= i)
	{
		tree[node] = val;
		return;
	}
	
	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e)/2;
	
	update(left, b, mid, i, val);
	update(right, mid + 1, e, i, val);
	
	tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j)
{
	if(i > e || j < b)
	return 0;
	
	if(b >= i && e <= j)
	return tree[node];
	
	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e)/ 2;
	
	int r1 = query(left, b, mid, i, j);
	int r2 = query(right, mid + 1, e, i, j);
	
	return r1 + r2;
}

int main()
{
	int test;
	
	scanf("%d",&test);
	
	for(int tc = 1; tc <= test; tc++){
		
	memset(tree, 0, sizeof(tree));
	memset(last, 0, sizeof(last));
	
	int n, q;
	
	scanf("%d %d", &n, &q);
	
	for(int i = 1; i <= n; i++)
	scanf("%d", &ara[i]);
	
	for(int i = 1; i <= q; i++){
	scanf("%d %d",&inp[i].fir, &inp[i].las);
	inp[i].indx = i;
	}
	
	sort(inp + 1, inp + q + 1, comp );
	
	/*for(int i = 1; i <= q; i++)
	printf("%d %d %d\n",inp[i].indx, inp[i].fir, inp[i].las);
	*/
	
	int ind = 1;
	for(int i = 1; i <= n; i++){
		if(last[ara[i]] == 0){
			last[ara[i]] = i;
			update(1, 1, n, i, 1);
		}
		else{
			update(1, 1, n, last[ara[i]], 0);
			last[ara[i]] = i;
			update(1, 1, n, i, 1);
		}
		while(ind <= q && inp[ind].las == i){
			ans[inp[ind].indx] = query(1, 1, n, inp[ind].fir, inp[ind].las);
			ind++;
		}
	}
	
	printf("Case %d:\n",tc);
	
	for(int i = 1; i <= q; i++)
	printf("%d\n",ans[i]);
	
	
}
	return 0;
}
