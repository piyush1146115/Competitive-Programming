#include<stdio.h>
#include<string.h>
int main()
{
    int a, b, c, d, i, j, k, l, test, sum;
    char str[25];

    scanf("%d",&test);

    while(test--){
        gets(str);
        l = strlen(str);

        if(l == 0){
            test++;
            continue;
        }
        sum = 0;
        b = 0;
        for(a = 0; a < l; a++){
            if(str[a] == ' '){
                continue;
            }
            if(b == 0){
                c = str[a] - '0';
                c = c * 2;
                while(c >= 1){
                    d = c % 10;
                    c = c / 10;
                    sum = sum + d;
                }
                b = 1;
            }
            else{
                c = str[a] - '0';
                sum = sum + c;
                b = 0;
            }
        }
        if(sum % 10 == 0){
            printf("Valid\n");
        }
        else{
            printf("Invalid\n");
        }
    }
    return 0;
}
