#include<bits/stdc++.h>
using namespace std;
char str[50002][55];
int sz[50005];

struct node
{
	int cnt;
	node *next[6];
	node()
	{
		cnt = 0;
		next[0] = NULL;
		next[1] = NULL;
		next[2] = NULL;
		next[3] = NULL;
		next[4] = NULL;
	}
}*root;


void inrt(int ind, int len)
{
  //  printf("%s %d\n",str[ind], len);
    node *curr = root;
    int id;
    for(int i = 0; i < len; i++)
    {
        if(str[ind][i] == 'A')
        {
            id = 0;
        }
        else if(str[ind][i] == 'C')
        {
            id = 1;
        }
        else if(str[ind][i] == 'G')
        {
            id = 2;
        }
        else
        {
            id = 3;
        }
    if(curr -> next[id] == NULL)
		curr -> next[id] = new node();
		curr = curr -> next[id];
		curr -> cnt++;

 //    printf("%s %d\n",str[ind], len);
    }
}

int ser(int ind, int len)
{
    //printf("%s %d",str[ind], len);

    node *curr = root;
    int ret = 0, id;
    for(int i = 0; i < len; i++)
    {
        if(str[ind][i] == 'A')
        {
            id = 0;
        }
        else if(str[ind][i] == 'C')
        {
            id = 1;
        }
        else if(str[ind][i] == 'G')
        {
            id = 2;
        }
        else
        {
            id = 3;
        }
        curr = curr -> next[id];
        int sum = ((curr -> cnt)* (i + 1));
        ret = max(ret, sum);
    }
    return ret;
}

void del(node *cur)
{
    for(int i = 0; i < 5; i++)
    {
        if(cur -> next[i])
        {
            del(cur -> next[i]);
        }
    }
    delete(cur);
}

int main()
{


    int test;
    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {
        root = new node();
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
        {
            scanf("%s", str[i]);
            sz[i] = strlen(str[i]);
             inrt(i, sz[i]);
        }
        int ans = 0;


        for(int i = 0; i < n; i++)
        {

            ans = max(ans, ser(i, sz[i]));
        }
        printf("Case %d: %d\n",tc, ans);
        del(root);
    }
}
