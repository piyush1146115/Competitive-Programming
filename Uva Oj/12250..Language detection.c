#include<stdio.h>
#include<string.h>
int main()
{
    int i = 0,a, b= 0 ,l,count;
    char str[20];

    while(gets(str)){
    i++;
    l = strlen(str);
    count = 0;
    for(a = 0; a < l; a++){
        if(str[a] != ' '){
            count += str[a];
        }
    }
    if(count == '#'){
        break;
    }
    if(strcmp(str,"HELLO") == 0){
        printf("Case %d: ENGLISH\n",i);
    }
    else if(strcmp(str,"HOLA") == 0){
        printf("Case %d: SPANISH\n",i);
    }
    else if(strcmp(str,"HALLO") == 0){
        printf("Case %d: GERMAN\n",i);
    }
    else if(strcmp(str, "BONJOUR") == 0)
        printf("Case %d: FRENCH\n",i);

     else if(strcmp(str ,"CIAO" ) == 0){
        printf("Case %d: ITALIAN\n",i);
    }
    else if(strcmp(str,"ZDRAVSTVUJTE") == 0){
        printf("Case %d: RUSSIAN\n",i);
    }
    else{printf("Case %d: UNKNOWN\n",i);}
    }
    return 0;
}
