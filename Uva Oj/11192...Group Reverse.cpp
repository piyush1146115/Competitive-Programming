#include<stdio.h>
#include<string.h>
int main()
{
    int a, b, c, d, l, n;
    char str[500];

    while(1){
        scanf("%d",&n);
        if(n == 0){
            break;
        }
        scanf("%s",str);
        l = strlen(str);
        c = 0;
        d = l /n;
        for( a = d - 1; a < l; a += d){
            for(b = a; b >= c; b--){
                printf("%c",str[b]);
            }
            c += d ;
        }
        printf("\n");
    }
    return 0;
}
