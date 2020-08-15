#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[105];
    scanf("%s",str);
    int mn;
    int len  = strlen(str);
    mn = len;
    for(int i=0; i<len; i++)
    {
        for(int j = i ; j<len; j++)
        {
            int tot = 0,ans = 0;
            for(int k = 0; k + (j - i)<len; k++)
            {
                int cnt = 0;

                while(cnt<(j - i + 1))
                {
                    if(str[i + cnt] == str[k + cnt])
                    {
                        cnt++;
                    }
                    else break;
                }
                if(cnt == (j - i + 1))
                {
                    tot++;
                    k+=(j - i);
                }
            }
            //cout<<" tot " <<tot<<endl;
            //cout << " len " << (j - i + 1) << endl;
            if(tot>0 && (j-i+1)>1)
            {
                ans+=(tot + ( j - i + 1)) ;
                ans+=(len - (tot * ( j - i + 1)));
            }

            //cout<<"ans = "<<ans<<endl;
            if(ans<=0) ans = 9999999;
            mn = min(ans,mn);

        }

    }
    //mn = min(mn,len);
    printf("%d\n",mn);
}
