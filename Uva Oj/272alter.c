#include<stdio.h>
#include<string.h>
int main()
{
    char str[100000];
    int i, j, k ,l;

    while(gets(str))
    {
        j=0;
        l = strlen(str);
        for(i = 0; i < l; i++)
        {
            if(str[i] =='"' )
            {
                if(j == 0)
                {
                    printf("``");
                    j = 1;
                }
                else
                {
                    printf("''");
                    j = 0;
                }
            }
            else
            {
                printf("%c",str[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
