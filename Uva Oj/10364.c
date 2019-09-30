#include<stdio.h>
int main()
{
    int ara[22];
    int a, b, c, test, sum;

    scanf("%d",&test);

    for(c = 1; c <= test;c++){
    scanf("%d", &a);


    sum = 0;
    for(b = 0; b < a; b++){
        scanf("%d",&ara[b]);
        sum = sum + ara[b];
    }
    if(a % 2 != 0 || a < 4){
        printf("no\n");
    }
    else{
    if(sum % 4 == 0)
        printf("yes\n");
    else
        printf("no\n");
    }
    }

return 0;
}
