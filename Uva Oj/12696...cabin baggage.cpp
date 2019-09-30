#include<stdio.h>
int main()
{
    int test, count = 0;
    float l, wid, dep, wei, sum;

    scanf("%d",&test);

  while(test--)
  {
      scanf("%f %f %f %f",&l, &wid, &dep, &wei);
      sum = l + wid + dep;
     if(wei > 7){
        printf("0\n");
      }
    else if(l <= 56 && wid <= 45 && dep <= 25){
        printf("1\n");
        count++;
    }
     else if(sum > 125){
        printf("0\n");
      }
      else{
        printf("1\n");
        count++;
      }
  }
  printf("%d\n",count);

    return 0;
}
