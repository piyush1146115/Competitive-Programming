#include<stdio.h>
#include<string.h>
int main()
{
    char sen[5000], pal[5000];
    int index, a, b, c, l;

    while(gets(sen)){
        if(strcmp("DONE",sen) == 0){
            break;
        }
        l = strlen(sen);
        index = 0;

        for(a = 0; a < l;a++){
            if((sen[a] >= 'A' && sen[a] <= 'Z') || (sen[a] >= 'a' && sen[a] <= 'z')){
               if(sen[a] < 97){
                sen[a] = (sen[a] + 32);
               }
                pal[index] = sen[a];
                index++;
               }
        }

       // printf("%s\n",pal);

       for(b = 0,c = --index;b != c;b++,c--){
        if(pal[b] != pal[c]){
            break;
        }
       }
       if(b < c){
        printf("Uh oh..\n");
       }
       else{
        printf("You won't be eaten!\n");
       }
    }
    return 0;
}
