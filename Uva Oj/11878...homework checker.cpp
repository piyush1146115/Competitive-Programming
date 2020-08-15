#include<bits/stdc++.h>

using namespace std;

int main()
{
    char str[25];
    int i, j, count = 0, a, b, c, d, res;

    while(gets(str)){
        a = 0;
        i = 0;
        while(str[i] >= '0' && str[i] <= '9'){
            a = (str[i] - 48)+ a * 10 ;

            i++;
        }

        j = i;

        b = 0;
         i++;
         //printf("%d\n",a);
        while(str[i] >= '0' && str[i] <= '9'){
            b = (str[i] - 48) + (b * 10);
            i++;
           //  printf("%d\n",b);
        }
       // printf("%d\n",b);
        i++;
        res = 0;
        if(str[i] != '?'){
            while(str[i] >= '0' && str[i] <= '9'){
                res = (str[i] - 48) + res*10;
                i++;
            }
            if(str[j] == '+'){
                c = a + b;
            }
            else{
                c = a - b;
            }

            if(c == res){
                count++;
            }
        }
    }
    printf("%d\n",count);
}
