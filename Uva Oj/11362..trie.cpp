#include<bits/stdc++.h>
using namespace std;

struct node
{
bool endmark;
node *next[10+1];
node()
{
endmark=false;
for(int i=0;i<10;i++)
 next[i]=NULL;
 }
 }*root;

 void insert(char *str,int len) {
	  node *curr=root;
	 for(int i=0;i<len;i++) {
    int id=str[i]-'0';
 if(curr->next[id]==NULL)
curr->next[id]=new node();
curr=curr->next[id];
}
curr->endmark=true;
}

int search(char *str,int len)
{	
node *curr=root;
for(int i=0;i<len;i++)
{
int id=str[i]-'0';

if(curr -> endmark == true)
 return 0;
curr=curr->next[id];
}
//cout << "ok\n";
return 1000000;
}

void del(node *cur)
{
for(int i=0;i<10;i++)
if(cur->next[i])
del(cur->next[i]);
delete(cur) ;
}

int main()
{
	char str[12000][11];
		int l[10005];
		int test;
		
		scanf("%d", &test);
		while(test--){
			root = new node();
			int n;
			scanf("%d", &n);
			
			for(int i = 0; i < n; i++){
				scanf("%s",str[i]);
				l[i] = strlen(str[i]);
				insert(str[i], l[i]);
			}
			
			bool flag = 0;
			
			for(int i = 0 ; i < n ; i++){
				if(search(str[i], l[i]) < l[i]){
					flag = 1;
	//				cout << str[i] << " " << search(str[i], l[i]) << endl;
					break;
				}
			}
			
			del(root);
			if(flag)
			printf("NO\n");
			else
			printf("YES\n");
		}
 return 0;
}
