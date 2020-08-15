#include<bits/stdc++.h>
using namespace std;

int ara[105];

int main()
{
    int n, i, j, k;

    scanf("%d",&n);

    for(i = 0; i < n; i++){
        scanf("%d",&ara[i]);
    }

    int sum = 0;

    for(i = 0; i < n; i++){
    sum += ara[i];
    }

    if(sum != 0){
        printf("YES\n1\n%d %d\n",1, n);
    }
    else{
            int s= 0, flag = 0;

        for(i = n - 1; i > 0; i--){
            sum -= ara[i];
            s += ara[i];
            if(sum != 0 && s != 0){
                flag = 1;
                printf("YES\n2\n");
                printf("1 %d\n%d %d\n", i, i + 1, n);
                break;
            }
        }

        if(!flag){
            printf("NO\n");
        }
    }
    return 0;
}
