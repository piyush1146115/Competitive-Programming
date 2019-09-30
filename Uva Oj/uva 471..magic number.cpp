#include <stdio.h>
#include <string.h>
#define N 9876543210
char verify(unsigned long long int n)
{
    int mark = 0,t;
    while(n>0)
    {
        t = n%10;
        n/=10;
        if(mark&(1<<t))
            return 0;
        mark|=1<<t;
    }
    return 1;
}
int main()
{
    unsigned long long int i,j,max;
    int c;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%llu",&j);
        max = N/j;
        for(i=1;i<=max;i++)
            if(verify(i)&&verify(j*i))
                printf("%llu / %llu = %llu\n",j*i,i,j);
        if(c)
            putchar('\n');
    }
    return 0;
}
