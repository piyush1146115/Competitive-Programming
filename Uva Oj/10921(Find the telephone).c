#include<stdio.h>
#include<string.h>
int main()
{
    char str[40],str2[40];
    int a, b, i, j;

    while(gets(str)){
        a = strlen(str);

        for(i = 0; i < a; i++){
            if(str[i] == 'A' || str[i] == 'B' || str[i] == 'C')
                str2[i] = '2';
            else if(str[i] == 'D' || str[i] == 'E' || str[i] == 'F')
                str2[i] = '3';
            else if(str[i] == 'G' || str[i] == 'H' || str[i] == 'I')
                str2[i] = '4';
            else if(str[i] == 'J' || str[i] == 'K' || str[i] == 'L')
                str2[i] = '5';
            else if(str[i] == 'M' || str[i] == 'N' || str[i] == 'O')
                str2[i] = '6';
            else if(str[i] == 'P' || str[i] == 'Q' || str[i] == 'R' || str[i] == 'S')
                str2[i] = '7';
            else if(str[i] == 'T' || str[i] == 'U' || str[i] == 'V')
                str2[i] = '8';
            else if(str[i] == 'W' || str[i] == 'X' || str[i] == 'Y' || str[i] == 'Z')
                str2[i] = '9';
            else
                str2[i] = str[i];
        }
        str2[i] = '\0';

        printf("%s\n",str2);
    }
return 0;
}
