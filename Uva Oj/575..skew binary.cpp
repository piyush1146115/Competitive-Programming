#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char str[40];
    long int a, b, c, d, e, f;
    long long int sum;

    while(gets(str)){
        if(str[0] == '0'){
            break;
        }
        d = strlen(str);
        sum = 0;
        e = 1;
        for(a = d - 1; a >= 0; a--){
            c = str[a] - '0';
            b = pow(2,e) - 1;
            e++;
            f = c * b;
            sum += f;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
