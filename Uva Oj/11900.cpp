#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;
int main()
{
    int a, b, c, d = 0,test, i, n, p, q,count;
    int ara[35];

    scanf("%d",&test);

    while(test--){
    c = 0;
    d++;
    count = 0;
        scanf("%d %d %d",&n,&p,&q);

        for(a = 0; a <n; a++)
            scanf("%d",&ara[a]);

   // sort(ara, ara + n);

    for(i = 0; i < n; i++){
        if(i >= p){
            break;
        }
        count += ara[i];
        if(count > q){
            break;
        }
        c++;
    }
    printf("Case %d: %d\n",d,c);
    }
}
