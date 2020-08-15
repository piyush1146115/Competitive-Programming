#include<stdio.h>
int main()
{
    int a,b,c,d,e,f=0,g=0,h;
    scanf("%d",&e);
    for(a=1; a<=e; a++)
    {
        scanf("%d",&b);
        d=b;
s:
        h=d;
        f = 0;
        while(d!=0 )
        {
            c=d%10;
            d=d/10;
            f=f*10+c;
        }
        if(f!=h)
        {
            g++;
            d=b+f;
            goto s;
        }
        else
            printf("%d %d\n", g ,f);
    }
}
