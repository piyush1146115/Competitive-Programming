#include<stdio.h>
#include<string.h>
int main()
{
    char a[20];
    int i,j,k,l,m,n;
    while(gets(a))
    {
        l=strlen(a);
        for(n=1; n<=l; n++)
        {
            for(i=0; i<l; i++)
            {
                m=0;
                for(j=i; j<=i+n-1; j++)
                {
                    printf("%c", a[j]);
                    if(j==l-1)
                    {
                        m++;
                        break;
                    }
                }
                if(m>0) break;
                printf(", ");
            }
            if(n==l) break;
            printf(", ");
        }
        printf("\n");
    }
    return 0;
}
