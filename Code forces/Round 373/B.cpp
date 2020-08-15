#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
string s[MAX];
long long ara[MAX];
int main()
{

    map<string, int> mp;

    int n, k, m;
    scanf("%d %d %d",&n, &k, &m);

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    for(int i = 0; i < n; i++){
        scanf("%lld", &ara[i]);
        mp[s[i]] = ara[i];
    }

    for(int i = 0; i < k; i++)
    {
        int x;
        scanf("%d", &x);
        int temp[x + 5];
        long long mn = 100000000000;
        for(int j = 0; j < x; j++){
            scanf("%d", &temp[j]);
            mn = min(mn, ara[temp[j]-1]);
        }

        for(int j = 0; j < x; j++){
            mp[s[temp[j] - 1]] = mn;
        }
    }

    string str;
    long long ans = 0;

    for(int i = 0; i < m;i++){
        cin >> str;
        ans += mp[str];
    }

    printf("%lld\n",ans);
}
