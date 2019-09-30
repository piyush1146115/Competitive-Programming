#include<stdio.h>
#include<string.h>
int main()
{
    long long int a, b, c, sum , acc = 0;
    char str[20];
    int test, d = 0;

    scanf("%d",&test);

    for(d = 1; d <= test;d++){
            gets(str);
            b = strlen(str);
            if(b == 0){
                d--;
                continue;
            }
        if(str[0] == 'd'){
            sum = 0;
            for(a = 7; a < b;a++){
                c = str[a] - '0';
                sum = sum*10 + c;
            }
            acc = acc + sum;
        }
        else{
            printf("%lld\n",acc);
        }
    }
    return 0;
}
