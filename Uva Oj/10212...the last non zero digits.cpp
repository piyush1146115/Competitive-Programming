#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main()
{
    long long n, r, i, res;

    while(scanf("%lld %lld",&n, &r) == 2){
        if(r == 0)
        printf("1\n");
        else{
        res = 1;
        for(i = n - r + 1; i <= n; i++){
            res = res * i;

            while(res % 10 == 0) res /= 10;
                res = res % 100000000000;

        }
        printf("%lld\n",res % 10);
        }
    }
    return 0;
}
/*
int main()
{
    LL a,b;
    while(cin>>a>>b)
    {
        if(b==0) cout<<1<<endl;
        else
        {
            LL ans=1;
            LL c=a-b+1;
            for(LL i=a;i>=c;i--)
            {
                ans*=i;
                while(ans%10==0)
                    ans/=10;

                ans%=1000000000;

            }
            cout<<ans%10<<endl;
        }
    }
    return 0;
}
*/
