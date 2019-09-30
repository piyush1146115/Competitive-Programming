#include<stdio.h>
#include<string.h>
int main()
{
    char str[10000];
    int a, b, c, d,l,status,count;

    while(gets(str)){

    status = 0;
    count = 0;
    l = strlen(str);

    for(a = 0; a < l; a++){
        if((str[a] >= 'A' && str[a] <= 'Z') || (str[a] >= 'a' && str[a] <= 'z')){
            if(status == 0){
                count++;
                status = 1;
            }
        }
        else{
            status = 0;
        }
    }
    printf("%d\n", count);
    }
}
