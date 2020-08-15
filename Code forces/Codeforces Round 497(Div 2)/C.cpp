#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[100005];
int main()
{
    ll n;

    scanf("%I64d" , &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%I64d", &ara[i]);
    }

    sort(ara, ara + n);

    queue<ll> q;

    for(int i = 0; i < n; i++)
    {
        q.push(ara[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(q.empty())
        {
            break;
        }
        ll ff = q.front();

        if(ff > ara[i])
        {
            q.pop();
            ans++;
        }
        else
        {
            while(!q.empty() && ff <= ara[i])
            {
                q.pop();
                if(!q.empty())
                {
                    ff = q.front();
                }
            }
            if(ff > ara[i])
            {
                q.pop();
                ans++;
            }
        }
    }

    printf("%d\n",ans);
}
