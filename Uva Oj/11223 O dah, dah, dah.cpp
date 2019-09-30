#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int T,i,j,k,Index;
    char Inp[2005], tmp[10],Out[2005];
    //freopen("in.txt","r",stdin);

    scanf("%d\n",&T);

    for(i = 1; i <= T; i++)
    {
        gets(Inp);
        Index = k = 0;
        memset(tmp,'\0',sizeof(tmp));

        cout << "Message #" << i << endl;

        for(j = 0; Inp[j]; j++)
        {
            if(Inp[j] != ' ' )
                tmp[Index++] = Inp[j];

            if(Inp[j] == ' ' || Inp[j+1]=='\0')
            {
                if(strcmp(tmp,".-" ) == 0)Out[k++] = 'A';
                else if(strcmp(tmp,"-..." ) == 0)Out[k++] = 'B';
                else if(strcmp(tmp,"-.-." ) == 0)Out[k++] = 'C';
                else if(strcmp(tmp,"-.." ) == 0)Out[k++] = 'D';
                else if(strcmp(tmp,"." ) == 0)Out[k++] = 'E';
                else if(strcmp(tmp,"..-." ) == 0)Out[k++] = 'F';
                else if(strcmp(tmp,"--." ) == 0)Out[k++] = 'G';
                else if(strcmp(tmp,"...." ) == 0)Out[k++] = 'H';
                else if(strcmp(tmp,".." ) == 0)Out[k++] = 'I';
                else if(strcmp(tmp,".---" ) == 0)Out[k++] = 'J';
                else if(strcmp(tmp,"-.-" ) == 0)Out[k++] = 'K';
                else if(strcmp(tmp,".-.." ) == 0)Out[k++] = 'L';
                else if(strcmp(tmp,"--" ) == 0)Out[k++] = 'M';
                else if(strcmp(tmp,"-." ) == 0)Out[k++] = 'N';
                else if(strcmp(tmp,"---" ) == 0)Out[k++] = 'O';
                else if(strcmp(tmp,".--." ) == 0)Out[k++] = 'P';
                else if(strcmp(tmp,"--.-" ) == 0)Out[k++] = 'Q';
                else if(strcmp(tmp,".-." ) == 0)Out[k++] = 'R';
                else if(strcmp(tmp,"..." ) == 0)Out[k++] = 'S';
                else if(strcmp(tmp,"-" ) == 0)Out[k++] = 'T';
                else if(strcmp(tmp,"..-" ) == 0)Out[k++] = 'U';
                else if(strcmp(tmp,"...-" ) == 0)Out[k++] = 'V';
                else if(strcmp(tmp,".--" ) == 0)Out[k++] = 'W';
                else if(strcmp(tmp,"-..-" ) == 0)Out[k++] = 'X';
                else if(strcmp(tmp,"-.--" ) == 0)Out[k++] = 'Y';
                else if(strcmp(tmp,"--.." ) == 0)Out[k++] = 'Z';
                else if(strcmp(tmp,"-----" ) == 0)Out[k++] = '0';
                else if(strcmp(tmp,".----" ) == 0)Out[k++] = '1';
                else if(strcmp(tmp,"..---" ) == 0)Out[k++] = '2';
                else if(strcmp(tmp,"...--" ) == 0)Out[k++] = '3';
                else if(strcmp(tmp,"....-" ) == 0)Out[k++] = '4';
                else if(strcmp(tmp,"....." ) == 0)Out[k++] = '5';
                else if(strcmp(tmp,"-...." ) == 0)Out[k++] = '6';
                else if(strcmp(tmp,"--..." ) == 0)Out[k++] = '7';
                else if(strcmp(tmp,"---.." ) == 0)Out[k++] = '8';
                else if(strcmp(tmp,"----." ) == 0)Out[k++] = '9';
                else if(strcmp(tmp,".-.-.-" ) == 0)Out[k++] = '.';
                else if(strcmp(tmp,"--..--" ) == 0)Out[k++] = ',';
                else if(strcmp(tmp,"..--.." ) == 0)Out[k++] = '?';
                else if(strcmp(tmp,".----." ) == 0)Out[k++] = '\'';
                else if(strcmp(tmp,"-.-.--" ) == 0)Out[k++] = '!';
                else if(strcmp(tmp,"-..-." ) == 0)Out[k++] = '/';
                else if(strcmp(tmp,"-.--." ) == 0)Out[k++] = '(';
                else if(strcmp(tmp,"-.--.-" ) == 0)Out[k++] = ')';
                else if(strcmp(tmp,".-..." ) == 0)Out[k++] = '&';
                else if(strcmp(tmp,"---..." ) == 0)Out[k++] = ':';
                else if(strcmp(tmp,"-.-.-." ) == 0)Out[k++] = ';';
                else if(strcmp(tmp,"-...-" ) == 0)Out[k++] = '=';
                else if(strcmp(tmp,".-.-." ) == 0)Out[k++] = '+';
                else if(strcmp(tmp,"-....-" ) == 0)Out[k++] = '-';
                else if(strcmp(tmp,"..--.-" ) == 0)Out[k++] = '_';
                else if(strcmp(tmp,".-..-." ) == 0)Out[k++] = char(34);
                else if(strcmp(tmp,".--.-." ) == 0)Out[k++] = '@';

                if(Inp[j+1] == ' ' )
                {
                    Out[k++] = ' ';
                    j++;
                }
                memset(tmp,'\0',sizeof(tmp));
                Index = 0;
            }
        }
        Out[k] = '\0';
        printf("%s\n",Out);
        if(i != T)
            printf("\n");
    }
    return 0;
}
