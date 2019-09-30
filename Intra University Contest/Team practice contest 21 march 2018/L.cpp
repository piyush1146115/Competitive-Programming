#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll ara[100];
    ara[1] = 1;
    ara[2] = 2;

    for(int i = 3; i <= 81; i++){
        ara[i] = ara[i - 1] + ara[i - 2];
    }

    int n;

    while(scanf("%d", &n) == 1 && n != 0){
        printf("%lld\n",ara[n]);
    }

    return 0;
}
