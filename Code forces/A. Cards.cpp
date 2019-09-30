#include<bits/stdc++.h>
using namespace std;
int flag[1002];
int main()
{
    int n, i, j, sum = 0, k, ara[1004];

    cin >> n;

    for(i = 0; i < n; i++){
        scanf("%d", &ara[i]);
        sum += ara[i];
    }

    k = n / 2;

    sum /= k;

    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
                if(flag[j] == 1 || flag[i] == 1)
                    continue;

            if(ara[i] + ara[j] == sum){
                printf("%d %d\n", i + 1, j + 1);
                flag[i] = flag[j] = 1;
            }
        }
    }

    return 0;
}
