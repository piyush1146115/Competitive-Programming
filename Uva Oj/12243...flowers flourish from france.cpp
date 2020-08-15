#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[10000];
    int i, j, k, len, flag, n,  sp, count ;
    char match[5];

    while(gets(str)){
        k = 0;
        count = 0;

    if(strcmp(str,"*") == 0){
        break;
    }

        len = strlen(str);

        flag = 0;
       match[0] = str[0];

       if(match[0] >= 'a' && match[0] <= 'z'){
        match[0] = match[0] - 32;
       }

        for(i = 1; i < len; i++){
            if(str[i] == ' '){
                flag = 1;
                k++;
            }
           else if(flag == 1){
                flag = 0;

                if(str[i] >= 'a' && str[i] <= 'z'){
                str[i] = str[i] - 32;
                }
                if(str[i] == match[0]){
                    count++;
                    continue;
                }
                else{
                    break;
                }
            }
        }

        if(count == k){
            printf("Y\n");
        }
        else{
            printf("N\n");
        }
    }
    return 0;
}
