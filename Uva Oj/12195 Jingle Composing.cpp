#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[500];
    int i, j, a, len, c;
    double sum;
//freopen("input.txt", "r", stdin);
   while(gets(str)){
        if(str[0] == '*')
        break;
        len = strlen(str);
        c = 0;
        for(i = 0; i < len; i++){
            if(str[i] == '/'){
                sum = 0;
                i++;
                int flag = 0;
                if(i < len){
                while(str[i] != '/'){
                        flag = 1;
                        if(str[i] == 'W')
                            sum += 1;
                        else if(str[i] == 'H')
                            sum += (1 / 2.0);
                         else if(str[i] == 'Q')
                            sum += (1 / 4.0);
                          else if(str[i] == 'E')
                            sum += (1/ 8.0);
                           else if(str[i] == 'S')
                            sum += (1 / 16.0);
                            else if(str[i] == 'T')
                                sum += (1/ 32.0);
                             else if(str[i] == 'X')
                                sum += (1/ 64.0);
                    i++;
                }
                }
                //cout << sum << endl;
                if(sum == 1)
                    c++;
                if(flag)
                    i--;
            }
        }
        cout << c << endl;
    }
    return 0;
}
