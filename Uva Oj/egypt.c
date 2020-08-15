#include <stdio.h>
#include<math.h>
int main()
{
    long int a,b,c,s;
    while(scanf("%ld %ld %ld",&a,&b,&c)!=EOF)
    {
        if(a==0 && b==0 && c==0)
        {
            break;
        }
        s=sqrt(a*a+b*b);
        if(s==c)
            printf("right\n");
        else
            printf("wrong\n");
    }
}
