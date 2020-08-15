#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

int ara[MAX], st[MAX][30];

void SparseTable(int n)
{
	for(int i = 1; i <= n; i++)
	st[i][0] = i;
	
	for(int j = 1; (1 << j) <= n; j++){
		for(int i = 1; (i + (1 << j) - 1) <= n; i++){
			if(ara[st[i][j - 1]] < ara[st[i + (1<<(j - 1))][j -1]]){
				st[i][j] = st[i][j - 1];
			}
			else
			st[i][j] = st[i + (1<<(j - 1))][j -1];
		//	debug3(i, j, st[i][j]);
		}
	}
}

int query(int a, int b)
{
	if(a > b)
	swap(a, b);
	
	int k = (int)log2(b - a + 1);
	
	if(ara[st[a][k]] < ara[st[b-(1 << k)+1][k]])
	return st[a][k];
	return st[b - (1 << k) + 1][k];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int test;
	scanf("%d", &test);
	
	for(int tc = 1 ;tc <=  test; tc++){
	int n, q;
	scanf("%d %d", &n , &q);
	
	for(int i = 1; i <= n; i++)
		scanf("%d", &ara[i]);
	
	SparseTable(n);
	printf("Case %d:\n",tc);
	while(q--){
		int a, b;
		scanf("%d %d", &a, &b);
		int ans = query(a,b);
		printf("%d\n",ara[ans]);
	}
}
    return 0;
}

