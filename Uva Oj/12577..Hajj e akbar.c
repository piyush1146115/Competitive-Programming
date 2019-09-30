#include<stdio.h>
#include<string.h>
int main()
{
    char str[10];
    int a = 0, b;

    while(gets(str)){
            a++;
        if(str[0] == '*'){
            break;
        }
        if(strcmp(str, "Hajj") == 0){
            printf("Case %d: Hajj-e-Akbar\n",a);
        }
        else{
            printf("Case %d: Hajj-e-Asghar\n",a);
        }
    }
    return 0;
}
