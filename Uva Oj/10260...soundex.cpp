#include<bits/stdc++.h>
using namespace std;
int ara[100];
int main()
{
    ara['B'] = ara['V'] = ara['F'] = ara['P'] = 1;
    ara['C'] = ara['J'] = ara['G'] = ara['K'] = ara['Q'] = ara['S'] = ara['X'] = ara['Z'] = 2;
    ara['D'] = ara['T'] = 3;
    ara['L'] = 4;
    ara['M'] = ara['N'] = 5;
    ara['R'] = 6;

    char str[25];
    int i, j, len;

    while(gets(str))
    {
        len = strlen(str);
        for(i = 0; i < len; i++){
            if(ara[str[i]] > 0){
                printf("%d",ara[str[i]]);
              while(i < len - 1 && ara[str[i]] == ara[str[i + 1]])
                i++;
            }
        }
        printf("\n");
    }
    return 0;
}
