#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, x, y;

bool fun(ll s)
{
    ll i = (s / 50) % 475;

    for(int j = 0; j < 25; j++){
        i = (i  * 96 + 42) % 475;
       // printf("%d\n", 26 + i);
       ll k = 26 + i;
       if(k == n)
        return 1;
    }
    return 0;
}

int main()
{
    scanf("%I64d %I64d %I64d", &n, &x, &y);
    ll cnt = 0, flag = 0;

    ll temp = x;

    while(temp >= y){
        if(fun(temp)){
            flag = 1;
            break;
        }
        temp -= 50;
    }

    if(flag == 0){
    while(1){
        if(fun(x)){
            break;
        }
        x += 50;
        cnt++;
    }
    }

    ll res = cnt /2 + (cnt % 2);

    printf("%I64d\n",res);
}

