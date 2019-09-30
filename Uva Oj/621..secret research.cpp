#include<stdio.h>
#include<string.h>
int main()
{
    int a, b, len, test;
    char str[1000];

    scanf("%d", &test);

    for(a = 1; a <= test; a++){
        scanf("%s", str);

        len = strlen(str);

        if(len <= 2){
            printf("+\n");
        }
        else if(str[len - 1] == '5' && str[len - 2] == '3'){
            printf("-\n");
        }
        else if(str[0] == '9' && str[len - 1] == '4'){
            printf("*\n");
        }
        else{
            printf("?\n");
        }
    }
    return 0;
}
