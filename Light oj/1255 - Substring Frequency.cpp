#include<bits/stdc++.h>
using namespace std;
#define mxx 1000005

char TXT[mxx], pat[mxx];

vector<int> compute_prefix(const char*p)
{
    int m = strlen(p + 1);

    vector<int> prefix(m + 1);

    prefix[1] = 0;
    int k =0;

    for(int i = 2; i <= m; i++){

        while(k > 0 && p[k + 1] != p[i]) k = prefix[k];

        if(p[k + 1]  == p[i])
            k++;

        prefix[i] = k;
    }

    return prefix;
}

int kmp_match(const char *txt, const char *ptrn)
{
      int n=strlen(txt+1);
    int m=strlen(ptrn+1);
   vector<int> Prefix=compute_prefix(ptrn);
   int ans = 0;
    int q=0;
    for(int i=1; i<=n; i++)
    {
        while(q>0 and ptrn[q+1]!=txt[i])q=Prefix[q];
        if(ptrn[q+1]==txt[i])q=q+1;
        if(q==m)
        {
            ans++;
            q=Prefix[q];
        }
    }
    return ans;
}

int main()
{
    int test, i, j;

    scanf("%d",&test);

    for(i = 1; i <= test; i++){
        scanf("%s %s",TXT + 1, pat + 1);
        int  ans = kmp_match(TXT, pat);

        printf("Case %d: %d\n",i, ans);
    }
    return 0;

}
