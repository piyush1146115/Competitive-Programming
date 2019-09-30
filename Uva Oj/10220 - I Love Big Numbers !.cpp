#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int a[3000];
    int n,i,j,temp,m,x, sum;
    while(scanf("%d",&n)==1)
    {
        sum = 0;
       a[0]=1;
       m=1;

       temp = 0;
       for(i=1;i<=n;i++)
       {
            for(j=0;j<m;j++)
            {
               x = a[j]*i+temp;
               a[j]=x%10;
               temp = x/10;
            }
             while(temp>0)
             {
               a[m]=temp%10;
               temp = temp/10;
               m++;
             }
      }

      for(i=m-1;i>=0;i--)
            sum += a[i];

            printf("%d\n",sum);
    }
    return 0;
}
