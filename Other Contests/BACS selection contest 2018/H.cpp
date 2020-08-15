#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ara[10000];
int main()
{
    int test;
    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++){
        int n, q;
        scanf("%d %d", &n, &q);

        for(int i = 0; i < n; i++){
                scanf("%lld",&ara[i]);
        }

        while(q--){
            int op, x, y;
            scanf("%d %d %d",&op, &x, &y);
            if(op == 1){
                for(int i = 0;i < n; i++){
                    if(ara[i] <= x){
                        ara[i] -= y;
                    }
                }
            }
            else{
                 for(int i = 0;i < n; i++){
                    if(ara[i] >= x){
                        ara[i] += y;
                    }
                }
            }
        }

        printf("%lld", ara[0]);
        for(int i = 1; i < n; i++){
            printf(" %lld",ara[i]);
        }
        printf("\n");
    }

}
