#include<bits/stdc++.h>
using namespace std;
#define MX 2005

int arr[MX][MX], ara[MX], tree[MX* 4], n;
char s[MX][MX];

void init(int node, int b, int e)
{
    if(b == e) {
        tree[node] = b;
        return;
    }
    int left = node  * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    if(ara[tree[left]] <= ara[tree[right]]) {
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
    if(b >= i &&  e <= j) {
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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	
    int i, j, k, cs = 0, test, indx, val;

    scanf("%d", &test);
	
    while(test--){
		
		memset(arr, 0, sizeof(arr));
		
		int row, col;
		scanf("%d %d",&row, &col);
		
		for(int i = 0;  i < row; i++){
			scanf("%s", s[i]);
		}
        //init(1, 1, n);
        //int ans = ser(1, n);
        
        for(int i  = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if(s[i][j] == '0'){
				if(i > 0)
				arr[i][j] = arr[i  - 1][j] + 1;
				else
				arr[i][j] = 1;
				}
			}
		}
		
		n = col;
		int ans , mxx = -2313231;
		for(int i  = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				ara[j + 1] = arr[i][j];
			}
			init(1, 1, n);
			ans = ser(1, n);
			mxx = max(ans, mxx);
		}

        printf("Case %d: %d\n",++cs, mxx);
    }
    return 0;
}

