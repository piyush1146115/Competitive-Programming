#include<stdio.h>
int main()
{
    int ara[105],test, temp, a, b, i, max;

    scanf("%d", &test);

    for(a = 1; a <= test; a++){
        scanf("%d", &b);
        max = 0;
        for(i = 0; i < b; i++){
            scanf("%d", &ara[i]);
        }
        for(i = 0; i < b ; i++){
            if(max < ara[i]){
                temp = ara[i];
                ara[i] = max;
                max = temp;
            }
        }
        printf("Case %d: %d\n",a, max);
    }
return 0;
}
