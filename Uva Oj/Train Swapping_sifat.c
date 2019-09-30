fatul
#include<stdio.h>
int main()
{
    int i,j,k,n,p,count;
    int a[100];
    scanf("%d",&k);
    for(p=1; p<=k; p++)
    {
        scanf("%d",&n);
        count=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",& a[i]);
        }

        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                if(a[i]>a[j])
                {
                    count++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",count);
    }
    return 0;
}
