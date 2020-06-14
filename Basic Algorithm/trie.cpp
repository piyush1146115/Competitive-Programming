#include<bits/stdc++.h>
using namespace std;

struct node
{
    bool endmark;
    node *next[10 + 1];

    node(){
    endmark = false;
    for(int i = 0; i < 11; i++)
    next[i] = NULL;
    }
}*root;

void insert(string str, int len)
{
    node *curr = root;

    for(int i = 0; i < len; i++)
    {
        int id = str[i] - '0';
        if(curr -> next[id] == NULL)
        curr -> next[id] = new node();

        curr = curr -> next[id];
    }
    curr -> endmark = true;
}

bool search(string str, int len)
{
    node *curr = root;

    for(int i = 0; i < len; i++)
    {
        int id = str[i] - '0';

        if(curr -> next[id] == NULL)
        return false;

        if(curr -> endmark == true)
        return true;
        curr = curr -> next[id];
    }
    return false;
}

void del(node *cur)
{
    for(int i = 0; i < 10; i++){
    if(cur -> next[i])
    del(cur -> next[i]);
    }

    delete(cur);
}

int main()
{

    int test;

    scanf("%d",&test);

    for(int tc = 1; tc <= test; tc++)
    {
        root = new node();
        int n;
        scanf("%d",&n);

        string s[n + 5];

        for(int i = 0; i < n; i++){
        cin >> s[i];
        insert(s[i], s[i].size());
    }

    bool flag = 0;

    for(int i = 0; i < n; i++)
    {
        flag = search(s[i], s[i].size());
        if(flag)
        break;
    }

    if(flag)
    printf("Case %d: NO\n",tc);
    else
    printf("Case %d: YES\n",tc);

    del(root);
    }
    return 0;
}
