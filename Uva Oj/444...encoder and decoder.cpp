#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "wt", stdout);
    char input[500], output[500];
    int i, j, len;

    while(gets(input)){
        len = strlen(input);

        for(i = 0; i < len / 2; i++){
            swap(input[i], input[len - i - 1]);
        }
        int k = 0;
        if(input[0] >= '0' && input[0] <= '9'){

            for(i = 0; i < len; i++){
                int num = (input[i + 1] - 48) + (input[i] - 48) * 10;

                if(num <= 30){
                    num = (input[i + 2] - 48) + (input[i + 1] - 48) * 10 + (input[i] - 48) * 100;
                    i++;
                }
                i++;
                output[k++] = num;
            }
        output[k] = '\0';

        }
        else{
            for(i = 0; i < len; i++){
                int num = input[i];

                while(num != 0){
                    j = num % 10;
                    output[k++] = j + 48;
                    num /= 10;
                }
            }
            output[k] = '\0';
        }
        printf("%s\n",output);
    }
    return 0;
}
