#include<stdio.h>
#include<string.h>
int match_letter(char a,char letter[50])
{
    int i, count = 0;
    for( i = 0; i < 50; i++ ){
            ++count;
        if( a == letter[i]){
            break;
        }
        else{
            continue;
        }
    }
    return count - 3;
}
int main()
{
    int a, lenth, b;
    char input[1000];
    char output[1000];

    gets(input);

char letter[50] = { '`','1', '2','3','4','5', '6', '7', '8', '9', '0','-', '=', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']','\\','a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';','\'' , 'z','x','c', 'v', 'b', 'n','m', ',','.','/','\0'};


    lenth = strlen(input);

    for( a = 0; a < lenth; a++){

        if(input[a] >= 'A' && input[a] <= 'Z')
            input[a] = input[a] + 32;

        if(input[a] == ' ' || input[a] == 'a' || input[a] == '`' || input[a] == 'q' || input[a] == 'z')
            output[a] = input[a];
        else{
            b = match_letter(input[a], letter);
            output[a] = letter[b];
        }
    }
    output[a] = '\0';
    printf("%s\n", output);


    return 0;
}
