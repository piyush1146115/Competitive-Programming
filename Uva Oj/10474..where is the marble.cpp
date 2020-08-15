#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

int main()
{
    int n, q, a, b, c = 0, d,count;
    int ara[100000], ara2[100000];

    while(scanf("%d %d",&n, &q) == 2 && (n != 0 || q != 0)){
            c++;
        for(a = 0; a  < n;a++){
            scanf("%d",&ara[a]);
        }
        sort(ara,ara + n);
        for(a = 0; a  < q; a++){
            scanf("%d",&ara2[a]);
        }
        printf("CASE# %d:\n",c);
        for(a = 0; a < q;a++){
                count = 0;
            for(b = 0;b < n;b++){
                count++;
                if(ara2[a] == ara[b]){
                   // d = b - 1;
                    break;
                }
            }
            if(b == n){
                printf("%d not found\n",ara2[a]);
            }
            else
                printf("%d found at %d\n",ara2[a],count);
        }
    }
    return 0;
}
