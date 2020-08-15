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
    int a, b, c, num, i, j, k, len, sum;

    while(gets(str)){
            //getchar();
            sum = 0;
        len = strlen(str);
        k = 0;
        for(i = 0; i <= len - 1; i++){

                switch(len){
            case 4:
                if(i == 0){
                    num = str[i] - '0';

                    while(num >= 1){
                     ///output[k++] = 'M';
                     sum += 4;
                        num--;
                    }
                }
                if(i == 1){
                    num = str[i] - 48;

                    if(num == 9){
                        ///output[k++] = 'C';
                        ///output[k++] = 'M';
                        sum += 6;
                    }
                    else if(num == 4){
                        //output[k++] = 'C';
                        //output[k++] = 'D';
                        sum += 5;
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            //output[k++] = 'C';
                            sum += 2;
                            num--;
                        }
                    }
                    else{
                        ///output[k++] = 'D';
                        sum += 3;
                        num = num - 5;
                        while(num >= 1){
                            ///output[k++] = 'C';
                            sum += 2;
                            num--;
                        }
                    }
                }
                if(i == 2){
                    num = str[i] - 48;

                    if(num == 9){
                        ///output[k++] = 'X';
                        ///output[k++] = 'C';
                        sum += 4;
                    }
                    else if(num == 4){
                        ///output[k++] = 'X';
                        ///output[k++] = 'L';
                        sum += 4;
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            ///output[k++] = 'X';
                            sum += 2;
                            num--;
                        }
                    }
                    else{
                        ///output[k++] = 'L';
                        sum += 2;
                        num = num - 5;
                        while(num >= 1){
                            ///output[k++] = 'X';
                            sum += 2;
                            num--;
                        }
                    }
                }
                if( i == 3){
                    num = str[i] - 48;

                    if(num == 9){
                        ///output[k++] = 'I';
                        ///output[k++] = 'X';
                        sum += 3;
                    }
                    else if(num == 4){
                        ///output[k++] = 'I';
                        ///output[k++] = 'V';
                        sum += 3;
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            ///output[k++] = 'I';
                            sum += 1;
                            num--;
                        }
                    }
                    else{
                        ///output[k++] = 'V';
                        sum += 2;
                        num = num - 5;
                        while(num >= 1){
                            ///output[k++] = 'I';
                            sum++;
                            num--;
                        }
                    }
                }
            break;

            case 3:
                 if(i == 0){
                    num = str[i] - 48;

                    if(num == 9){
                            sum += 6;
                        ///output[k++] = 'C';
                        ///output[k++] = 'M';
                    }
                    else if(num == 4){
                        ///output[k++] = 'C';
                        ///output[k++] = 'D';
                        sum += 5;
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            ///output[k++] = 'C';
                                sum += 2;
                                num--;
                        }
                    }
                    else{
                        ///output[k++] = 'D';
                        sum += 3;
                        num = num - 5;
                        while(num >= 1){
                            ///output[k++] = 'C';
                            sum += 2;
                            num--;
                        }
                    }
                }
                if(i == 1){
                    num = str[i] - 48;

                    if(num == 9){
                       ///output[k++] = 'X';
                        ///output[k++] = 'C';
                        sum += 4;
                    }
                    else if(num == 4){
                        ///output[k++] = 'X';
                        ///output[k++] = 'L';
                        sum += 4;
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            ///output[k++] = 'X';
                            sum += 2;
                            num--;
                        }
                    }
                    else{
                        ///output[k++] = 'L';
                        sum += 2;
                        num = num - 5;
                        while(num >= 1){
                            ///output[k++] = 'X';
                            sum += 2;
                            num--;
                        }
                    }
                }
                if( i == 2){
                    num = str[i] - 48;

                    if(num == 9){
                        ///output[k++] = 'I';
                        ///output[k++] = 'X';
                        sum += 3;
                    }
                    else if(num == 4){
                        ///output[k++] = 'I';
                        ///output[k++] = 'V';
                        sum += 3;
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            ///output[k++] = 'I';
                            sum++;
                            num--;
                        }
                    }
                    else{
                        ///output[k++] = 'V';
                        sum += 2;
                        num = num - 5;
                        while(num >= 1){
                            ///output[k++] = 'I';
                            sum++;
                            num--;
                        }
                    }
                }
                break;

            case 2:
                 if(i == 0){
                    num = str[i] - 48;

                    if(num == 9){
                        ///output[k++] = 'X';
                        ///output[k++] = 'C';
                        sum += 4;
                    }
                    else if(num == 4){
                      ///  output[k++] = 'X';
                        ///output[k++] = 'L';
                        sum += 4;
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            ///output[k++] = 'X';
                            sum += 2;
                            num--;
                        }
                    }
                    else{
                        ///output[k++] = 'L';
                        sum += 2;
                        num = num - 5;
                        while(num >= 1){
                            ///output[k++] = 'X';
                            sum += 2;
                            num--;
                        }
                    }
                }
                if( i == 1){
                    num = str[i] - 48;

                    if(num == 9){
                        //output[k++] = 'I';
                        //output[k++] = 'X';
                        sum += 3;
                    }
                    else if(num == 4){
                        //output[k++] = 'I';
                        //output[k++] = 'V';
                        sum += 3;
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            //output[k++] = 'I';
                            sum++;
                            num--;
                        }
                    }
                    else{
                        ///output[k++] = 'V';
                        sum += 2;
                        num = num - 5;
                        while(num >= 1){
                            ///output[k++] = 'I';
                            sum++;
                            num--;
                        }
                    }
                }
                break;
            case 1:
                   num = str[i] - 48;

                    if(num == 9){
                        ///output[k++] = 'I';
                        ///output[k++] = 'X';
                        sum += 3;
                    }
                    else if(num == 4){
                        ///output[k++] = 'I';
                        ///output[k++] = 'V';
                        sum += 3;
                    }
                    else if(num <= 3){
                        while(num >= 1){
                            ///output[k++] = 'I';
                            sum++;
                            num--;
                        }
                    }
                    else{
                        ///output[k++] = 'V';
                        sum += 2;
                        num = num - 5;
                        while(num >= 1){
                            ///output[k++] = 'I';
                            sum++;
                            num--;
                        }
                    }
                break;
            }
    }
    printf("%d\n",sum);

}
return 0;
}

