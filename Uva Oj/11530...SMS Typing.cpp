#include<stdio.h>
#include<string.h>
int main()
{
    char str[105];
    int ara[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    int a, b, c, d, e, f, test;

    scanf("%d",&test);

    for(a = 1; a <= test; a++){
        gets(str);
        e = 0;
        b = strlen(str);
        if(b == 0){
            a--;
            continue;
        }

        for(c = 0; c < b; c++){
            if(str[c] == ' '){
                e += 1;
            }
            else{
                d = str[c] ;
                e += ara[d-97];
            }

        }
       /* if(a >= 2){
            e += 1;
        }*/
        printf("Case #%d: %d\n",a,e);
    }
    return 0;
}
