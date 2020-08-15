#include<bits/stdc++.h>
using namespace std;
int ara[100010], cont[100010];
int main()
{
    int n , q, i;

    while(scanf("%d", &n) == 1, n){
        scanf("%d", &q);


        for(i = 0; i < n; i++){
            scanf("%d",&ara[i]);
            cont[i] = 0;
        }
        int ind = 0, up, down;
        cont[0]++;
        for(i = 1;i < n; i++){
            if(ara[i] == ara[ind])
                cont[ind]++;
            else{
                ind = i;
                cont[ind]++;
            }
            }


    }
}
