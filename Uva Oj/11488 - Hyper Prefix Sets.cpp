#include<bits/stdc++.h>
using namespace std;
char st[50005][205];
int l[50005];

struct node
{
	int cnt;
	node *next[3];
	node()
	{
		cnt = 0;
		next[0] = NULL;
		next[1] = NULL;
	}
}*root;

void insert(char *str, int len)
{
	node *curr = root;
	for(int i = 0; i < len; i++){
		int id = str[i] - '0';
		if(curr -> next[id] == NULL)
		curr -> next[id] = new node();		
		curr = curr -> next[id];
		curr -> cnt++;
	}	
}


int search(char *str, int len)
{
	node *curr = root;
	int ans = 0, sum = 0, prev = -1, prs = 0;
	
	for(int i = 0; i < len; i++){
	int id = str[i] - '0';
	curr = curr -> next[id];
	
	prs = curr -> cnt;
	
	if(prs < prev){
		int dif = prev - prs;
		sum -= (dif * (i));
	//	cout << sum << endl;
	}
	
	if(curr -> cnt > 1)
	sum += curr -> cnt;
	else 
	break;
	
	ans = max(sum , ans);
	
	prev = curr -> cnt;
	
	}
	return ans;
}

void del(node *cur)
{
	for(int i = 0; i < 2; i++)
	if(cur -> next[i])
	del(cur -> next[i]);	
	delete(cur);
}

int main()
{
		int test;
		
		scanf("%d", &test);
		while(test--){
			root = new node();
			int n;
			scanf("%d", &n);
		int ans = -123124;		
			for(int i = 0; i < n; i++){
				scanf("%s",st[i]);
				l[i] = strlen(st[i]);
			insert(st[i], l[i]);
			}
			
//			bool flag = 0;
		
			for(int i = 0 ; i < n ; i++){
			ans = max(search(st[i], l[i]), ans);
			ans = max(ans, l[i]);
			}
			del(root);
			cout << ans << endl;
		}
 return 0;
}
