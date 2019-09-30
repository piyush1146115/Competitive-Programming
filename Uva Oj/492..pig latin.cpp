/*#include<bits/stdc++.h>
using namespace std;

bool vowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'U' || c == 'O'){
        return true;
    }
    return false;
}
int main()
{
    char str[1000005], res[1000005];
    int l, i, j, k;


    while(gets(str)){
            k = 0;

        l = strlen(str);

      for(i = 0; i < l; i++){
         if(vowel(str[i])){
                if(i < l)
            while(str[i] != ' ' && i < l - 1)
            {
                res[k++] = str[i];
                i++;
            }
             if(i == l - 1 && str[i] != '.'){
                res[k++] = str[i];
                i++;
             }
             res[k++] = 'a';
            res[k++] = 'y';
            if(i == l - 1)
                res[k++] = str[i];


            if(str[i] == ' ')
                res[k++] = ' ';

         }
            else if(!vowel(str[i])){
                j = i;
                i++;
                if(i < l - 1)
                while(str[i] != ' ' && i < l - 1){
                    res[k++] = str[i];
                    i++;
                }
                 res[k++] = str[j];
             if(i == l - 1 && str[i] != '.'){
                res[k++] = str[i];
                i++;
             }
                res[k++] = 'a';
                res[k++] = 'y';
                 if(i == l - 1)
                    res[k++] = str[i];

                if(str[i] == ' ')
                    res[k++] = ' ';
            }
      }
      res[k] = '\0';
    printf("%s\n", res);
    }
    return 0;
}
*/

#include<stdio.h>
int main()
{
    int a,b,c,d,flag;
    char g,v;
    while((g=getchar())!=EOF)
    {
        if((g<'a'||g>'z') &&(g<'A'||g>'Z'))
            printf("%c",g);
        else if(g=='a'||g=='A'||g=='e'||g=='E'||g=='i'||g=='I'||g=='o'||g=='O'||g=='u'||g=='U')
        {
            printf("%c",g);
            while((g=getchar())&&(g>='a'&&g<='z')||(g>='A'&&g<='Z'))
                printf("%c",g);
            printf("ay%c",g);
        }
        else if((g>='a'&&g<='z')||(g>='A'&&g<='Z'))
        {
            v=g;
            while((g=getchar())&&(g>='a'&&g<='z')||(g>='A'&&g<='Z'))
                printf("%c",g);
            printf("%cay%c",v,g);
        }
    }
    return 0;
}

