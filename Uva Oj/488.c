#include<stdio.h>
int main()
{
    int a, b, c, d, e;
    int i, j, k, test;

    scanf("%d", &test);

    for( e = 1; e <= test;e++){
    scanf("%d", &a);
    scanf("%d", &b);

    for(c = 1; c <= b; c++){
        for(d= 1; d <= a; d++){
            for(i = 1;i <= d;i++){
                printf("%d", d);
            }
            printf("\n");
        }
        for(k = a- 1; k >= 1; k--){
            for(j = 1; j <= k; j++){
                printf("%d", k);
            }
            printf("\n");
        }
        if(e < test || c != b)
        printf("\n");
    }
    }
return 0;
}
