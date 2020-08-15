#include<stdio.h>
int main()
{
    int ara[10] = {0};
    long long int a, b, n, c;
    int d, test;

    scanf("%d",&test);

    while(test--){
        scanf("%lld",&n);
        for(a = 1; a <= n;a++){
                c = a;
            while(c >= 1){
                d = c % 10;
                ara[d]++;
                c = c/10;
            }
        }
        for(b = 0; b < 10; b++){
            printf("%d",ara[b]);
            ara[b] = 0;
            if(b < 9){
                printf(" ");
            }
        }
        printf("\n");
    }
return 0;
}
