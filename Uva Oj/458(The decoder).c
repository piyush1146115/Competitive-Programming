#include<stdio.h>
#include<string.h>
int main()
{
    char str[1005];
    int a, b, i, j, k;

   while (gets(str)){

    a = strlen(str);

    for(i = 0; i < a; i++){
        printf("%c",str[i] - 7);
    }
    printf("\n");
   }
return 0;
}
