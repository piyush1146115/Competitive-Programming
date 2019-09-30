#include<bits/stdc++.h>
using namespace std;
int ara[1000];
int main()
{
    int n, k, i, j, sum = 0;

    cin >> n >> k;

    for(i = 0; i < n ; i++)
        scanf("%d", &ara[i]);

    for(i = 0; i < n - 1; i++){
        if(ara[i] + ara[i + 1] < k){
            j = k - (ara[i] + ara[i + 1]);


                ara[i + 1] += j;

            sum += j;
        }
    }

    printf("%d\n", sum);

    for(i = 0; i < n - 1; i++)
        printf("%d ",ara[i]);

    printf("%d\n",ara[i]);

    return 0;
}
