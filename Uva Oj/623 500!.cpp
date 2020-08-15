/*
Algorithm :
1. For finding out the factorial of N ( any natural number ) we have to multiply the
numbers from from 1 to N. That 1 x 2 x 3 x 4 x....x N.

2. As the number is very Big we have to multiply all the numbers before
 and including N and store the result in an array. For this we multiply all the number before and including N with
 the current multiplied result that is the result of all N-1 for current N.
 (one character at a time dividing by 10 and at last we have some remainder)

3. After that every time we have to put the remainder ( one character at a time )
into the array. (At this time the Array size will increase. )
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int a[3000];
    int n,i,j,temp,m,x;
    while(scanf("%d",&n)==1)
    {
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
      printf("%d!\n",n);
      for(i=m-1;i>=0;i--)
      printf("%d",a[i]);
      printf("\n");
    }
    return 0;
}
