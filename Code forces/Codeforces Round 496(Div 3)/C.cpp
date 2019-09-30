#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, ara[200005];
map<ll, ll> mp;
int main()
{
    scanf("%I64d", &n);


    for(int i = 0; i < n; i++){
        scanf("%I64d", &ara[i]);
        mp[ara[i]]++;
    }
    int flag, cnt = 0;
    for(int i = 0; i < n; i++){
        mp[ara[i]]--;
        flag = 1;
        for(ll j = 0; j < 50; j++){
            ll sum = 1 << j;
            if(sum >= ara[i]){
               ll dif = sum - ara[i];
               if(mp[dif] >= 1){
                flag = 0;
                break;
               }
            }
        }
        if(flag){
            cnt++;
        }
        else{
        mp[ara[i]]++;
        }
    }

    printf("%d\n",cnt);
}
