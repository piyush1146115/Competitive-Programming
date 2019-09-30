#include<stdio.h>
#include<string.h>
int main()
{
    int a, b,i,k,m[500];
    char str[1000];
    while(gets(str)){
    k = 0;
    b= strlen(str);

    for( a = 0; a < b; a++)
    {
        if(a == b - 1)
        {
            a++;
        }
        if(str[a] == ' ' || a==b)
        {
            m[0] = 0;
            for(i = a - 1; i >= m[k]; i--)
            {
                printf("%c",str[i]);
            }

            if(a != b)
                printf(" ");
            k = k + 1;
            m[k] = a + 1;
        }
    }
    printf("\n");
    }
    return 0;

}
