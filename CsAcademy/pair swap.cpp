#include<bits/stdc++.h>
using namespace std;
int ara[100005], sor[100005];

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++){
        scanf("%d",&ara[i]);
        sor[i] = ara[i];
    }

    sort(sor, sor + n);
        int ind = 0;

    for(int i = 0; i < n; i++){
        ind = max(ind, i + 1);
        int flag = 0;
                int mn= i;
        if(sor[i] < ara[i]){
            while(ind < n && (i + k) >= ind){
                if(flag == 0 && ara[ind] < ara[i]){
                  //  swap(ara[i], ara[ind]);
                    flag = 1;
                    mn = i;
                }
                if(flag == 1 && ara[ind] <= ara[mn]){
                    mn = ind;
                }

                ind++;
            }
            ind--;
        }
        if(flag){
                swap(ara[i],ara[mn]);
            break;
        }
    }

    printf("%d",ara[0]);

    for(int i = 1; i < n; i++)
        printf(" %d",ara[i]);

    printf("\n");
}
