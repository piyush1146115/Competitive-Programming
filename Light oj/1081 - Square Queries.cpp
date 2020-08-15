#include<bits/stdc++.h>
using namespace std;
#define mxx 505

int ara[mxx][mxx];
int tree[mxx][ mxx * 4];
int n, q, r;

void init(int node, int b, int e)
{
	if(b == e){
		tree[r][node]  = ara[r][b];
		return;
	}
	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e)/2;
	
	init(left, b, mid);
	init(right, mid + 1, e);
	tree[r][node] = max(tree[r][left], tree[r][right]);
}

int query(int node, int b, int e, int i, int j)
{
	if(i > e || j < b)
        return 0;
        
    if(b >= i && e <= j)
        return tree[r][node];
	
	 int left = node * 2;
    int right = node*2 + 1;
    int mid = (b + e)/2;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid + 1, e, i, j);
    
    return max(p1, p2);
}

int main()
{
	int test;
	scanf("%d", &test);

	for(int tc = 1; tc <= test; tc++){
		scanf("%d %d",&n, &q);
		
		for(int i = 1; i <= n ; i++){
			for(int j = 1; j <= n; j++){
				scanf("%d",&ara[i][j]);
			}
		}
		r = 0;
		
		for(r = 1; r <= n; r++){
			init(1, 1, n);
		}
		/*for(r = 1; r <= n; r++)
		printf("%d %d\n",r, query(1, 1, n, 1, n));*/
		
		printf("Case %d:\n",tc);
		
		while(q--){
			int x, y, s;
			scanf("%d %d %d", &x, &y, &s);
			int ans = 0;
			
			for(r = x; r < (x + s); r++){
				ans = max(ans, query(1, 1, n, y , y + s - 1));
				
				//printf("%d %d\n",r,  query(1, 1, n, y , y + s - 1));
			}
			printf("%d\n",ans);
		}
		
	}
	return 0;
}
