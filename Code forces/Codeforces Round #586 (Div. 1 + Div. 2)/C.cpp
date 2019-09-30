#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[1005][1005];
ll brr[1005][1005];
ll f[1005];
int main()
{
    int n;
    cin>>n;
    ll gcd = 0;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            scanf("%lld", &arr[i][j]);
            if(i == 1) gcd = __gcd(gcd,arr[i][j]);
        }
    }
    vector<ll>vc;
    int sq = sqrt(gcd);
    for(ll i = 1; i<=sq; i++)
    {
        if(gcd%i == 0)
        {
            vc.push_back(i);
            vc.push_back(gcd/i);
        }
    }
    int sz = vc.size();
    for(int i = 0; i < sz; i++)
    {
        f[1] = vc[i];
        for(int j = 2; j<=n; j++) f[j] = arr[1][j]/f[1];
        for(int ii = 1; ii<=n; ii++)
        {
            for(int jj = 1; jj<=n; jj++)
            {
                brr[ii][jj] = f[ii]*f[jj];
            }
        }
        int ck = 0;
        for(int ii = 1; ii<=n; ii++)
        {
            for(int jj = 1; jj<=n; jj++)
            {
                if(ii == jj) continue;
                else if(arr[ii][jj] != brr[ii][jj])
                    ck = 1;
            }
        }
        if(ck == 0)
        {
            for(int jj = 1; jj<=n; jj++)
                cout<<f[jj]<<" ";
            return 0;
        }
    }
}

