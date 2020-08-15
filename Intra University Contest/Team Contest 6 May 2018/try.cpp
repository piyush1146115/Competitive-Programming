#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
char TXT[1000000],ptr[1000000];
vector<int> Match_position;

vector<int> compute_prefix(const char *p)
{
    int m=strlen(p+1);
    vector<int> prefix(m+1);
    prefix[1]=0;
    int k=0;
    for(int i=2; i<=m; i++)
    {
        while(k>0 and p[k+1]!=p[i])
            k=prefix[k];

        if(p[k+1]==p[i])k=k+1;
        prefix[i]=k;
    }
    return prefix;
}

vector<int> KMP_match(const char *txt,const char *ptrn)
{
    int n=strlen(txt+1);
    int m=strlen(ptrn+1);
    vector<int> Prefix=compute_prefix(ptrn);
    vector<int>Match_position;
    int q=0;
    for(int i=1; i<=n; i++)
    {
        while(q>0 and ptrn[q+1]!=txt[i])q=Prefix[q];
        if(ptrn[q+1]==txt[i])q=q+1;
        if(q==m)
        {
            Match_position.push_back(i-m);
            q=0;
        }
    }
    return Match_position;
}

int main()
{
    int n,q;

    cin>>n>>q;

    scanf("%s",TXT+1);
    while(q--)
    {
        int mx = 0;
        scanf("%s",ptr+1);
        int ln = strlen(ptr + 1);


        vector<int> Match_position=KMP_match(TXT,ptr);
        if(Match_position.size() == 0) printf("0\n");
        else
        {
            int ck = 0,cn = 1;
            for(int i=0; i<Match_position.size() -1; i++)
            {
               // cout<<"pos = "<<Match_position[i]<<endl;
          if(abs(Match_position[i] - Match_position[i+1]) == ln)
                cn++;
            else
                {
                    mx = max(mx,cn);
                    cn = 1;
                }
            }
            mx = max(mx,cn);
            printf("%d\n",mx);
        }

    }
    return 0;
}
