#include<stdio.h>
#include<math.h>
int main()
{
    long long int a, b,root,div, i,max = 0,num,k;
    int test,c;
    scanf("%d", &test);

    for(c = 1 ;c <= test; c++){
    scanf("%lld %lld",&a, &b);
    {
        for(i = a; i <= b; i++)
        {
            root = sqrt(i);
            div = 0;
            if(i <= 10)
            {
                if(i == 1)
                {
                    max = 0;
                    num = 1;
                }
                else
                {
                    for(k = 1; k <= i/2; k++)
                    {
                        if(i % k == 0)
                            div++;
                    }
                }
            }
            else
            {
                for(k = 1; k <= root; k++)
                {
                    if(i % k == 0)
                        div++;
                }
            }


            if(div > max)
            {
                max = div;
                num = i;
            }
        }
        if(b <= 10  )
        {

                printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",a,b,num, max+1);
                max = 0;
        }
        else
        {
            printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",a, b,num, max*2);
            max = 0;
        }
    }
    }
    return 0;
}
