#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, k, ara[100005], n;

    cin >> n;
    for(i = 0; i < n; i++)
        scanf("%d",&ara[i]);

        sort(ara, ara + n);

    for(i = 0; i < n; i++){
        if(ara[i] < i + 1){
                //printf("%d\n",i);
            for(j = i; j < n; j++){
                if(ara[j] >= i + 1){
                    ara[j] = 0;
                    break;
                }
            }
            if(j == n)
                break;
        }
    }
    printf("%d\n",i + 1);
}
