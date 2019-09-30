#include<bits/stdc++.h>
using namespace std;
int arr[1000010];
bool mp[1000010];
int main()
{
    int n,m;
    scanf("%d %d",&n, &m);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int l,r,cn;
    while(m--)
    {
        getchar();
        char ch;
        scanf("%c %d %d",&ch,&l,&r);

        if(ch == 'Q')
        {
            if(l>r) swap(l,r);
            cn = 0;
            memset(mp,false,sizeof(mp));

            for(int i=l; i<r; i++)
            {
                if(mp[arr[i]] == false)
                {
                    mp[arr[i]] = true;
                    cn++;
                }

            }
            cout<<cn<<endl;
        }
        else
            arr[l] = r;
    }
    return 0;
}
