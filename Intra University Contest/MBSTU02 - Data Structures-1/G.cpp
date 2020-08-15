#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct st{
ll  num, md;
};

bool cmp(st a, st b)
{
    if(a.md == b.md){
        if((a.num % 2 == 0) && (b.num % 2 == 0)){
            return a.num < b.num;
        }

        if((a.num % 2 != 0) && (b.num % 2 != 0))
        {
            return a.num > b.num;
        }
        if((a.num % 2 != 0) && (b.num % 2 == 0)){
            return true;
        }
        if((b.num % 2 != 0) && (a.num % 2 == 0)){
            return false;
        }

        //return true;
    }
    else{
        return a.md < b.md;
    }
}

st ara[10005];

int main()
{
    ll n, m;

    while(scanf("%lld %lld",&n, &m) == 2){
        if(n == 0 && m == 0){
            printf("%lld %lld\n",n, m);
            break;
        }

        for(int i = 0; i < n; i++){
            scanf("%lld",&ara[i].num);
            ara[i].md = ara[i].num % m;
        }

        sort(ara, ara + n, cmp);

        printf("%lld %lld\n",n,m);

        for(int i = 0; i < n; i++){
            printf("%lld\n",ara[i].num);
        }
    }
}
