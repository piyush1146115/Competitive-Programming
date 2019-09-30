#include<bits/stdc++.h>
using namespace std;
#define mxx 62525
#define inf 1 << 30

int n, p, q;

struct st {
    int val, ind;
} b[mxx];

int a[mxx], lon[mxx], fin[mxx];

bool comp(st x, st y)
{
	
	if(x.val < y.val)
	return true;
	else
	return false;
}

void init(int num)
{
	lon[0] = -inf;
	
	for(int i = 1 ; i <= num; i++)
		lon[i] = inf;
}


int bin(int ind, int num)
{
	int lo = 0, hi = num, ans = num;
	
	//cout << num << endl;
	
	while(lo <= hi){
		int mid = (lo + hi)/2;
		//cout << lon[mid] << " " << mid << " " << ind << endl;
		//getchar();
		
		if(lon[mid] < ind){
			lo = mid + 1;
			ans = mid + 1;
		}
		else{
			hi = mid - 1;
		}
	}
	lon[ans] = ind;
	//cout << ind << " --- " << ans << endl;
	return ans;
}

int lcs(int num)
{
	init(num);
	int ans = 0;
	
	for(int i = 1; i <= p + 1; i++){
		int flag = 0, ind;
		int lo = 1, hi = q + 1, mid;
		
		while(lo <= hi){
			mid = (lo + hi)/2;
			if(b[mid].val == a[i]){
				flag = 1;
				ind = b[mid].ind;
				break;
			}
			if(b[mid].val < a[i]){
				lo = mid + 1;
			}
			else{
				hi = mid - 1;
			}
		}
		
		if(flag == 1){
		//	printf("%d ---- %d\n",a[i], ind);
			ans = max(ans, bin(ind, num));
		}
	}
	return ans;
}


int main()
{
    int test;

    scanf("%d", &test);

    for (int tc = 1; tc <= test; tc++) {
        scanf("%d %d %d", &n, &p, &q);

		for(int i = 1; i <= p + 1; i++)
		scanf("%d", &a[i]);
		
		for(int i = 1; i <= q + 1; i++){
			scanf("%d", &b[i].val);
			b[i].ind = i;
		}
		
		sort(b + 1, b + q + 2, comp);
		
		int ans = lcs(max(p, q) + 1);
		
		printf("Case %d: %d\n",tc ,ans);
    }
}
