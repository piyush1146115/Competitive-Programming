#include<stdio.h>
#include<string.h>
int main()
{
    int a, b, c, i, j, k;
    char str[10];
    scanf("%d",&k);
    while(k--){
        scanf("%s",str);
        i = strlen(str);

        if(i == 3){
            if((str[0] =='t' || str[1] == 'w') &&( str[1] == 'w' || str[2] == 'o') && (str[0] == 't' || str[2] == 'o')){
                printf("2\n");
            }
            else{
                printf("1\n");
            }
        }
        else{
            printf("3\n");
        }
    }
    return 0;
}
