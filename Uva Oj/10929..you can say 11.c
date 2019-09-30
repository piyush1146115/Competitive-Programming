#include<stdio.h>
#include<string.h>
int main()
{
    int a, b,c, l, sum;
    char str[1005];

    while(gets(str)){
        sum = 0;
        c = 0;

    l = strlen(str);



    for(a = 0; a < l;a++){
        if(str[a] >= '0' && str[a] <= '9'){
                c = c + (str[a] - '0');
        if(a % 2 == 0){
            sum = sum + (str[a] - '0');
        }
        else{
            sum = sum - (str[a] - '0');
        }
        }

    }
    if(c == 0)
    {
        break;
    }
    if(sum % 11 == 0){
        printf("%s is a multiple of 11.\n",str);
    }
    else{
        printf("%s is not a multiple of 11.\n",str);
    }
    }
    return 0;
}

