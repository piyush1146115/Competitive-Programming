#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char str[10005];

    int a, c, d, test;
    float b;
    scanf("%d",&test);

    while(test--){
        gets(str);
        a = strlen(str);

        if(a == 0){
            test++;
            continue;
        }

        b = sqrt(a);

          if(b == (int)b){
                for(d = 0; d < (int)b; d++){
            for(c = d; c < a;c = c + b){
                printf("%c",str[c]);
            }
        }
            printf("\n");
        }
        else
        printf("INVALID\n");
    }
return 0;
}
