#include<stdio.h>
#include<string.h>
char str[1000005];
int main()
{
    long long a, b,m, n, i, j;
    char c[2], d[2];
    int r, test,ara[128];
    for(a = 0; a < 128;a++){
        ara[a] = a;
    }
    scanf("%d", &test);

    for(a = 1; a <= test; a++)
    {
        scanf("%s",str);
        b = strlen(str);
        scanf("%d", &r);

        for(i = 1; i <= r; i++ )
        {
            scanf("%s",&c);
            scanf("%s",&d);
              for(j = 'A'; j <= 'Z'; j++){

                if(ara[j] == d[ 0 ]){
                    ara[j] = c[ 0 ];
                }
              }
        }
        for(n = 0; n < b; n++)
            putchar(ara[str[n]]);

        puts("");
    }
    return 0;
}
