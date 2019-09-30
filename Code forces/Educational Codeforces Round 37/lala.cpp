#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[100005];

int main()
{

    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        scanf("%lld",&arr[i]);
    ll ans = 1;
    sort(arr,arr+n);
    int cn = 0;
    for(int i=n-1; i>0; i--)
    {
        if(cn == 2) break;
        if(arr[i] == arr[i-1] )
        {
            ans*=arr[i];
            cn++;
            i--;
        }
        else if((arr[i]-1) == arr[i-1])
        {
            ans*=(arr[i]-1);
            cn++;
            i--;
        }

    }
    if(cn == 2) cout<<ans<<endl;
    else cout<<0<<endl;
    return 0;
}
