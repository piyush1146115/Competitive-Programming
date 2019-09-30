#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int fre[12] = {0};

    for(int i=1; i<=n; i++)
    {
        int x = i;
        while(x!=0)
        {
            fre[x%10]++;
            x/=10;
        }
    }
    int mx = 0,ans;
    for(int i=1; i<=9; i++)
    {
       // cout<<fre[i]<<endl;
        if(fre[i]>=mx)
        {
            mx = fre[i];
            ans = i;
        }
    }
        cout<<ans<<" ace = "<<mx<<" bar "<<endl;
        main();
    }
