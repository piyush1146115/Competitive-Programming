#include<stdio.h>
#include<math.h>
int main()
{
    double tax, sum;
    int test, i;

    scanf("%d", &test);

    for(i = 1; i <= test; i++){

    scanf("%lf", &tax);
    sum = 0;
    if(tax <= 180000){
        tax = 0;
    }
    else{
        tax -= 180000;
    }
    if(tax <= 300000){
        sum += (tax * 0.1);
        tax = 0;
    }
    else{
        sum += 30000;
        tax -= 300000;
    }
    if(tax <= 400000){
        sum += (tax * 0.15);
        tax = 0;
    }
    else{
        sum += (400000 * 0.15);
        tax -= 400000;
    }
      if(tax <= 300000){
        sum += (tax * 0.2);
        tax = 0;
    }
    else{
        sum += 60000;
        tax -= 300000;
    }
    //printf("%lf\n",sum);
    if(tax > 0){
        sum += (tax * .25);
    }
    if(sum != (int)sum){
        sum -= (sum - (int)sum);
        sum++;
    }
    if(sum > 0 && sum < 2000)
        sum = 2000;

    printf("Case %d: %.0lf\n",i, sum);
   }
   return 0;
}
