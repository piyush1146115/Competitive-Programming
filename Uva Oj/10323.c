#include<stdio.h>
int main()
{
    unsigned long long int fact;
    int n, a;

    while(scanf("%d",&n) == 1)
    {
        if(n < 0 && n % 2 != 0)
        {
            printf("Overflow!\n");
        }
        else
        {
            fact = 1;
            for(a = 1; a <= n; a++)
            {
                fact = fact*a;
                if(fact > 6227020800)
                {
                    printf("Overflow!\n");
                    break;
                }
            }
            if(fact < 10000)
            {
                printf("Underflow!\n");
            }
            else if(fact >= 10000 && fact <= 6227020800)
            {
                printf("%llu\n",fact);
            }
        }
    }
    return 0;
}
/*
#include<stdio.h>
long long int fac(long long int num)
{
    if(num== 0)
        return 1;
    else
        return num*fac(num-1);
}
int main()
{
    long long int num,i;
    while(scanf("%lld",&num)!= EOF)
    {
	if(num < 0 && num % 2!= 0){
	printf("Overflow!\n");
	}
	else{
        if((num%2==0)&&(num<0))
        {
            num = num*(-1);
        }
         if(num<8)
        {
            printf("Underflow!\n");
        }
        else if(num>13)

            printf("Overflow!\n");
        else
        {
                    i = fac(num);
            printf("%lld\n",i);
        }
	}
    }
    return 0;
}
*/
