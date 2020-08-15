#include<bits/stdc++.h>
using namespace std;
long long ara[1005];
int main()
{
    int test;
    scanf("%d", &test);
    for(int tc = 1; tc <= test; tc++)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &ara[i]);
        }
        int flag = 0;
        for(int i = 1; i < n; i++)
        {
            if(ara[i] - ara[i - 1] == 1)
            {
                flag = 1;
            }
        }
        if(flag)
        {
            printf("Case %d: Yes\n",tc);
        }
        else
        {
            printf("Case %d: No\n",tc);
        }
    }
}
