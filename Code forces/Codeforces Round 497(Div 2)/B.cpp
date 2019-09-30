#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct st{
    ll h, w;
}ara[100005];

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%I64d %I64d",&ara[i].h, &ara[i].w);
    }
    ll prev = max(ara[0].h, ara[0].w);
    bool flag = true;
    for(int i = 1; i < n; i++){
        ll mx = max(ara[i].h,ara[i].w);
        ll mn = min(ara[i].h,ara[i].w);
        if(mn > prev){
            flag = false;
            break;
        }

        if(mx <= prev){
            prev = mx;
        }
        else{
            prev = mn;
        }
    }

    if(flag){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
