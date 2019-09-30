#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
int ara[2000] = {0};
bool prime(int n)
{
    int a, b, c, d;
    a = sqrt(n);

    for(b = 2; b <= a;b++){
        if(ara[b] == 0){
            for(c = b*b;c <= n;c+= b){
                ara[c] = 1;
            }
        }
    }
    if(ara[n] == 0){
        return true;
    }
    else
        return false;
    }

int main()
{
    char str[50];
    int a, b, c, d, l, sum;

    while(gets(str)){
        sum = 0;
        l = strlen(str);
        for(a = 0; a < l; a++){
            if(str[a] >= 'a' && str[a] <= 'z'){
                sum += str[a] - 'a' + 1;
            }
            else  if(str[a] >= 'A' && str[a] <= 'Z'){
                sum += str[a] - 'A' + 27;
            }
        }

        if(prime(sum)){
            printf("It is a prime word.\n");
        }
        else{
            printf("It is not a prime word.\n");
        }

    }
    return 0;
}
