#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

int main()
{
    char str[100];
    char output[100];
    int a, b, c, num, i, j, k, len;

    while(gets(str)){
            //getchar();
        len = strlen(str);
        k = 0;
        if(str[0] >= '0' && str[0] <= '9'){
        for(i = 0; i <= len - 1; i++){

                switch(len){
            case 4:
                if(i == 0){
                    num = str[i] - '0';

                    while(num >= 1){
                     output[k++] = 'M';
                        num--;
                    }
                }
                if(i == 1){
                    num = str[i] - 48;

                    if(num == 9){
                        output[k++] = 'C';
                        output[k++] = 'M';
                    }
                    else if(num == 4){
                        output[k++] = 'C';
                        output[k++] = 'D';
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            output[k++] = 'C';
                            num--;
                        }
                    }
                    else{
                        output[k++] = 'D';
                        num = num - 5;
                        while(num >= 1){
                            output[k++] = 'C';
                            num--;
                        }
                    }
                }
                if(i == 2){
                    num = str[i] - 48;

                    if(num == 9){
                        output[k++] = 'X';
                        output[k++] = 'C';
                    }
                    else if(num == 4){
                        output[k++] = 'X';
                        output[k++] = 'L';
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            output[k++] = 'X';
                            num--;
                        }
                    }
                    else{
                        output[k++] = 'L';
                        num = num - 5;
                        while(num >= 1){
                            output[k++] = 'X';
                            num--;
                        }
                    }
                }
                if( i == 3){
                    num = str[i] - 48;

                    if(num == 9){
                        output[k++] = 'I';
                        output[k++] = 'X';
                    }
                    else if(num == 4){
                        output[k++] = 'I';
                        output[k++] = 'V';
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            output[k++] = 'I';
                            num--;
                        }
                    }
                    else{
                        output[k++] = 'V';
                        num = num - 5;
                        while(num >= 1){
                            output[k++] = 'I';
                            num--;
                        }
                    }
                }
            break;

            case 3:
                 if(i == 0){
                    num = str[i] - 48;

                    if(num == 9){
                        output[k++] = 'C';
                        output[k++] = 'M';
                    }
                    else if(num == 4){
                        output[k++] = 'C';
                        output[k++] = 'D';
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            output[k++] = 'C';
                            num--;
                        }
                    }
                    else{
                        output[k++] = 'D';
                        num = num - 5;
                        while(num >= 1){
                            output[k++] = 'C';
                            num--;
                        }
                    }
                }
                if(i == 1){
                    num = str[i] - 48;

                    if(num == 9){
                        output[k++] = 'X';
                        output[k++] = 'C';
                    }
                    else if(num == 4){
                        output[k++] = 'X';
                        output[k++] = 'L';
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            output[k++] = 'X';
                            num--;
                        }
                    }
                    else{
                        output[k++] = 'L';
                        num = num - 5;
                        while(num >= 1){
                            output[k++] = 'X';
                            num--;
                        }
                    }
                }
                if( i == 2){
                    num = str[i] - 48;

                    if(num == 9){
                        output[k++] = 'I';
                        output[k++] = 'X';
                    }
                    else if(num == 4){
                        output[k++] = 'I';
                        output[k++] = 'V';
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            output[k++] = 'I';
                            num--;
                        }
                    }
                    else{
                        output[k++] = 'V';
                        num = num - 5;
                        while(num >= 1){
                            output[k++] = 'I';
                            num--;
                        }
                    }
                }
                break;

            case 2:
                 if(i == 0){
                    num = str[i] - 48;

                    if(num == 9){
                        output[k++] = 'X';
                        output[k++] = 'C';
                    }
                    else if(num == 4){
                        output[k++] = 'X';
                        output[k++] = 'L';
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            output[k++] = 'X';
                            num--;
                        }
                    }
                    else{
                        output[k++] = 'L';
                        num = num - 5;
                        while(num >= 1){
                            output[k++] = 'X';
                            num--;
                        }
                    }
                }
                if( i == 1){
                    num = str[i] - 48;

                    if(num == 9){
                        output[k++] = 'I';
                        output[k++] = 'X';
                    }
                    else if(num == 4){
                        output[k++] = 'I';
                        output[k++] = 'V';
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            output[k++] = 'I';
                            num--;
                        }
                    }
                    else{
                        output[k++] = 'V';
                        num = num - 5;
                        while(num >= 1){
                            output[k++] = 'I';
                            num--;
                        }
                    }
                }
                break;
            case 1:
                   num = str[i] - 48;

                    if(num == 9){
                        output[k++] = 'I';
                        output[k++] = 'X';
                    }
                    else if(num == 4){
                        output[k++] = 'I';
                        output[k++] = 'V';
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            output[k++] = 'I';
                            num--;
                        }
                    }
                    else{
                        output[k++] = 'V';
                        num = num - 5;
                        while(num >= 1){
                            output[k++] = 'I';
                            num--;
                        }
                    }
                break;
            }
    }
    output[k] = '\0';
    printf("%s\n",output);
    }
    else{
            num = 0;
        for(i = len - 1; i >= 0; i--){
            if(str[i] == 'I'){
                if(i < len - 1){
                if(str[i + 1] == 'V' || str[i + 1] == 'X'){
                    num = num -1;
                }
                else{
                    num++;
                }
                }
                else{
                    num++;
                }
            }

            else if(str[i] == 'V'){
                num += 5;
            }
            else if(str[i] == 'X'){
                if(i < len - 1){
                    if(str[i + 1] == 'C' || str[i + 1] == 'L'){
                        num -= 10;
                    }
                    else{
                        num += 10;
                    }
                }
                else{
                    num += 10;
                }
            }
            else if(str[i] == 'L'){
                num += 50;
            }
            else if(str[i] == 'C'){
                if(i < len - 1){
                    if(str[i + 1] == 'M' || str[i + 1] == 'D'){
                        num -= 100;
                    }
                    else{
                        num += 100;
                    }
                }
                else{
                    num += 100;
                }
            }
            else if(str[i] == 'D'){
                num += 500;
            }
            else if(str[i] == 'M'){
                num += 1000;
            }


        }
        printf("%d\n",num);
    }
}
return 0;
}

