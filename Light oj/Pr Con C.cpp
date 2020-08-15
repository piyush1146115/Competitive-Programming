#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    int tc;
    cin>>tc;

    for (int t=1; t<=tc; t++)
    {
        ll n;
        cin>>n;
        ll r=sqrt(n);
        ll a,b;
        for (int i=2; i<=r; i++)
        {
            if (n%i==0)
            {
                a=i;
                break;
            }
        }
        b=n/a;
        ll c=-1;
        for (int i=2; i<=sqrt(b); i++)
        {
            if (b%i==0)
            {
                c=i;
                break;
            }
        }
        cout<<"Case #"<<t<<": "<<n<<" = ";
        if (c!=-1)
        {
            cout<<a<<" * "<<b<<" = "<<a*c<<" * "<<b/c<<endl;
        }
        else
        {
            for (int i=2; i<=sqrt(a); i++)
            {
                if (a%i==0)
                {
                    c=i;
                    break;
                }
            }
            cout<<a<<" * "<<b<<" = "<<a*c<<" * "<<b/c<<endl;
        }
    }
}
