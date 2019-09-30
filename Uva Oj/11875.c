#include<stdio.h>
int main()
{
    int a, b[12],c,d,i,test;
    int j,k,l,m,sum,temp;
    scanf("%d",&test);
    for(d = 1; d <= test; d++)
    {
        scanf("%d",&a);
        //sum = 0;
        for(i = 0; i < a; i++)
        {
            scanf("%d",&b[i]);
            //sum = sum + b[i];
        }
        c = a/2;
        for(j = 0; j < a - 1; j++)
        {
            for(k = j+1; k < a; k++)
            {
                if(b[k] < b[j])
                {
                    temp = b[j];
                    b[j] = b[k];
                    b[k] = temp;
                }
            }
        }
        printf("Case %d: %d\n",d,b[c]);
    }
    return 0;
}
