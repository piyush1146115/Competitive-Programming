#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll dp[100005];

ll fun(int n, int r)
{
    int dif = (n - r);
        //cout << n << " " << r << endl;
    if(dif > r){
        ll hor = 1;

        for(int i = n ; i > dif; i--)
        {
            hor *= i;
            hor %= mod;
        }
        ll lob = 1;
        for(int i = 1; i <= r; i++)
            lob *= i;

            //cout << hor <<" " <<  lob << endl;

        return (hor / lob);
    }

    else if(r < n){
        ll hor = 1;

        for(int i = n ; i > r; i--)
        {
            hor *= i;
            hor %= mod;
        }
        ll lob = 1;
        for(int i = 1; i <= dif; i++)
            lob *= i;
        return (hor / lob);
    }
    return 1;
}

int main()
{
    int test, n, k;
    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++){
        scanf("%d %d",&k, &n);
        ll ans = 0;
        for(int i = 1; ; i++){
            if(i * k > n)
                break;

           int  dif = n - (i * k);
          // cout << dif << " " << n << " " << i<< endl;
            ans += (fun((dif +i  + 1 , dif)) % mod;
        }
        printf("Case %d: %lld\n",tc, ans + 1);
    }
    return 0;
}

