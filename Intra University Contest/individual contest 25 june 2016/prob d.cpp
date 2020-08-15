#include<bits/stdc++.h>
using namespace std;

struct bur{
long long int box, match;
}ara[25];
bool comp(bur a, bur b){
return a.match > b.match;
}
int main()
{
    long long int n, m, i, j, total = 0;
    cin >> n >> m;

    for(i = 0; i < m; i++){
        scanf("%lld %lld", &ara[i].box , &ara[i].match);
    }

    sort(ara, ara + m, comp);
    int s = 0;
    for(i = 0; i < m; i++){
           // printf("%d %d\n",ara[i].box, ara[i].match);
        if(s + ara[i].box > n){
            j = n - s;
            total += (j * ara[i].match);
            break;
        }
        else{
            s += ara[i].box;
            total += (ara[i].box * ara[i].match);
        }
        if(s == n)
            break;
    }

    printf("%lld\n",total);

    return 0;
}
